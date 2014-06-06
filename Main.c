
/*
 * File:   Main.h
 * Author: Radjy RAMLALL
 * Project: Phyleas Dev
 * Created on 19 mars 2014, 12:34
 */

#include <plib.h>
#include "ConfigProcessor.h"
#include "Bluetooth.h"
#include <GenericTypeDefs.h>
#include "Explore.h"


/*Fuses Config*/

#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_1, FWDTEN = OFF
#pragma config POSCMOD = HS, FNOSC = PRIPLL, FPBDIV = DIV_1

BYTE CAN1MessageFifoArea[2 * 8 * 16];
BYTE CAN2MessageFifoArea[2 * 8 * 16];


// some definitions
#define    DMA_CH1_VECTOR    38
#define    U2RX_IRQ_NO        41
#define    U2TX_IRQ_NO        42
int        DmaIntFlag;            // flag used in interrupts



// some definitions
#define    DMA_CH1_VECTOR    38
#define    U2RX_IRQ_NO        41
#define    U2TX_IRQ_NO        42
int        DmaIntFlag;            // flag used in interrupts



void delay_for_1000_nops_x (int n)
{
    while (n --)
    {
        int i;

        for (i = 0; i < 1000; i++)
            asm volatile ("nop");
    }
}

void Init_DMA(void)
{
    char             dmaBuff[256+1];        // we'll store the received data here
    int                chn=1;                // DMA channel to use for our example
                                        // NOTE: the ISR setting has to match the channel number
    DmaTxferRes        res;


    //DmaChnConfigure(chn, DMA_CHN_PRI2, DMA_CFG_NORM|DMA_CFG_MATCH);
    DmaChnConfigure(chn, DMA_CHN_PRI2, DMA_CONFIG_AUTO|DMA_CONFIG_MATCH|DMA_CONFIG_ENABLE);
    DmaChnSetMatchPattern(chn, '\r');    // set \r as ending character

    // set the events: we want the UART2 rx interrupt to start our transfer
    // also we want to enable the pattern match: transfer stops upon detection of CR
    DmaChnSetEventControl(chn, DMA_EV_START_IRQ_EN|DMA_EV_MATCH_EN|DMA_EV_START_IRQ(U2RX_IRQ_NO));

    // set the transfer source and dest addresses, source and dest sizes and the cell size
    DmaChnSetTxfer(chn, (void*)&U2RXREG, &BtBuff, 1, 256, 1);

    DmaChnSetEvEnableFlags(chn, DMA_EV_BLOCK_DONE);        // enable the transfer done interrupt: pattern match or all the characters transferred

    INTEnableSystemMultiVectoredInt();                            // enable system wide multi vectored interrupts

    DmaChnSetIntPriority(chn, INT_PRIORITY_LEVEL_5, INT_SUB_PRIORITY_LEVEL_3);        // set INT controller priorities

    DmaChnIntEnable(chn);        // enable the chn interrupt in the INT controller

    DmaIntFlag=0;                // clear the interrupt flag

    // enable the chn
    DmaChnEnable(chn);

    // let the user know that he has to enter a string
    // for example, you could do something like:
    // printf("\r\nType a string less than 256 characters followed by Enter key...Will echo it using the DMA\r\n\r\n");

    // wait for the data to come in
    //while(!DmaIntFlag);            // just block here. In a real application you can do some other stuff while the DMA transfer is taking place

    // ok, we've received the data in the buffer
    //putsUART2("\r\nReceived the character string. Now echoing it back...\r\n\r\n");

    // now the TX part
    // reconfigure the channel
    DmaChnConfigure(chn, DMA_CHN_PRI2, DMA_CONFIG_AUTO|DMA_CONFIG_MATCH|DMA_CONFIG_ENABLE);

    // set the events: now the start event is the UART tx being empty
    // we maintain the pattern match mode
    DmaChnSetEventControl(chn, DMA_EV_START_IRQ_EN|DMA_EV_MATCH_EN|DMA_EV_START_IRQ(U2TX_IRQ_NO));

    // set the transfer source and dest addresses, source and dest size and cell size
    DmaChnSetTxfer(chn, dmaBuff, (void*)&U1TXREG, 256, 1, 1);


    DmaIntFlag=0;        // clear the interrupt flag



    // set the transfer source and dest addresses, source and dest size and cell size
    DmaChnSetTxfer(chn, dmaBuff, (void*)&U1TXREG, 256, 1, 1);


    DmaIntFlag=0;        // clear the interrupt flag


    // enable the channel
    DmaChnEnable(chn);

    DmaChnStartTxfer(chn, DMA_WAIT_NOT, 0);    // force the DMA transfer: the UART2 tx flag it's already been active

    // wait for data to be output
    //while(!DmaIntFlag);            // just block here

    // DMA Echo is complete

    //DmaChnIntDisable(chn);        // disable further interrupts from the DMA controller

   


}

/*
void __attribute__ ((interrupt(ipl5), vector(DMA_CH1_VECTOR))) DmaHandler1(void)
{
    int    evFlags;                // event flags when getting the interrupt

    mDmaChnClrIntFlag(1);        // release the interrupt in the INT controller, we're servicing int

    evFlags=DmaChnGetEvFlags(1);    // get the event flags

    if(evFlags&DMA_EV_BLOCK_DONE)
    { // just a sanity check. we enabled just the DMA_EV_BLOCK_DONE transfer done interrupt
        DmaIntFlag=1;
         DmaChnClrEvFlags(1, DMA_EV_BLOCK_DONE);
    }
}

*/
int main (void)
{
    DBINIT();
    DBPRINTF("Hello from PIC32 \n");

    
    DDPCONbits.JTAGEN = 0;
    SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    
    initEX16();
    Init_Xbee();
    CAN1Init();


    //initLCD();
    //putsLCD("RRC");


    DelayMs(1500);

    

    InitBluetooth();

    mPORTDSetPinsDigitalOut(BIT_0);
    mPORTDSetBits(BIT_0);

    mPORTDSetPinsDigitalOut(BIT_1);
    mPORTDClearBits(BIT_1);


    //Init_DMA();


    //Init_DMA();

    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
    INTEnableInterrupts();

    
    while(1)
    {
        mPORTDToggleBits(BIT_0);

        DelayMs(1000);

       /* if((I_Write>I_Read)||(I_Write>I_Read))
        {
            PutCharacterXbee(BtBuff[I_Read]);
            if(I_Read==2999)
            {
                I_Read=0;
            }
            else
            {
                I_Read++;
            }

        }
       */
        PutCharacterBluetooth('D');
        DelayMs(10);

    }
    return -1;
}