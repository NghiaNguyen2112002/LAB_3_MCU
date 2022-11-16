/*
 * traffic_led_control.c
 *
 *  Created on: Nov 12, 2022
 *      Author: DELL
 */


#include "traffic_led_control.h"

enum LIGHT_STATE	{INIT, RED_STATE, AMBER_STATE, GREEN_STATE};
enum LIGHT_STATE state_light_0 = INIT;
enum LIGHT_STATE state_light_1 = INIT;

static int8_t	timeLight_0 	= 0;
static int8_t	timeLight_1 	= 0;


void LightOff(void){
	HAL_GPIO_WritePin(PORT_LIGHT, RED_0_Pin|AMBER_0_Pin|GREEN_0_Pin|RED_1_Pin
	                          |AMBER_1_Pin|GREEN_1_Pin, GPIO_PIN_RESET);
}

void Blink_Red(void){
	HAL_GPIO_TogglePin(PORT_LIGHT, RED_0_Pin | RED_1_Pin);
}
void Blink_Amber(void){
	HAL_GPIO_TogglePin(PORT_LIGHT, AMBER_0_Pin | AMBER_1_Pin);
}
void Blink_Green(void){
	HAL_GPIO_TogglePin(PORT_LIGHT, GREEN_0_Pin | GREEN_1_Pin);
}

void UpdateTime_Red(uint8_t duration){
	if(duration > 99) return;
	TIME_RED = duration;
}
void UpdateTime_Amber(uint8_t duration){
	if(duration > 99) return;
	TIME_AMBER = duration;
}
void UpdateTime_Green(uint8_t duration){
	if(duration > 99) return;
	TIME_GREEN = duration;
}

void Reset_Light(void){
	state_light_0 = INIT; timeLight_0 = 0;
	state_light_1 = INIT; timeLight_1 = 0;
}

void Traffic_Light_0(void){
	switch(state_light_0){
	case INIT:
		timeLight_0 = TIME_RED;
		HAL_GPIO_WritePin(PORT_LIGHT, RED_0_Pin, SET);
		HAL_GPIO_WritePin(PORT_LIGHT, AMBER_0_Pin | GREEN_0_Pin, RESET);
		state_light_0 = RED_STATE;
		break;
	case GREEN_STATE:
		timeLight_0 = TIME_AMBER;
		HAL_GPIO_WritePin(PORT_LIGHT, AMBER_0_Pin, SET);
		HAL_GPIO_WritePin(PORT_LIGHT, RED_0_Pin | GREEN_0_Pin, RESET);
		state_light_0 = AMBER_STATE;
		break;
	case AMBER_STATE:
		timeLight_0 = TIME_RED;
		HAL_GPIO_WritePin(PORT_LIGHT, RED_0_Pin, SET);
		HAL_GPIO_WritePin(PORT_LIGHT, AMBER_0_Pin | GREEN_0_Pin, RESET);
		state_light_0 = RED_STATE;
		break;
	case RED_STATE:
		timeLight_0 = TIME_GREEN;
		HAL_GPIO_WritePin(PORT_LIGHT, GREEN_0_Pin, SET);
		HAL_GPIO_WritePin(PORT_LIGHT, RED_0_Pin | AMBER_0_Pin, RESET);
		state_light_0 = GREEN_STATE;
		break;
	default:
		break;
	}
}

void Traffic_Light_1(void){
	switch(state_light_1){
	case INIT:
		timeLight_1 = TIME_GREEN;
		HAL_GPIO_WritePin(PORT_LIGHT, GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(PORT_LIGHT, RED_1_Pin | AMBER_1_Pin, RESET);
		state_light_1 = GREEN_STATE;
		break;
	case GREEN_STATE:
		timeLight_1 = TIME_AMBER;
		HAL_GPIO_WritePin(PORT_LIGHT, AMBER_1_Pin, SET);
		HAL_GPIO_WritePin(PORT_LIGHT, RED_1_Pin | GREEN_1_Pin, RESET);
		state_light_1 = AMBER_STATE;
		break;
	case AMBER_STATE:
		timeLight_1 = TIME_RED;
		HAL_GPIO_WritePin(PORT_LIGHT, RED_1_Pin, SET);
		HAL_GPIO_WritePin(PORT_LIGHT, AMBER_1_Pin | GREEN_1_Pin, RESET);
		state_light_1 = RED_STATE;
		break;
	case RED_STATE:
		timeLight_1 = TIME_GREEN;
		HAL_GPIO_WritePin(PORT_LIGHT, GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(PORT_LIGHT, RED_1_Pin | AMBER_1_Pin, RESET);
		state_light_1 = GREEN_STATE;
		break;
	default:
		break;
	}
}

void Traffic_Light_Run(void){
	if(timeLight_0 <= 0){
		Traffic_Light_0();
	}
	if(timeLight_1 <= 0){
		Traffic_Light_1();
	}

	UpdateLed7SegBuffer(timeLight_0, timeLight_1);
	timeLight_0--; timeLight_1--;
}

