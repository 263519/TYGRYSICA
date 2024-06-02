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
#include <stdlib.h>
#include <limits.h>


typedef enum {
	CW = 0,
	CCW = 1
} MOTOR_dir;

typedef struct{
	int dir_motor_1;
	int dir_motor_2;
	int prev_counter_value1;
	int prev_counter_value2;

}motors_t;
//MOTORS INIT
void MOTOR1_init(motors_t *motor);
void MOTOR2_init(motors_t *motor);

//MOTORS CONTROL
void MOTOR1_set_dir(MOTOR_dir dir, motors_t *motor);
void MOTOR2_set_dir(MOTOR_dir dir, motors_t *motor);

void MOTOR2_set_speed(int16_t speed,  motors_t *motor);
void MOTOR1_set_speed(int16_t speed,  motors_t *motor);



//ENCODERS READINGS
void MOTOR1_read_wheel_angle(float *angle, motors_t *motor);
void MOTOR2_read_wheel_angle(float *angle, motors_t *motor);




#endif /* INC_MOTOR_H_ */
