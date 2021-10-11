 /******************************************************************************
 *
 * File Name: source.c
 *
 * Description: Application
 *
 * Author: Abdelrahman Elsayed
 *
 *******************************************************************************/
#include "lcd.h"
#include "dc_motor.h"
#include "adc.h"
#include "lm35_sensor.h"


int main(){

	/* initialize ADC driver */
	ADC_ConfigType Config={INERNAL_vref,F_CPU_CLOCK_8};
	ADC_init(&Config);


	/* initialize dc-motor driver */
	DcMotor_Init();

	/* initialize LCD driver */
	LCD_init();

	/*print state of fan in the first line*/
	LCD_displayString("   FAN is");
	/*print temperature in the second line*/
	LCD_moveCursor(1,0);
	LCD_displayString("   Temp =     C");

	/*print speed of motor in third line*/
	LCD_moveCursor(2,0);
	LCD_displayString("   speed =    %");

	/*temp Variable to store the temperature value measured by LM35*/
	uint8 temp;

	/*string variable to store fan working ON/OFF*/
	char* fan_work="OFF";

	/*variables to store fan info */
	uint8 motor_speed=0;
	uint8 motor_state=motor_stop;

	while(1)
	{
		/*get temperature from LM35 periodically*/
		temp = LM35_getTemperature();

		/*display periodically periodically*/
		LCD_moveCursor(1, 10);
		LCD_intgerToString(temp);
		if(temp<100)
			LCD_displayCharacter(' ');

		if(temp < 30)
		{
			/*if temperature is less than 30 :
			 * change  state of fan to OFF
			 * speed of  fan = 0
			 *  */
			motor_speed=0;
			motor_state=motor_stop;
			fan_work="OFF";

		}else{
			/*if temperature is less than 30 :
			 * change  state of fan to ON and control direction
			 * speed of  fan depend on temperature
			 *  */
			fan_work = "ON ";
			motor_state=motor_CW;

			if (temp < 60) {
				motor_speed=25;
			}
			else if(temp<90) {
				motor_speed=50;
			}
			else if(temp<120) {
				motor_speed=75;
			}
			else if(temp<=150) {
				motor_speed=100;
			}
		}

		/*control speed and motor speed*/
		DcMotor_Rotate(motor_state,motor_speed);

		/*print fan working: OFF/ON */
		LCD_moveCursor(0, 10);
		LCD_displayString(fan_work);

		/*print fan speed*/
		LCD_moveCursor(2, 11);
		LCD_intgerToString(motor_speed);
		if(motor_speed<100)
					LCD_displayCharacter(' ');
	}

	return 0;
}
