
#include "DmaPhyleas.h"
#include <stdlib.h>
#include <time.h>
#include <plib.h>
#include "../include/peripheral/dma.h"


int DmaIntFlag;


void Init_Dma(void)
{

}

/*********************************************************************
 * Function:        void DmaDoUartEchoExample(int pbClk)
 *
 * PreCondition:    None
 *
 * Input:			pbClk	- the PB frequency
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:		Examples for receiving some data from the UART and echoing it back using the DMA Peripheral Lib.
 * 					The received data is expected to end with a CR and has to be less than DmaGetMaxTxferSize() bytes in length.
 * 					We'll enable the DMA interrupts to signal us when the transfer is done.
 *
 * Note:            None.
 ********************************************************************/
void DmaDoUartEchoExample(int pbClk)
{
	char 		dmaBuff[256+1];		// we'll store the received data here
	DmaChannel	chn=DMA_CHANNEL1;	// DMA channel to use for our example
						// NOTE: the ISR setting has to match the channel number

	

	// configure the channel
	DmaChnOpen(chn, DMA_CHN_PRI2, DMA_OPEN_MATCH);

	DmaChnSetMatchPattern(chn, '\r');	// set \r as ending character

	// set the events: we want the UART2 rx interrupt to start our transfer
	// also we want to enable the pattern match: transfer stops upon detection of CR
	DmaChnSetEventControl(chn, DMA_EV_START_IRQ_EN|DMA_EV_MATCH_EN|DMA_EV_START_IRQ(_UART2_RX_IRQ));

	// set the transfer source and dest addresses, source and dest sizes and the cell size
	DmaChnSetTxfer(chn, (void*)&U2RXREG, dmaBuff, 1, 256, 1);

	DmaChnSetEvEnableFlags(chn, DMA_EV_BLOCK_DONE);		// enable the transfer done interrupt: pattern match or all the characters transferred

	// enable system wide multi vectored interrupts
	INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
	INTEnableInterrupts();

	INTSetVectorPriority(INT_VECTOR_DMA(chn), INT_PRIORITY_LEVEL_5);		// set INT controller priority
	INTSetVectorSubPriority(INT_VECTOR_DMA(chn), INT_SUB_PRIORITY_LEVEL_3);		// set INT controller sub-priority

	INTEnable(INT_SOURCE_DMA(chn), INT_ENABLED);		// enable the chn interrupt in the INT controller

	DmaIntFlag=0;				// clear the interrupt flag

	// enable the chn
	DmaChnEnable(chn);

	// let the user know that he has to enter a string
	// for example, you could do something like:
	// printf("\r\nType a string less than 256 characters followed by Enter key...Will echo it using the DMA\r\n\r\n");

	// wait for the data to come in
	while(!DmaIntFlag);			// just block here. In a real application you can do some other stuff while the DMA transfer is taking place

	// ok, we've received the data in the buffer
	putsUART2("\r\nReceived the character string. Now echoing it back...\r\n\r\n");

	// now the TX part
	// reconfigure the channel
	DmaChnOpen(chn, DMA_CHN_PRI2, DMA_OPEN_MATCH);

	// set the events: now the start event is the UART tx being empty
	// we maintain the pattern match mode
	DmaChnSetEventControl(chn, DMA_EV_START_IRQ_EN|DMA_EV_MATCH_EN|DMA_EV_START_IRQ(_UART2_TX_IRQ));

	// set the transfer source and dest addresses, source and dest size and cell size
	DmaChnSetTxfer(chn, dmaBuff, (void*)&U2TXREG, 256, 1, 1);

	DmaChnSetEvEnableFlags(chn, DMA_EV_BLOCK_DONE);		// enable the transfer done interrupt: pattern match or all the characters transferred

	INTEnable(INT_SOURCE_DMA(chn), INT_ENABLED);		// enable the chn interrupt in the INT controller

	DmaIntFlag=0;		// clear the interrupt flag

	DmaChnStartTxfer(chn, DMA_WAIT_NOT, 0);	// force the DMA transfer: the UART2 tx flag it's already been active

	// wait for data to be output
	while(!DmaIntFlag);			// just block here

	// DMA Echo is complete

	INTEnable(INT_SOURCE_DMA(chn), INT_DISABLED);		// disable further interrupts from the DMA controller

	putsUART2("\r\nEcho back completed...\r\n\r\n");


}

// handler for the DMA channel 1 interrupt
void __ISR(_DMA1_VECTOR, IPL5SOFT) DmaHandler1(void)
{
	int	evFlags;				// event flags when getting the interrupt

	INTClearFlag(INT_SOURCE_DMA(DMA_CHANNEL1));	// release the interrupt in the INT controller, we're servicing int

	evFlags=DmaChnGetEvFlags(DMA_CHANNEL1);	// get the event flags

    if(evFlags&DMA_EV_BLOCK_DONE)
    { // just a sanity check. we enabled just the DMA_EV_BLOCK_DONE transfer done interrupt
	DmaIntFlag=1;
	DmaChnClrEvFlags(DMA_CHANNEL1, DMA_EV_BLOCK_DONE);
    }
}
