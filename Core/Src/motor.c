/*
 * motor.c
 *
 *  Created on: Apr 26, 2024
 *      Authors: Szymon Wesołowski, Michał Suski
 */

#include "motor.h"

void MOTOR1_init(motors_t *motor){
	MOTOR1_set_dir(CW, motor);
	MOTOR1_set_speed(0, motor);
	motor->prev_counter_value1=0;
	HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);

}
void MOTOR1_set_dir(MOTOR_dir dir, motors_t *motor){
	motor->dir_motor_1 = dir;
	if(dir==CW){
		HAL_GPIO_WritePin(DIR_MOTOR1_A_GPIO_Port, DIR_MOTOR1_A_Pin, SET);
		HAL_GPIO_WritePin(DIR_MOTOR1_B_GPIO_Port, DIR_MOTOR1_B_Pin, RESET);
	}
	if(dir==CCW){
		HAL_GPIO_WritePin(DIR_MOTOR1_A_GPIO_Port, DIR_MOTOR1_A_Pin, RESET);
		HAL_GPIO_WritePin(DIR_MOTOR1_B_GPIO_Port, DIR_MOTOR1_B_Pin, SET);
	}
}


void MOTOR1_set_speed(int16_t speed, motors_t *motor){

//	if(speed>=htim4.Instance->ARR)
//		speed = htim4.Instance->ARR;


	if(speed>0){
		motor->dir_motor_1 = CW;
			MOTOR1_set_dir(CW, motor);
	}
	else{
		motor->dir_motor_1 = CCW;
				MOTOR1_set_dir(CCW, motor);

	}


	speed=abs(speed);
		if (speed >400)
					speed = 400;
	__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_2, speed);



}

void MOTOR1_read_wheel_angle(float *angle, motors_t *motor){
	  int counter_value = TIM2->CNT;
	  int encoder_max = INT_MAX;
	  int real_value;




//	  if (motor->prev_counter_value1 > counter_value && motor->dir_motor_1 == CCW && abs(motor->prev_counter_value1 - counter_value) > 150) {
//	      real_value = (encoder_max - motor->prev_counter_value1 + counter_value);
//	  } else if (motor->prev_counter_value1 < counter_value && motor->dir_motor_1 == CW && abs(motor->prev_counter_value1 - counter_value) > 150) {
//	      real_value = -(motor->prev_counter_value1 + encoder_max - counter_value);
//	  } else {
	      real_value = counter_value - motor->prev_counter_value1 ;
//	  }

	  //	if(motor->dir_motor_1 == CW)
	  	*angle -= (360.0f / (960.0f *2)) * ((float)real_value);
//	  	else
//	  	*angle += (360.0f / (960.0f *2)) * ((float)real_value);
	  motor->prev_counter_value1 = counter_value;


//	  if(counter_value1 != past_counter_value1){
//		  *angle = (360.0f/(960.0f*2))*((float)counter_value);
//	  }
		   	//  past_counter_value1=counter_value1;
}


void MOTOR2_init(motors_t *motor){
	MOTOR2_set_dir(CW, motor);
	MOTOR2_set_speed(0, motor);
	motor->prev_counter_value2=0;
	HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);

}
void MOTOR2_set_dir(MOTOR_dir dir, motors_t *motor){
	motor->dir_motor_2=dir;
	if(dir==CW){
		HAL_GPIO_WritePin(DIR_MOTOR2_A_GPIO_Port, DIR_MOTOR2_A_Pin, SET);
		HAL_GPIO_WritePin(DIR_MOTOR2_B_GPIO_Port, DIR_MOTOR2_B_Pin, RESET);
	}
	if(dir==CCW){
		HAL_GPIO_WritePin(DIR_MOTOR2_A_GPIO_Port, DIR_MOTOR2_A_Pin, RESET);
		HAL_GPIO_WritePin(DIR_MOTOR2_B_GPIO_Port, DIR_MOTOR2_B_Pin, SET);
	}
}


void MOTOR2_set_speed(int16_t speed,  motors_t *motor){

//	if(speed>=htim4.Instance->ARR)
//		speed = htim4.Instance->ARR;



	if(speed>0){

		motor->dir_motor_2 = CCW;
			MOTOR2_set_dir(CCW, motor);
	}
	else{
		motor->dir_motor_2 = CW;
			MOTOR2_set_dir(CW, motor);
	}

	speed=abs(speed);
	if (speed >400)
				speed = 400;



	__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1, speed);
}

void MOTOR2_read_wheel_angle(float *angle, motors_t *motor){
	int counter_value = TIM3->CNT;
	int encoder_max = 65535;
	int real_value;


	if (motor->prev_counter_value2 < counter_value && motor->dir_motor_2 == CW && abs(motor->prev_counter_value2 - counter_value) > 150) {
		    real_value = (encoder_max - counter_value + motor->prev_counter_value2 );
		}
	else if (motor->prev_counter_value2 < counter_value && motor->dir_motor_2 == CCW && abs(motor->prev_counter_value2 - counter_value) > 150) {
	    real_value =-(motor->prev_counter_value2 + encoder_max - counter_value);
	}
	else {
	    real_value =  counter_value- motor->prev_counter_value2 ;
	}


//	if(motor->dir_motor_2 == CCW)
	*angle -= (360.0f / (960.0f *2)) * ((float)real_value);
//	else
//	*angle += (360.0f / (960.0f *2)) * ((float)real_value);

	motor->prev_counter_value2 = counter_value;
//	  if(counter_value1 != past_counter_value1){
		//  *angle += (360.0f/(960.0f*2))*((float)real_value);
//		  motor->prev_counter_value2 = counter_value;
////	  }
		   	//  past_counter_value1=counter_value1;
}
