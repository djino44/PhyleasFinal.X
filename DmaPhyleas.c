
#include "DmaPhyleas.h"
#include <stdlib.h>
#include <time.h>
#include <plib.h>
#include "../include/peripheral/dma.h"
#include "Decoder.h"


int DmaIntFlag;
extern char dmaBuff[16+1];
DmaChannel	chn=DMA_CHANNEL1;

void Init_Dma(void)
{
    // configure the channel
	DmaChnOpen(chn, DMA_CHN_PRI2, DMA_OPEN_MATCH);

	DmaChnSetMatchPattern(chn, '\r');	// set \r as ending character

	// set the events: we want the UART2 rx interrupt to start our transfer
	// also we want to enable the pattern match: transfer stops upon detection of CR
	DmaChnSetEventControl(chn, DMA_EV_START_IRQ_EN|DMA_EV_MATCH_EN|DMA_EV_START_IRQ(_UART1_RX_IRQ));

	// set the transfer source and dest addresses, source and dest sizes and the cell size
	DmaChnSetTxfer(chn, (void*)&U1RXREG, dmaBuff, 1, 16, 1);

	DmaChnSetEvEnableFlags(chn, DMA_EV_BLOCK_DONE);		// enable the transfer done interrupt: pattern match or all the characters transferred


	INTSetVectorPriority(INT_VECTOR_DMA(chn), INT_PRIORITY_LEVEL_5);		// set INT controller priority
	INTSetVectorSubPriority(INT_VECTOR_DMA(chn), INT_SUB_PRIORITY_LEVEL_3);		// set INT controller sub-priority

	INTEnable(INT_SOURCE_DMA(chn), INT_ENABLED);		// enable the chn interrupt in the INT controller

	DmaIntFlag=0;				// clear the interrupt flag

	// enable the chn
	DmaChnEnable(chn);

	//while(!DmaIntFlag);

}



// handler for the DMA channel 1 interrupt
void __ISR(_DMA1_VECTOR, IPL5SOFT) DmaHandler1(void)
{
	int evFlags;				// event flags when getting the interrupt

	INTClearFlag(INT_SOURCE_DMA(DMA_CHANNEL1));	// release the interrupt in the INT controller, we're servicing int

	evFlags=DmaChnGetEvFlags(DMA_CHANNEL1);	// get the event flags

    if(evFlags&DMA_EV_BLOCK_DONE)
    { // just a sanity check. we enabled just the DMA_EV_BLOCK_DONE transfer done interrupt
	DmaIntFlag=1;
	DmaChnClrEvFlags(DMA_CHANNEL1, DMA_EV_BLOCK_DONE);
        Decoder(dmaBuff);
        DmaChnEnable(chn);
    }
}
