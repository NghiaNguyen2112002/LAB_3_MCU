/*
 * traffic_led_control.h
 *
 *  Created on: Nov 12, 2022
 *      Author: DELL
 */

#ifndef INC_TRAFFIC_LED_CONTROL_H_
#define INC_TRAFFIC_LED_CONTROL_H_

#include "main.h"
#include "led_7_seg.h"
#include "timer.h"
#include "global.h"

#define PORT_LIGHT				GPIOA

void LightOff(void);

void Blink_Red(void);
void Blink_Amber(void);
void Blink_Green(void);

void UpdateTime_Red(uint8_t duration);
void UpdateTime_Amber(uint8_t duration);
void UpdateTime_Green(uint8_t duration);

void Reset_Light(void);
void Traffic_Light_Run(void);		//this function is invoked every second
#endif /* INC_TRAFFIC_LED_CONTROL_H_ */
