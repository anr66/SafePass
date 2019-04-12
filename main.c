/* 
 * File:   main.c
 * Author: Laptop
 *
 * Created on March 6, 2019, 3:09 PM
 */

// Defines the clk freq as 500000KHz
//#define _XTAL_FREQ 32000000                 // Fosc  frequency for _delay()  library
//#define F_CPU 32000000

//#define FCY 32000000UL

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
//#include "delay.h"
#include "pin_manager.h"
#include "spi.h"
//#include "uart.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/mcc.h"

/*
 * 
 */
int main(int argc, char** argv)
{

    SYSTEM_Initialize();
    OSCILLATOR_Initialize();
    
            
    // Initialize the pin manager
    PIN_MANAGER_Initialize();
    __delay_ms(10);
    
    
    
    // Initialize the uart
    //UART_Init(115200);
    __delay_ms(10);
    
    EUSART_Initialize();
    
    // Initialize the spi
    //spiBegin(MASTER_OSC_DIV4, SAMPLE_MIDDLE, IDLE_TO_ACTIVE, IDLE_LOW);
    //__delay_ms(100);
    
    //TRISCbits.TRISC5 = 1;
    
    int x = 0;
    uint8_t data[50];
    memset(data, 0, sizeof(data));
    
    // Begin infinite loop
    while(1)
    {
        /*
        //spiWrite(0b00000001);
        //SSPDATPPS = 0x01;
        LED_D5_SetHigh();
        __delay_ms(1000);
        LED_D5_SetLow();
        __delay_ms(1000);
        
        LED_D7_SetHigh();
        __delay_ms(1000);
        LED_D7_SetLow();
        __delay_ms(1000);
          */
        
        
        
        //int i = 0;
        //for (i = 0; i < 50; i++)
        //{
        //    if (i > 3)
        //    {
        //        data[i - 1] = 0;
        //    }
        //    
        //    data[i] = EUSART_Read();
        //}
        
        data[x] = EUSART_Read();
        x++;
        
        if (x == 49)
        {
            x = 0;
        }
        
        //memset(data, 0, sizeof(data));
        
        
        //__delay_ms(100);
        
        
        if (data[1] > 0)
        {
            LED_D5_SetHigh();
            //__delay_ms(100);
            //LED_D5_SetLow();
            //__delay_ms(100);
        }
        /*
        
        char lidar_data[9];
        UART_Read_Text(lidar_data, 9);
    
        
        if (lidar_data[0] == 0x59)
        {
            LED_D5_SetHigh();
            __delay_ms(100);
            LED_D5_SetLow();
            __delay_ms(100);
        }
         */
        
        //LED_D5_SetHigh();
        //__delay_ms(100);
        //LED_D5_SetLow();
        //__delay_ms(100);       
        
        //char data;
        
        //uint8_t data;
        //data = UART_Read();
        
        //char test = PORTCbits.RC5;
        //char test2 = PORTC;
        
        //if (PORTCbits.RC5 >= 0x01)
       // {
         //   LED_D5_SetHigh();
         //   __delay_ms(100);
         //   LED_D5_SetLow();
         //   __delay_ms(100);  
        //}
        
        
        //LED_D4_SetHigh();
        //__delay_ms(1000);
        //LED_D4_SetLow();
        //__delay_ms(1000);
        
        //__delay_ms(100);
        //char uart;
        //uart = UART_Read();
        
        
        //uint8_t result = spiRead();
        //__delay_ms(100);
        
        /*
        if (SSPDATPPS == 0x01)
        {
            LED_D6_SetHigh();
        }
        
        else
        {
            LED_D6_SetLow();
        }
        */
    }

    return (EXIT_SUCCESS);
}



