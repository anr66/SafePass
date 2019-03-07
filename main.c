/* 
 * File:   main.c
 * Author: Laptop
 *
 * Created on March 6, 2019, 3:09 PM
 */

// Defines the clk freq as 500000KHz
#define _XTAL_FREQ 500000                 // Fosc  frequency for _delay()  library

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "delay.h"
#include "pin_manager.h"
#include "spi.h"
#include "uart.h"

/*
 * 
 */
int main(int argc, char** argv)
{
    PIN_MANAGER_Initialize();
    __delay_ms(100);
    UART_Init(112000);
    
    spiBegin(MASTER_OSC_DIV4, SAMPLE_MIDDLE, IDLE_TO_ACTIVE, IDLE_LOW);

    
    while(1)
    {
        //spiWrite(0b00000001);
        SSPDATPPS = 0x01;
        LED_D5_SetHigh();
        __delay_ms(500);
        LED_D5_SetLow();
        __delay_ms(500);
        
        
        //uint8_t result = spiRead();
        __delay_ms(100);
        
        if (SSPDATPPS == 0x01)
        {
            LED_D6_SetHigh();
        }
        
        else
        {
            LED_D6_SetLow();
        }
    }

    return (EXIT_SUCCESS);
}



