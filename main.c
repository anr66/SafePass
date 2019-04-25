/* 
 * File:   main.c
 * Author: DT09
 *
 * Created on March 6, 2019, 3:09 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "mcc_generated_files/pin_manager.h"
#include "spi.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/mcc.h"

/*
 * 
 */
int main(int argc, char** argv)
{
    // Initialize system and clock
    SYSTEM_Initialize();
    OSCILLATOR_Initialize();
            
    // Initialize the pin manager
    PIN_MANAGER_Initialize();
    __delay_ms(10);
    
   
    // Initialize UART
    EUSART_Initialize();
    __delay_ms(10);
    
    SPI_Initialize();
    __delay_ms(10);

    int x = 0;
    uint8_t data[8]; 
    memset(data, 0, sizeof(data));
    
    TRISAbits.TRISA3 = 0;
    TRISAbits.TRISA4 = 0;
    TRISAbits.TRISA5 = 0; // set pin as output
    
    TRISCbits.TRISC7 = 0;
    
    
    // Begin infinite loop
    while(1)
    {         
        data[x] = EUSART_Read();
        
        uint8_t header = 0x59; 
        uint8_t  zero = 0x00;
        
        // 32 cm
        uint16_t feet = 0x0040;
        
        uint8_t spi_data = 0x29;
        
        SPI_Exchange8bit(spi_data);
        // 20 ft
        //uint16_t feet = 0x0299;
        
        // 365 ft
        //uint16_t feet = 0x2A62;
        x++;
        
        if (x == 8)
        {
            x = 0;
             
            for (int n = 0; n < 8; n++)
            {
                if ((data[n] != header) && (data[n] != zero))
                {
                    uint16_t distance = (data[n+1] << 8) | data[n];
                    
                    // checksum
                    if((data[n - 1] == zero) && (data[n] != zero))
                    {
                        LATAbits.LATA5 = 0;
                        PORTAbits.RA4 = 0;
                        PORTCbits.RC7 = 0;
                        
                       
                    }
                    
                    
                    
                    else if (distance < feet)
                    {
                    
                        LATAbits.LATA5 = 1;
                        PORTAbits.RA4 = 1;
                        PORTCbits.RC7 = 1;
                    }   
           
                    else
                    {
                        LATAbits.LATA5 = 0;
                        PORTAbits.RA4 = 0;
                        PORTCbits.RC7 = 0;
                                
                    }   
                }          
            }           
        }
    }

    return (EXIT_SUCCESS);
}



