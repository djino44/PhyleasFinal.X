/* 
 * File:   Decoder.h
 * Author: travail
 *
 * Created on 3 juin 2014, 11:38
 */

#ifndef DECODER_H
#define	DECODER_H

#include "GenericTypeDefs.h"


#ifdef	__cplusplus
extern "C" {
#endif

char dmaBuff[16+1];
    
void Decoder(char *buf);
UINT16 Get_SID(void);
UINT32 Get_EID(char *Mytab);
int Get_RTR(char *Mytab);
int Get_IDE(char *Mytab);
CAN_MODULE Get_CAN_Module(char *Mytab);
unsigned char Get_PAYLOAD(char *Mytab,int PayloadNumber);

#ifdef	__cplusplus
}
#endif

#endif	/* DECODER_H */

