/*
**
** LCDlib.c
**
** 7/30/06 LDJ v1.0
** 7/24/07 LDJ v1.1 porting to PIC32
** 7/26/07 LDJ v.1.2 fixed PMMODE.MODE8 bit 
** 11/12/07 LDJ v1.3 using libraries
*/

#include <p32xxxx.h>
#include <plib.h>
#include "Explore.h"
#include "LCD.h"
#include "TimeDelay.h"
#define PMDATA  PMDIN


void initLCD( void)
{
    // PMP initialization 
    mPMPOpen( PMP_ON | PMP_READ_WRITE_EN | 3,
              PMP_DATA_BUS_8 | PMP_MODE_MASTER1 | 
              PMP_WAIT_BEG_4 | PMP_WAIT_MID_15 | 
              PMP_WAIT_END_4,
              0x0001,           // only PMA0 enabled 
              PMP_INT_OFF);     // no interrupts used       
        
    // wait for >30ms
    Delayms( 30);
    
    //initiate the HD44780 display 8-bit init sequence
    PMPSetAddress( LCDCMD);     // select command register
    PMPMasterWrite( 0x38);      // 8-bit int, 2 lines, 5x7
    Delayms( 1);                // > 48 us
    
    PMPMasterWrite( 0x0c);      // ON, no cursor, no blink 
    Delayms( 1);                // > 48 us
    
    PMPMasterWrite( 0x01);      // clear display
    Delayms( 2);                // > 1.6ms
    
    PMPMasterWrite( 0x06);      // increment cursor, no shift
    Delayms( 2);                // > 1.6ms
} // initLCD


char readLCD( int addr)
{
    PMPSetAddress( addr);       // select register
    mPMPMasterReadByte();       // initiate read sequence
    return mPMPMasterReadByte();// read actual data
} // readLCD


void writeLCD( int addr, char c)    
{
    while( busyLCD());
    PMPSetAddress( addr);       // select register
    PMPMasterWrite( c);         // initiate write sequence
} // writeLCD
    

void putsLCD( char *s)
{  
    char c;
    
    while( *s) 
    {
        switch (*s)
        {
        case '\n':          // point to second line
            setLCDC( 0x40);
            break;
        case '\r':          // home, point to first line
            setLCDC( 0);
            break;
        case '\t':          // advance next tab (8) positions
            c = addrLCD();
            while( c & 7)
            {
                putLCD(' '); 
                c++;
            }
            if ( c > 15)   // if necessary move to second line
                setLCDC( 0x40);
            break;                
        default:            // print character
            putLCD( *s);
            break;
        } //switch
        s++;
    } Delayms( 1);
} //putsLCD

void newBarTip( int i, int width)
{
    char bar;
    int pos;

    // save cursor position
    while( busyLCD());
    pos = addrLCD();

    // generate a new character at position i
    // set the data pointer to the LCD CGRAM buffer
    setLCDG( i*8);

    // as a horizontal bar (0-4)x thick moving left to right
    // 7 pixel tall
    if ( width > 4)
        width = 0;
    else
        width = 4 - width;

    for( bar=0xff; width > 0; width--)
        bar<<=1;            // bar >>= 1; if right to left

    // fill each row (8) with the same pattern
    putLCD( bar);
    putLCD( bar);
    putLCD( bar);
    putLCD( bar);
    putLCD( bar);
    putLCD( bar);
    putLCD( bar);
    putLCD( bar);

    // restore cursor position
    setLCDC( pos);
} // newBarTip


void drawProgressBar( int index, int imax, int size)
{   // index is the current progress value
    // imax  is the maximum value
    // size  is the number of character positions available
    int i;

    // scale the input values in the available space
    int width = index * (size*5) / imax;

    // generate a character to represent the tip
    newBarTip( TIP, width % 5);   // user defined character 0

    // draw a bar of solid blocks
    for ( i=width/5; i>0; i--)
        putLCD( BRICK);          // filled block character

    // draw the tip of the bar
    putLCD( TIP);                // use character 0

} // drawProgressBar

void drawBpState(bool bp1, bool bp2)
{
    char s[1];

    line2LCD(); // go to second line
    putLCD('B');
    putLCD('P');
    putLCD('1');
    putLCD(':');
    sprintf( s, "%1d", bp1);
    putsLCD(s);
    putLCD(' ');
    putLCD(' ');
    putLCD('B');
    putLCD('P');
    putLCD('2');
    putLCD(':');
    sprintf( s, "%1d", bp2);
    putsLCD(s);
    
}

void clearLCD(void)
{
    clrLCD();
}