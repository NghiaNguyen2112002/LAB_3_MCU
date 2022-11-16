/*
 * led_7_seg.c
 *
 *  Created on: Nov 12, 2022
 *      Author: DELL
 */

#include "led_7_seg.h"

static uint8_t led7SegBuffer[4]		= { 0, 0, 0, 0 };

void Enable7Seg(uint8_t index){
	if(index >= NO_OF_7SEG) return;

	switch(index){
	case 0:
		HAL_GPIO_WritePin(LED_7SEG_PORT, en0_Pin, RESET);
		HAL_GPIO_WritePin(LED_7SEG_PORT, en1_Pin | en2_Pin | en3_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(LED_7SEG_PORT, en1_Pin, RESET);
		HAL_GPIO_WritePin(LED_7SEG_PORT, en0_Pin | en2_Pin | en3_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(LED_7SEG_PORT, en2_Pin, RESET);
		HAL_GPIO_WritePin(LED_7SEG_PORT, en0_Pin | en1_Pin | en3_Pin, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(LED_7SEG_PORT, en3_Pin, RESET);
		HAL_GPIO_WritePin(LED_7SEG_PORT, en0_Pin | en1_Pin | en2_Pin, SET);
		break;
	default:
		break;
	}
}

void Display7Seg(uint8_t num){
	if(num > 9) return;
	switch(num){
	case 0:
		HAL_GPIO_WritePin(LED_7SEG_PORT, a_Pin | b_Pin | c_Pin |
										d_Pin | e_Pin | f_Pin, RESET);
		HAL_GPIO_WritePin(LED_7SEG_PORT, g_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(LED_7SEG_PORT, b_Pin | c_Pin, RESET);
		HAL_GPIO_WritePin(LED_7SEG_PORT, a_Pin | d_Pin | e_Pin |
										f_Pin | g_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(LED_7SEG_PORT, a_Pin | b_Pin | d_Pin |
										e_Pin | g_Pin, RESET);
		HAL_GPIO_WritePin(LED_7SEG_PORT, f_Pin | c_Pin, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(LED_7SEG_PORT, a_Pin | b_Pin | c_Pin |
									d_Pin | g_Pin, RESET);
		HAL_GPIO_WritePin(LED_7SEG_PORT, f_Pin | e_Pin, SET);
		break;
	case 4:
		HAL_GPIO_WritePin(LED_7SEG_PORT, b_Pin | c_Pin | f_Pin |
									g_Pin, RESET);
		HAL_GPIO_WritePin(LED_7SEG_PORT, a_Pin | e_Pin | d_Pin, SET);
		break;
	case 5:
		HAL_GPIO_WritePin(LED_7SEG_PORT, a_Pin | f_Pin | c_Pin |
									d_Pin | g_Pin, RESET);
		HAL_GPIO_WritePin(LED_7SEG_PORT, b_Pin | e_Pin, SET);
		break;
	case 6:
		HAL_GPIO_WritePin(LED_7SEG_PORT, a_Pin | f_Pin | c_Pin |
									d_Pin | e_Pin | g_Pin, RESET);
		HAL_GPIO_WritePin(LED_7SEG_PORT, b_Pin, SET);
		break;
	case 7:
		HAL_GPIO_WritePin(LED_7SEG_PORT, a_Pin | b_Pin | c_Pin, RESET);
		HAL_GPIO_WritePin(LED_7SEG_PORT, d_Pin | e_Pin | f_Pin | g_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(LED_7SEG_PORT, a_Pin | b_Pin | c_Pin |
									d_Pin | e_Pin | f_Pin | g_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(LED_7SEG_PORT, a_Pin | b_Pin | c_Pin |
									d_Pin | f_Pin | g_Pin, RESET);
		HAL_GPIO_WritePin(LED_7SEG_PORT, e_Pin, SET);
		break;
	default:
		break;
	}
}

void UpdateLed7SegBuffer(uint8_t time1, uint8_t time2){
	if(time1 >= 0 && time1 <= 99){
		led7SegBuffer[0] = time1 / 10;
		led7SegBuffer[1] = time1 % 10;
	}

	if(time2 >= 0 && time2 <= 99){
		led7SegBuffer[2] = time2 / 10;
		led7SegBuffer[3] = time2 % 10;
	}
}

void Update7Seg(uint8_t index){
	if(index >= 0 && index <= 3){
		Enable7Seg(index);
		Display7Seg( led7SegBuffer[index] );
	}
}
