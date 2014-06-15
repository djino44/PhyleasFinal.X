/* 
 * File:   Bluetooth.h
 * Author: WindSignal
 *
 * Created on 19 mars 2014, 13:01
 */

#ifndef BLUETOOTH_H
#define	BLUETOOTH_H


volatile char BtBuff[3000];
volatile char Buff1;
int I_Write,I_Read;
unsigned int myFirst_Time_Flag;


typedef struct
{
    char name[20];
    char MyAdress[13];
    char Destination[13];
}BT_Device;
/***********Prototypes************/

void InitBluetooth(void);
void Init_Tab(void);
void WriteStringBluetooth(const char *string);
void WriteStringBluetooth2(const char *string);
void PutCharacterBluetooth(const char character);

#endif	/* BLUETOOTH_H */

