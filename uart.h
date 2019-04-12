/* 
 * File:   uart.h
 * Author: Laptop
 *
 * Created on March 7, 2019, 2:54 PM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */


void UART_Init(const long int baudrate)
{
    ANSELCbits.ANSC6 = 0;   // Disable Analog function of pin RC6/AN8
    RC6PPS = 0x12;          // Sets RC6 to PPS Transmit Serial Data
    //SP1BRGL = 51;          // Initialising SPxBRGH & SPxBRGL register pair (BAUD)
    //SP1BRGH = 0x31;         // Initialising SPxBRGH & SPxBRGL register pair (BAUD)
    //SP1BRGL = ((_XTAL_FREQ/16)/baudrate) - 1;
    //SP1BRGL = _XTAL_FREQ/(16*(SPBRG + 1));
    SPBRG = 16;
    BRGH = 1;               // Initialising BRGH and BRG16 register pair (BAUD RATE)
    BRG16 = 0;              // Initialising BRGH and BRG16 register pair (BAUD RATE)
    SYNC = 0;               // Clearing SYNC bit (TXxSTA reg)|Configures EUSART for asynchronous operation
    SPEN = 1;               // Enables EUSART and configures TX/CK I/O pin as output
    TXEN = 1;               // Enables Transmitter circuitry
    
    //TRISC6 = 0; // TX Pin set as output
    //TRISC7 = 1; // RX Pin set as input
    
    // set baud rate. this might not be right
    //SP1BRGL = ((_XTAL_FREQ/16)/baudrate) - 1;
    //BRGH  = 0;  // for high baud_rate
    
    //TX9   = 0;    // 8-bit reception selected
    //RX9   = 0;    // 8-bit reception mode selected
    
    CREN = 1;                                     //Enables Continuous Reception
    //TXEN = 1;                                     //Enables Transmission
    
}

char UART_TX_Empty()
{
    return TRMT;
}

char UART_Data_Ready()
{
    return RCIF;
}

char UART_Read()
{
    //while(!RCIF);
    return RC1REG;
}

void UART_Read_Text(char output, unsigned int length)
{
    unsigned int i;
    for(int i=0;i<length;i++)
    {
        output = UART_Read();
    } 
}

void UART_Write(unsigned char data)
{
    while(!TRMT);
    TXREG = data;
}

void UART_Write_Text(char *text)
{
    int i;
    for(i=0;text!='\0';i++)
    {
        UART_Write(text);
    }
     
}