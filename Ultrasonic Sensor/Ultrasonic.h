/*
 * Ultrasonic.h
 *
 *  Created on: Oct 13, 2022
 *      Author: amaar
 */
#include "std_types.h"

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

extern uint8 g_edgeCount;

void Ultrasonic_edgeProcessing(void);

void Ultrasoinc_init(void);

uint16 Ultrasonic_readDistance(void);

void Ultrasonic_trigger(void);

#endif /* ULTRASONIC_H_ */
