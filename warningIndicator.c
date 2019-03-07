/*
 * File:   warningIndicator.c
 * Author: DT09
 *
 * Created on January 28, 2019, 4:53 PM
 */


#include <xc.h>
//#include <pic16f1619.h>
#include "spi.h"
#include "delay.h"

int brightness_level = 0;    //Initialize Brightness level



// Used to control the brightness level. Called by main
void brightness(void)
{
    TRISA = 0x10;
    TRISCbits.TRISC3 = 0;        // Use PortC RC3 as SS, thus set to output
    PORTCbits.RC3 = 1;          // Set hi for now.
    ADCON0=0X0F;
    
 
    // Eventually we will send the brightness level via spi
    spiBegin(MASTER_OSC_DIV4, SAMPLE_MIDDLE, IDLE_TO_ACTIVE, IDLE_LOW);
    
    /*
    if()    //If photoresistor indicates low light level
    {
        Brightness=0;       //Set Brightness Variable Low
    }

    if()    //If photoresistor indicates high light level
    {
        Brightness=1;       //Set Brightness Variable High
    }
    */

    if( PORTCbits.RC1==1 && brightness_level == 0)    //If Front End Detects Vehicle
    {
        PORTAbits.RA0 = 1;          // Set Warning Indicator Lights Low
        PORTCbits.RC3 = 0;           //ZigBee Slave Select Low
        spiWrite(1);                //Received: Traffic Detected, Warning Indicator On
        us_delay(500);
    }

    if( PORTCbits.RC1==1 && brightness_level == 1)    //If Front End Detects Vehicle
    {
        PORTAbits.RA1 = 1;          // Set Warning Indicator Lights High
        PORTCbits.RC3 = 0;           //ZigBee Slave Select Low
        spiWrite(1);                //Received: Traffic Detected, Warning Indicator On
        us_delay(500);
    }
    else                            //If Front End Did Not Detect Vehicle
    {
        PORTAbits.RA1 = 0;          //Turn off Warning Indicator
        PORTAbits.RA0 = 0;          //Turn off Warning Indicator
        PORTCbits.RC3 = 0;          //ZigBee Slave Select Low
        spiWrite(0);               //Received: No Traffic Detected, Warning Indicator Off 
        us_delay(500);
    }
        PORTCbits.RC3 = 1;          // Set SS High to End SPI communication
}

