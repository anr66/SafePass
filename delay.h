/* 
 * File:   delay.h
 * Author: DT09
 *
 * Created on March 6, 2019, 3:11 PM
 */

#ifndef DELAY_H
#define	DELAY_H

#include <xc.h>

#ifdef	__cplusplus
extern "C" {
#endif
    
    
    
void ms_delay(int N)
{
    T1CON = 0x8030; // TON, Fcy=16MHz, Prescale 256
    TMR1 = 0; // Clear Timer1
    while(TMR1 < 62.5*N) // wait for TMR1 to count up.
    {
    }
}

void us_delay(int us) 
{
    T2CON = 0x8010; // Timer 2 on, TCKPS<1,0> = 01 thus 8 Prescale thus 2MHz
    TMR2 = 0;
    while (TMR2 < us * 2); // 1/16MHz/(8*2)) = 1us.)
}

#ifdef	__cplusplus
}
#endif

#endif	/* DELAY_H */

