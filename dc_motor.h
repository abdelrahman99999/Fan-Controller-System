 /******************************************************************************
 *
 * Module: dc motor
 *
 * File Name: dc_motor.h
 *
 * Description: header file for the dc motor driver
 *
 * Author: Abdelrahman Elsayed
 *
 *******************************************************************************/

/* Description:
  * Control the DC Motor direction using L293D H-bridge.
  * Control The DC Motor Speed using PWM from MC.
  */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"
#include "gpio.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*
 * to control direction
 */
#define MOTOR_PORT_CONTROL PORTB_ID
#define MOTOR_PIN0_CONTROL PIN0_ID
#define MOTOR_PIN1_CONTROL PIN1_ID

typedef enum{
	motor_stop,motor_A_CW,motor_CW
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * function responsible for initialize dc-motor
 */
void DcMotor_Init(void);

/*
 * Description :
 * setup dc-motor state as clock wise or anti-clock wise or stop
 * setup dc-motor speed, input speed should be from 0:100
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
