/*
 * adc.h
 *
 * Created: 25/11/2021 05:48:27 ص
 *  Author: ahmed essam
 */ 

#define F_CPU 8000000UL // 8 MHz clock speed
#include <avr/io.h>
#include <util/delay.h> 

#ifndef ADC_H_
#define ADC_H_



void  adc_init();
int adc_read();



#endif /* ADC_H_ */