 /******************************************************************************
 *
 * Module: dc motor
 *
 * File Name: dc_motor.c
 *
 * Description: source file for the dc motor driver
 *
 * Author: Abdelrahman Elsayed
 *
 *******************************************************************************/
#include "dc_motor.h"
#include "pwm.h"



/*
 * Description :
 * function responsible for initialize dc-motor
 */
void DcMotor_Init(void){
	/* configure pins responsible for direction as output pins */
		GPIO_setupPinDirection(MOTOR_PORT_CONTROL, MOTOR_PIN0_CONTROL, PIN_OUTPUT);
		GPIO_setupPinDirection(MOTOR_PORT_CONTROL, MOTOR_PIN1_CONTROL, PIN_OUTPUT);


		/* Motor is stop at the beginning */
		GPIO_writePin(MOTOR_PORT_CONTROL, MOTOR_PIN0_CONTROL, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_CONTROL, MOTOR_PIN1_CONTROL, LOGIC_HIGH);
}

/*
 * Description :
 * setup dc-motor state as clock wise or anti-clock wise or stop
 * setup dc-motor speed, input speed should be from 0:100
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed){

	switch(state){
	case motor_stop:
		GPIO_writePin(MOTOR_PORT_CONTROL, MOTOR_PIN0_CONTROL, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_CONTROL, MOTOR_PIN1_CONTROL, LOGIC_LOW);
		break;
	case motor_A_CW:
		GPIO_writePin(MOTOR_PORT_CONTROL, MOTOR_PIN0_CONTROL, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_CONTROL, MOTOR_PIN1_CONTROL, LOGIC_HIGH);
		break;
	case motor_CW:
		GPIO_writePin(MOTOR_PORT_CONTROL, MOTOR_PIN0_CONTROL, LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT_CONTROL, MOTOR_PIN1_CONTROL, LOGIC_LOW);
		break;
	}

	uint8 duty_cycle= (uint8) (  (speed/100.0f)*255 ) ;
	PWM_Timer0_Start(duty_cycle); //generate duty cycle
}
