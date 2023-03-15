/*
 * Ultrasonic.c
 *
 *  Created on: Oct 13, 2022
 *      Author: amaar
 */
#include "gpio.h"
#include "std_types.h"
#include "icu.h"
#include "common_macros.h"
#include "avr/io.h"
#include <util/delay.h> /* For the delay functions */
#include "Ultrasonic.h"

uint8  g_edgeCount = 0;

uint16 g_timeHigh = 0;

void Ultrasoinc_init(void){
	Icu_ConfigType config = {F_CPU_8,RISING};
	Icu_init(&config);
	SREG |= (1<<7);
	Icu_setCallBack(Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_OUTPUT);
}

void Ultrasonic_trigger(void){
	g_timeHigh = 0;

	GPIO_writePin(PORTB_ID,PIN5_ID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(PORTB_ID,PIN5_ID,LOGIC_LOW);
}

void Ultrasonic_edgeProcessing(void){

	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		Icu_clearTimerValue();
		Icu_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		g_timeHigh = Icu_getInputCaptureValue();

	}
}

uint16 Ultrasonic_readDistance(void){
	uint8 distance = 0;

	Ultrasonic_trigger();
	while(!(g_timeHigh));
	distance = (float)(g_timeHigh / 57.5);
	return distance;
}


