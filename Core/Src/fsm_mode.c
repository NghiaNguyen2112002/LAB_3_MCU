/*
 * fsm_mode.c
 *
 *  Created on: Nov 12, 2022
 *      Author: DELL
 */

#include "fsm_mode.h"

enum LIGHT_MOD_DISPLAY {RUN, BLINK_RED, BLINK_AMBER, BLINK_GREEN};
enum LIGHT_MOD_DISPLAY lightMode;

enum MODE {NORMAL, MODI_RED, MODI_AMBER, MODI_GREEN};
enum MODE mode;

int8_t counter_TIME;

void init_fsm_mode(void){
	lightMode = RUN;
	mode = NORMAL;
	counter_TIME = 0;
}

uint8_t isLightNormal(void){
	return (lightMode == RUN);
}
uint8_t isBlinkRed(void){
	return (lightMode == BLINK_RED);
}
uint8_t isBlinkAmber(void){
	return (lightMode == BLINK_AMBER);
}
uint8_t isBlinkGreen(void){
	return (lightMode == BLINK_GREEN);
}

void fsm_mode(void){
	switch(mode){
	case NORMAL:

		lightMode = RUN;
		if(is_button_pressed(SEL)) {
			LightOff();
			counter_TIME = 0;				//reset counter TIME
			mode = MODI_RED;
		}
		break;
	case MODI_RED:

		lightMode = BLINK_RED;
		UpdateLed7SegBuffer(TIME_RED + counter_TIME, 11);

		if(is_button_pressed(MODI))	{
			if(TIME_RED + counter_TIME < 99) counter_TIME++;
			else counter_TIME = 1 - TIME_RED;
		}
		if(is_button_pressed(SET)) {
			TIME_RED += counter_TIME;
			counter_TIME = 0;
		}
		if(is_button_pressed(SEL)) {
			LightOff();
			counter_TIME = 0;				//reset counter TIME
			mode = MODI_AMBER;
		}
		break;
	case MODI_AMBER:

		lightMode = BLINK_AMBER;
		UpdateLed7SegBuffer(TIME_AMBER + counter_TIME, 22);


		if(is_button_pressed(MODI)){
			if(TIME_AMBER + counter_TIME < 99) counter_TIME++;
			else counter_TIME = 1 - TIME_AMBER;
		}
		if(is_button_pressed(SET)) {
			TIME_AMBER += counter_TIME;
			counter_TIME = 0;
		}
		if(is_button_pressed(SEL)) {
			LightOff();
			counter_TIME = 0;				//reset counter TIME
			mode = MODI_GREEN;
		}
		break;
	case MODI_GREEN:

		lightMode = BLINK_GREEN;
		UpdateLed7SegBuffer(TIME_GREEN + counter_TIME, 33);


		if(is_button_pressed(MODI)){
			if(TIME_GREEN + counter_TIME < 99) counter_TIME++;
			else counter_TIME = 1 - TIME_GREEN;
		}
		if(is_button_pressed(SET)) {
			TIME_GREEN += counter_TIME;
			counter_TIME = 0;
		}

		if(is_button_pressed(SEL)) {
			LightOff();
			Reset_Light();
			mode = NORMAL;
		}
		break;
	default:
		break;
	}
}

