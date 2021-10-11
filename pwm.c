 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: source file for the ATmega16/32 PWM driver
 *
 * Author: Abdelrahman Elsayed
 *
 *******************************************************************************/
#include"pwm.h"
#include"avr/io.h" /*to use Timer0 Registers*/


/*
 * Description :
 * Function responsible for generating PWM signal on  OC0/PB3
 */
void PWM_Timer0_Start(uint8 set_duty_cycle)
{

	TCNT0 = 0; //Set Timer Initial value

	OCR0  = set_duty_cycle; // Set Compare Value

	DDRB  = DDRB | (1<<PB3); //set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */

	/*
	 * prescaler=8 ---> F(timer)=f(cpu)/prescaler=1Mhz/8
	 * T(timer)=1/F(timer)   ---> T=T(timer)*256
	 * so F(pwm)=1/T=500Hz
	 */

	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
