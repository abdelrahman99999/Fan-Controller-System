 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16/32 ADC driver
 *
 * Author: Abdelrahman Elsayed
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*	ADC_MAXIMUM_VALUE=1023 	as ATmega16/32 ADC is 10 bits (2pow10=1024)(0-1023) */
#define ADC_MAXIMUM_VALUE    1023

extern float ADC_REF_VOLT_VALUE ;

typedef enum{
	AREF_vref, AVCC_vref ,RESRVED_vref, INERNAL_vref
}ADC_ReferenceVolatge;

typedef enum{
	F_CPU_CLOCK_2=1, F_CPU_CLOCK_4, F_CPU_CLOCK_8, F_CPU_CLOCK_16 ,F_CPU_CLOCK_32, F_CPU_CLOCK_64, F_CPU_CLOCK_128
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 
  ATmega16/32 supports 8 ADC channels on PORTA we can only convert to one digital value at a time
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
