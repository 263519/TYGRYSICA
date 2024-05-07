/*
 * motor.h
 *
 *  Created on: Apr 26, 2024
 *      Authors: Szymon Wesołowski, Michał Suski
 *      * based on: https://www.stm32wrobotyce.pl/2021/01/23/sterowanie-silnikiem-dc/
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "tim.h"
#include "gpio.h"


typedef enum {
	CW = 0,
	CCW = 1
} MOTOR_dir;


void MOTOR1_init();
void MOTOR1_set_dir(MOTOR_dir dir);
void MOTOR1_set_speed(uint8_t speed);
void MOTOR2_init();
void MOTOR2_set_dir(MOTOR_dir dir);
void MOTOR2_set_speed(uint8_t speed);


#endif /* INC_MOTOR_H_ */
