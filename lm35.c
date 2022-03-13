/*
 * lm35.c
 *
 * Created: 07/02/2022 11:56:47 م
 *  Author: ahmed essam
 */ 

#include "lm35.h"

float lm35_read()
{
	return (((adc_read())*4.88)/10); //Lm35 outputs 10mv for each  C degree , step size = 4.88mv ,almost 2steps for each degree
}