/* 
 * File:   Xbee.h
 * Author: WindSignal
 *
 * Created on 19 mars 2014, 13:01
 */

#ifndef XBEE_H
#define	XBEE_H




#define UART_MODULE_ID (UART1)
#define DESIRED_BAUDRATE_XBEE (115200)

/*Variables*/



/*Prototypes*/
void Init_Xbee(void);
void WriteStringXbee(const char *string);
void PutCharacterXbee(const char character);

#endif	/* XBEE_H */



