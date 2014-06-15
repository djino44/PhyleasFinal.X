
#include <stdio.h>
#include <strings.h>

#include "CANFunctions.h"
#include "CAN.h"
#include "CAN_Type.h"
#include "Decoder.h"


#include "Bluetooth.h"
#include "Xbee.h"
#include "Selected_RFSolution.h"

CAN_TYPE MyFrame;

void Decoder(char *Mytab)
{
    CANTxMessageBuffer * message;
    message = CANGetTxMessageBuffer(CAN1,CAN_CHANNEL0);

    if(message != NULL)
    {
            message->messageWord[0] = 0;
            message->messageWord[1] = 0;
            message->messageWord[2] = 0;
            message->messageWord[3] = 0;



            if ((Get_IDE(dmaBuff)) == 1) {
                MyFrame = EX_ID;
            } else {
                MyFrame = STD_ID;
            }

            switch (MyFrame) {

                case STD_ID:

                    message->msgSID.SID = Get_SID();
                    message->msgEID.IDE = Get_IDE(dmaBuff);
                    message->msgEID.DLC = Get_DLC(dmaBuff);
                    message->data[0] = Get_PAYLOAD(dmaBuff, 0);
                    message->data[1] = Get_PAYLOAD(dmaBuff, 1);
                    message->data[2] = Get_PAYLOAD(dmaBuff, 2);
                    message->data[3] = Get_PAYLOAD(dmaBuff, 3);
                    message->data[4] = Get_PAYLOAD(dmaBuff, 4);
                    message->data[5] = Get_PAYLOAD(dmaBuff, 5);
                    message->data[6] = Get_PAYLOAD(dmaBuff, 6);
                    message->data[7] = Get_PAYLOAD(dmaBuff, 7);

                    break;

                case EX_ID:

                    message->msgSID.SID = Get_SID(); /* Send message to CAN2.				*/
                    message->msgEID.EID = Get_EID(dmaBuff); /* Send message to CAN2.				*/
                    message->msgEID.IDE = Get_IDE(dmaBuff); /* IDE = 1 means Extended ID message.	*/
                    message->msgEID.RTR = Get_RTR(dmaBuff); /* Not an RTR message.              	*/
                    message->msgEID.DLC = Get_DLC(dmaBuff); /* Send one byte of data.				*/
                    message->data[0] = Get_PAYLOAD(dmaBuff, 0);
                    message->data[1] = Get_PAYLOAD(dmaBuff, 1);
                    message->data[2] = Get_PAYLOAD(dmaBuff, 2);
                    message->data[3] = Get_PAYLOAD(dmaBuff, 3);
                    message->data[4] = Get_PAYLOAD(dmaBuff, 4);
                    message->data[5] = Get_PAYLOAD(dmaBuff, 5);
                    message->data[6] = Get_PAYLOAD(dmaBuff, 6);
                    message->data[7] = Get_PAYLOAD(dmaBuff, 7);

                    break;
            }

            CANUpdateChannel(CAN1, CAN_CHANNEL0);
            CANFlushTxChannel(CAN1, CAN_CHANNEL0);
    }



}

UINT16 Get_SID(void) {
    UINT16 toto = 0x0000;
     //toto = (((uint16_t)dmaBuff[1] << 8) | (uint16_t)dmaBuff[2]&0xFF);
     toto=( ((UINT16)dmaBuff[1]&0xFF) << 8) | ((UINT16)dmaBuff[2]&0xFF);
    return (toto);
}

UINT32 Get_EID(char *Mytab) {
    return ((UINT32) dmaBuff[3] << 16 | (UINT32) dmaBuff[4] << 8 | dmaBuff[5]);
}

int Get_RTR(char *Mytab) {
    return (dmaBuff[0]&0x01);
}

CAN_MODULE Get_CAN_Module(char *Mytab) {
    if (((dmaBuff[0]&0x4) >> 2) == 1) {
        return (CAN2);
    } else return (CAN1);
}

int Get_IDE(char *Mytab) {
    return ((dmaBuff[0]&0x2) >> 1);
}

int Get_DLC(char *Mytab) {
    return (dmaBuff[6]);
}

BYTE Get_PAYLOAD(char *Mytab, int PayloadNumber) {
    int mask = 0x01 << PayloadNumber;

    if ((((dmaBuff[15] & mask) >> PayloadNumber) == 1) && (dmaBuff[7 + PayloadNumber] == 0)) {
        return (0x0D);
    } else return ((BYTE) (dmaBuff[7 + PayloadNumber]));

}

