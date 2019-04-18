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
#include "mcc_generated_files/pin_manager.h"
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

    
    EUSART_Initialize();
    __delay_ms(10);
    
    // Initialize the spi
    //spiBegin(MASTER_OSC_DIV4, SAMPLE_MIDDLE, IDLE_TO_ACTIVE, IDLE_LOW);
    //__delay_ms(100);
    
    //TRISCbits.TRISC5 = 1;
    
    //int n = 0;
    int x = 0;
    uint8_t data[8];
    
    
    memset(data, 0, sizeof(data));
    
    TRISAbits.TRISA3 = 0;
    TRISAbits.TRISA4 = 0;
    TRISAbits.TRISA5= 0; // set pin as output
    //LATAbits.LATA5 = 1;  //set pin as high
    
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
        
        //LATAbits.LATA3 = 1;
        //LATAbits.LATA5 = 1;
        //PORTAbits.RA5 = 1;
                
        data[x] = EUSART_Read();
        uint8_t header = 0x59;
        uint8_t  zero = 0x00;
        uint8_t distance = 0x40;
        x++;
        
        if (x == 8)
        {
            x = 0;
             
            int n = 0;
            
            for (int n = 0; n < 8; n++)
            {
                if ((data[n] != header) && (data[n] != zero))
                {
                    if((data[n - 1] == zero) && (data[n] != zero))
                    {
                        LATAbits.LATA5 = 0;
                        PORTAbits.RA4 = 0;
                        
                    
                    }
                    
                    else if (data[n] > distance)
                    {
                        LATAbits.LATA5 = 1;
            
                
                
                        PORTAbits.RA4 = 1;
                    }   
            
                    
                    
                    else
                    {

                        LATAbits.LATA5 = 0;
                        PORTAbits.RA4 = 0;
                    }
                    
                }          
            }           
        }
    }

    return (EXIT_SUCCESS);
}



