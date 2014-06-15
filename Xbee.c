
 /*
 * File:   Xbee.c
 * Author: Radjy RAMLALL
 * Project: Phyleas Dev
 * Created on 19 mars 2014, 12:34
 */

#include "Xbee.h"
#include "ConfigProcessor.h"
#include <plib.h>
#include "LCD.h"


volatile static char toto=0;


void Init_Xbee(void)
{

    UARTConfigure(UART_MODULE_ID, UART_ENABLE_PINS_TX_RX_ONLY);
    UARTSetFifoMode(UART_MODULE_ID, UART_INTERRUPT_ON_TX_NOT_FULL | UART_INTERRUPT_ON_RX_NOT_EMPTY);
    UARTSetLineControl(UART_MODULE_ID, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
    UARTSetDataRate(UART_MODULE_ID, GetPeripheralClock(), DESIRED_BAUDRATE_XBEE);
    UARTEnable(UART_MODULE_ID, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));

    // Configure UART RX Interrupt
    INTEnable(INT_SOURCE_UART_RX(UART_MODULE_ID), INT_ENABLED);
    INTSetVectorPriority(INT_VECTOR_UART(UART_MODULE_ID), INT_PRIORITY_LEVEL_2);
    INTSetVectorSubPriority(INT_VECTOR_UART(UART_MODULE_ID), INT_SUB_PRIORITY_LEVEL_1);

    // Enable multi-vector interrupts
    
    //WriteStringXbee("*** UART Xbee2 Initialized ***\r\n");
    
}



void WriteStringXbee(const char *string)
{
    while(*string != '\0')
    {
        while(!UARTTransmitterIsReady(UART_MODULE_ID));

        UARTSendDataByte(UART_MODULE_ID, *string);

        string++;

        while(!UARTTransmissionHasCompleted(UART_MODULE_ID));
    }
}

void WriteStringXbee2(const char *string)
{
    int i=0;
    while(i<17)
    {
        while(!UARTTransmitterIsReady(UART_MODULE_ID));

        UARTSendDataByte(UART_MODULE_ID, *string);

        string++;
        
        i++;
        
        while(!UARTTransmissionHasCompleted(UART_MODULE_ID));
    }
}


void PutCharacterXbee(const char character)
{
        while(!UARTTransmitterIsReady(UART_MODULE_ID));

        UARTSendDataByte(UART_MODULE_ID, character);

        while(!UARTTransmissionHasCompleted(UART_MODULE_ID));
        DelayMs(100);
}

void ProgMode(void)
{
    
    PutCharacterBluetooth('$');
    DelayMs(10);
    PutCharacterBluetooth('$');
    DelayMs(10);
    PutCharacterBluetooth('$');
    DelayMs(10);
}

void Reset_BT(void)
{
    mPORTBClearBits(BIT_9); // active reset
    DelayMs(1000);
    mPORTBSetBits(BIT_9); //  reset
    DelayMs(1);
}

void __ISR(_UART_1_VECTOR, ipl2) IntUart1Handler(void)
{
	// Is this an RX interrupt?
	if(INTGetFlag(INT_SOURCE_UART_RX(UART_MODULE_ID)))
	{
            // Clear the RX interrupt Flag
            while (UARTReceivedDataIsAvailable (UART_MODULE_ID))
            {// none zero if UART has received data
                toto = UARTGetDataByte(UART_MODULE_ID);
            }
                //PutCharacterXbee(toto);

            #ifdef DEBUG
                if(toto=='p')
                {
                    ProgMode();
                    WriteStringXbee("Prog.mode\n");
                }
                else if (toto=='d')
                {
                    WriteStringXbee("Inforequest\n");
                    PutCharacterBluetooth('D');
                    PutCharacterBluetooth(0x0D);
                }
                else if (toto=='c')
                {
                    Reset_BT();
                    WriteStringXbee("Reset\n");
                }
            #endif

	    INTClearFlag(INT_SOURCE_UART_RX(UART_MODULE_ID));

            // Echo what we just received.
            
            DBPRINTF("%c",UARTGetDataByte(UART_MODULE_ID));

	}

	// We don't care about TX interrupt
	if (INTGetFlag(INT_SOURCE_UART_TX(UART_MODULE_ID)))
	{
            INTClearFlag(INT_SOURCE_UART_TX(UART_MODULE_ID));
	}
}