/*
 * led_7_seg.h
 *
 *  Created on: Nov 12, 2022
 *      Author: DELL
 */

#ifndef INC_LED_7_SEG_H_
#define INC_LED_7_SEG_H_

#include "main.h"

#define NO_OF_7SEG				4

#define LED_7SEG_PORT			GPIOB

void UpdateLed7SegBuffer(uint8_t time1, uint8_t time2);
void Update7Seg(uint8_t indexLed7Seg);

#endif /* INC_LED_7_SEG_H_ */
