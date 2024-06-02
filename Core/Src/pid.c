/*
 * pid.c
 *
 *  Created on: May 26, 2024
 *      Authors: Szymon Wesołowski, Michał Suski
 *      * based on Wojciech Domski - https://edu.domski.pl/wp-content/uploads/2017/02/sr_lab04b.pdf
 */
#include "pid.h"

#define MOTOR_SPEED_HIGH 399
#define MOTOR_SPEED_LOW 0
#define ANGLE_TOLERANCE 0.2f
#define POSITION_TOLERANCE 0.2f

int right_angle = 0;
void pid_init(pid_controller_t *pid, float p, float i, float d){
	pid->p = p;
	pid->i = i;
	pid->d = d;
}


void pid_calc(pid_controller_t *pid, float x, float y, msg_t *msg, motors_t *motor) {

    float error_x = x - msg->x ;
    float error_y = -y - msg->y;
    float target_angle = atan2(y, x);
   // float target_angle = atan2(error_y, error_x);
    float error_angle = target_angle - msg->angle;
//    while (error_angle > M_PI) error_angle -= 2 * M_PI;
//    while (error_angle < -M_PI) error_angle += 2 * M_PI;
  //  printf("target: %f, curr: %f, error_angle: %f, error_x: %f, error_y: %f\r\n",
      //     target_angle, msg->angle, error_angle, error_x, error_y);

//    if (error_angle > ANGLE_TOLERANCE) {
//           // Rotate to correct the angle
//           MOTOR1_set_speed(0, motor);
//           MOTOR2_set_speed(299, motor);
//       }
    error_angle = fmod(error_angle, 2 * M_PI);
    float Kp = 1000;
    float sum_error = Kp * error_angle;
    if(sum_error > 300)
    	sum_error = 300;
    if(sum_error <-300)
     	sum_error = -300;
   // msg->angle=error_angle;
   // if (fabs(error_x) < POSITION_TOLERANCE && fabs(error_y) < POSITION_TOLERANCE)
//    if (fabs(error_angle) > ANGLE_TOLERANCE) {
//          // Angle is within tolerance, stop the motors
//
//          MOTOR1_set_speed(sum_error, motor);
//                MOTOR2_set_speed(-sum_error, motor);
//      }
//    else if(fabs(error_angle) < ANGLE_TOLERANCE &&  ){
//    	MOTOR1_set_speed(499, motor);
//    	MOTOR2_set_speed(499, motor);
//    }
//    else {
//          // Adjust motor speeds to correct position
//    	 MOTOR1_set_speed(0, motor);
//    	          MOTOR2_set_speed(0, motor);
//      }

    if(fabs(error_x) < POSITION_TOLERANCE && fabs(error_y) < POSITION_TOLERANCE){
    	 MOTOR1_set_speed(0, motor);
    	 MOTOR2_set_speed(0, motor);
    }
    else{
    	  if (fabs(error_angle) > ANGLE_TOLERANCE) {
    	          // Angle is within tolerance, stop the motors

    	          MOTOR1_set_speed(sum_error, motor);
    	                MOTOR2_set_speed(-sum_error, motor);
    	      }
    	    else if(fabs(error_angle) < ANGLE_TOLERANCE   ){
    	    	MOTOR1_set_speed(499, motor);
    	    	MOTOR2_set_speed(499, motor);
    	    }
    }
}


