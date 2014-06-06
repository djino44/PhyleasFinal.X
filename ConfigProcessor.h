/* 
 * File:   ConfigProcessor.h
 * Author: WindSignal
 *
 * Created on 20 mars 2014, 09:45
 */

#ifndef CONFIGPROCESSOR_H
#define	CONFIGPROCESSOR_H

#ifdef	__cplusplus
extern "C" {
#endif


   /*Processor Frequency*/
#define SYS_FREQ (80000000L)
   /*Instruction to set peripheral internal Clock*/
#define	GetPeripheralClock()		(SYS_FREQ/(1 << OSCCONbits.PBDIV))
#define	GetInstructionClock()		(SYS_FREQ)


#ifdef	__cplusplus
}
#endif

#endif	/* CONFIGPROCESSOR_H */

