/*
 * pid.c
 *
 *  Created on: May 26, 2024
 *      Authors: Szymon Wesołowski, Michał Suski
 *      * based on Wojciech Domski - https://edu.domski.pl/wp-content/uploads/2017/02/sr_lab04b.pdf
 */
#include "pid.h"

#define MOTOR_SPEED_HIGH 299
#define MOTOR_SPEED_LOW 0
#define ANGLE_TOLERANCE 0.15f
#define POSITION_TOLERANCE 0.05f




void pid_init(pid_controller_t *pid, float p, float i, float d) {
    pid->p = p;
    pid->i = i;
    pid->d = d;
    pid->integral = 0.0f;
    pid->previous_error = 0.0f;
}

void pid_calc(pid_controller_t *pid, float x, float y, msg_t *msg, motors_t *motor) {

    float error_x = x - msg->x;
    float error_y = y - msg->y;
    float target_angle = atan2(error_y, error_x);
    float error_angle = target_angle - msg->angle;


    while (error_angle > M_PI) error_angle -= 2 * M_PI;
    while (error_angle < -M_PI) error_angle += 2 * M_PI;


    pid->integral += error_angle;
    float derivative = error_angle - pid->previous_error;


    float sum_error = pid->p * error_angle + pid->i * pid->integral + pid->d * derivative;

    pid->previous_error = error_angle;


    if (sum_error > MOTOR_SPEED_HIGH) sum_error = MOTOR_SPEED_HIGH;
    if (sum_error < -MOTOR_SPEED_HIGH) sum_error = -MOTOR_SPEED_HIGH;


    if(fabs(error_x) < POSITION_TOLERANCE && fabs(error_y) < POSITION_TOLERANCE){
      	 MOTOR1_set_speed(0, motor);
      	 MOTOR2_set_speed(0, motor);
      }
      else{
      	  if (fabs(error_angle) > ANGLE_TOLERANCE) {


      	          MOTOR1_set_speed(sum_error, motor);
      	                MOTOR2_set_speed(-sum_error, motor);
      	      }
      	    else if(fabs(error_angle) < ANGLE_TOLERANCE   ){
      	    	MOTOR1_set_speed(499 + sum_error/10, motor);
      	    	MOTOR2_set_speed(499 - sum_error/10, motor);
      	    }
      }
}


