/*
 * adc.c
 *
 * Created: 25/11/2021 05:49:26 ص
 *  Author: ahmed essam
 */ 
#include "adc.h"

void adc_init()
{
	DDRC   &= ~(1<<PINC0);
	DIDR0  |= (1<<ADC0D);
	ADMUX  |= (1<<REFS0); //ADC0 ,Voltage Reference : AVCC with EXT capacitor
	ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

int adc_read()
{
	int datal,datah;
	ADCSRA |= (1<<ADSC);
	while(!(ADCSRA & (1<<ADIF)));
	_delay_us(10);
	datal = (int)ADCL;
	datah = (int)ADCH*256;
	datah = (datah + datal);
	//dataf = ((datah + datal)/204.5);
	return datah;
}