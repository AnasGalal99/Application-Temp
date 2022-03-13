/*
 * Application Code.c
 *
 * Created: 3/6/2022 7:48:43 PM
 * Author : anas4
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include "uart.h"
#include "adc.h"
#include "lm35.h"
#include "timer1.h"

int Temp[6];
unsigned char count = 0;
int Average;
char buffer[6];
ISR (TIMER1_OVF_vect)
{
	count++;
	Temp[count]=(int)lm35_read();

	if(count == 6)
	{
		Average = (int)((Temp[0]+Temp[1]+Temp[2]+Temp[3]+Temp[4]+Temp[5])/6);
		count = 0;
		itoa(Average,buffer,10);
		serial_debug(buffer);

	}
}

int main(void)
{
	_delay_ms(1500);
	adc_init();
	tim1_OVinterrupt_Enable();
	uart_init();  //For Serial Monitor
	serial_debug("start!\n");
	sei();
	start_tim1_normal();
	
    while (1) 
    {
	
    }
	
}
