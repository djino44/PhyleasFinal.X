#include <stdio.h>
#include <strings.h>
#include <inttypes.h>

#include "CANFunctions.h"
#include "CAN.h"
#include "CAN_Type.h"

#include "Encoder.h"
#include "Bluetooth.h"
#include "Xbee.h"
#include "Selected_RFSolution.h"



//#define DEBUG_Decode

char P_Recovery = 0;

/*Declaration of CANTYPE, for standart or extended ID message*/

CAN_TYPE MyFrame = STD_ID;


void SendFrame(const char *MyString)
{
    #ifdef Bluetooth_Com
         WriteStringBluetooth2(MyString);
    #else
         WriteStringXbee2(MyString);
    #endif
}


void Encoder(CANRxMessageBuffer* MyMessage,CAN_MODULE module)
{
    char buf[100]={0};
    int indice;

    for(indice=0;indice<100;indice++)
    {
        buf[indice]=0;
    }

    #ifdef DEBUG_Decode
        unsigned int MyCanModule;

        if(MyMessage->msgEID.IDE == 0)
        {
            MyFrame= STD_ID;
        }
        else
        {
            MyFrame= EX_ID;
        }
        if(module==CAN1)
        {
            MyCanModule=0; //CAN1
        }
        else
        {
           MyCanModule=1; //CAN2
        }

        switch(MyFrame)
        {

            case STD_ID :
                sprintf(buf, "CAN_Module:%d  IDE:%d SID:%.3x EID:%.5x RTR:%d  payload:%.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x\n\n\n",MyCanModule,MyMessage->msgEID.IDE,MyMessage->msgSID.SID,MyMessage->msgEID.EID,MyMessage->msgEID.RTR,MyMessage->data[7],MyMessage->data[6],MyMessage->data[5],MyMessage->data[4],MyMessage->data[3],MyMessage->data[2],MyMessage->data[1],MyMessage->data[0]);
                    #ifdef Bluetooth_Com
                        WriteStringBluetooth(MyString);
                    #else
                        WriteStringXbee(MyString);`
                    #endif
                break;

            case EX_ID :

                break;

            default :

                break;
        }
    
    #else
        buf[0]  = Encode_CanInfo(MyMessage,module);
        buf[1]  = Encode_SID(MyMessage,1);
        buf[2]  = Encode_SID(MyMessage,0);
        buf[3]  = Encode_EID(MyMessage,2);
        buf[4]  = Encode_EID(MyMessage,1);
        buf[5]  = Encode_EID(MyMessage,0);
        buf[6]  = Encode_DLC(MyMessage);
        buf[7]  = Encode_DATA(MyMessage,0);
        buf[8]  = Encode_DATA(MyMessage,1);
        buf[9]  = Encode_DATA(MyMessage,2);
        buf[10] = Encode_DATA(MyMessage,3);
        buf[11] = Encode_DATA(MyMessage,4);
        buf[12] = Encode_DATA(MyMessage,5);
        buf[13] = Encode_DATA(MyMessage,6);
        buf[14] = Encode_DATA(MyMessage,7);
        buf[15] = P_Recovery;
        buf[16] = '\r';
        SendFrame(buf);

    #endif

}


CHAR Encode_CanInfo(CANRxMessageBuffer* MyMessage,CAN_MODULE module)
{
    unsigned int MyCanModule;

    if(module==CAN1)
    {
        MyCanModule=0; //CAN1
    }
    else
    {
       MyCanModule=1; //CAN2
    }

    CHAR info = ((MyCanModule<<2)|((MyMessage->msgEID.IDE)<<1)|(MyMessage->msgEID.RTR));
    return (info);
}

CHAR Encode_DLC(CANRxMessageBuffer* MyMessage)
{
    return((UINT8)MyMessage->msgEID.DLC);
}

CHAR Encode_SID(CANRxMessageBuffer* MyMessage,UINT8 ByteNumber)
{
    char value = 0;

    if(ByteNumber==0)
    {
        value = ((MyMessage->msgSID.SID)&0x00FF);
        return(value);
    }
    else
    {
        value = (((MyMessage->msgSID.SID)>>(ByteNumber * 8))&0xFF);
        return(value);
    }
}

CHAR Encode_EID(CANRxMessageBuffer* MyMessage,UINT8 ByteNumber)
{
    char value = 0;

    if(ByteNumber==0)
    {
        value = ((MyMessage->msgEID.EID)&0x00FF);
        return(value);
    }
    else
    {
        value = (((MyMessage->msgEID.EID)>>(ByteNumber * 8))&0xFF);
        return(value);
    }
}

CHAR Encode_DATA(CANRxMessageBuffer* MyMessage,const UINT8 PayloadNumber)
{
    
    UINT8 mask1 = 0x01<<PayloadNumber;

    if(MyMessage->data[PayloadNumber]=='\r')
    {
        P_Recovery|=mask1;
        return(0);
    }
    else
    {
        P_Recovery&=~mask1;
        return(MyMessage->data[PayloadNumber]);
    }
}