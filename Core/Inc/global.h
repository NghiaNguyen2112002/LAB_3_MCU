/*
 * global.h
 *
 *  Created on: Nov 12, 2022
 *      Author: DELL
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <stdint.h>

#define SEL					0
#define MODI				1
#define SET					2

#define RED					0
#define AMBER				1
#define GREEN				2

extern uint8_t TIME_RED;
extern uint8_t TIME_AMBER;
extern uint8_t TIME_GREEN;


extern uint8_t TIME_LIGHT[3];
#endif /* INC_GLOBAL_H_ */
