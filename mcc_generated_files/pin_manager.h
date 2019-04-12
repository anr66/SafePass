/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F1619
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB 	          :  MPLAB X 5.10	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SDI aliases
#define SDI_TRIS                 TRISBbits.TRISB4
#define SDI_LAT                  LATBbits.LATB4
#define SDI_PORT                 PORTBbits.RB4
#define SDI_WPU                  WPUBbits.WPUB4
#define SDI_OD                   ODCONBbits.ODB4
#define SDI_ANS                  ANSELBbits.ANSB4
#define SDI_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SDI_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SDI_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SDI_GetValue()           PORTBbits.RB4
#define SDI_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SDI_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SDI_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SDI_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SDI_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define SDI_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define SDI_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define SDI_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set SCK aliases
#define SCK_TRIS                 TRISBbits.TRISB6
#define SCK_LAT                  LATBbits.LATB6
#define SCK_PORT                 PORTBbits.RB6
#define SCK_WPU                  WPUBbits.WPUB6
#define SCK_OD                   ODCONBbits.ODB6
#define SCK_ANS                  ANSELBbits.ANSB6
#define SCK_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define SCK_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define SCK_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define SCK_GetValue()           PORTBbits.RB6
#define SCK_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define SCK_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define SCK_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define SCK_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define SCK_SetPushPull()        do { ODCONBbits.ODB6 = 0; } while(0)
#define SCK_SetOpenDrain()       do { ODCONBbits.ODB6 = 1; } while(0)
#define SCK_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define SCK_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSB7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/