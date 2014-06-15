/* 
 * File:   Encoder.h
 * Author: RadjyTech
 *
 * Created on 3 juin 2014, 11:39
 */

#ifndef ENCODER_H
#define	ENCODER_H

#ifdef	__cplusplus
extern "C" {
#endif


/*Define*/






/*Prototypes*/

void Encoder(CANRxMessageBuffer* MyMessage,CAN_MODULE module);
void SendFrame(const char *MyString);

/*Getter Prototypes*/

CHAR Encode_CanInfo(CANRxMessageBuffer* MyMessage,CAN_MODULE module);
CHAR Encode_DLC(CANRxMessageBuffer* MyMessage);
CHAR Encode_SID(CANRxMessageBuffer* MyMessage,UINT8 ByteNumber);
CHAR Encode_EID(CANRxMessageBuffer* MyMessage,UINT8 ByteNumber);
CHAR Encode_DATA(CANRxMessageBuffer* MyMessage,const UINT8 PayloadNumber);


#ifdef	__cplusplus
}
#endif

#endif	/* ENCODER_H */

