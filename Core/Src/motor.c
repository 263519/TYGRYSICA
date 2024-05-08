/*
 * motor.c
 *
 *  Created on: Apr 26, 2024
 *      Authors: Szymon Wesołowski, Michał Suski
 */

#include "motor.h"

void MOTOR1_init(){
	MOTOR1_set_dir(CW);
	MOTOR1_set_speed(0);

	HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);

}
void MOTOR1_set_dir(MOTOR_dir dir){
	if(dir==CW){
		HAL_GPIO_WritePin(DIR_MOTOR1_A_GPIO_Port, DIR_MOTOR1_A_Pin, SET);
		HAL_GPIO_WritePin(DIR_MOTOR1_B_GPIO_Port, DIR_MOTOR1_B_Pin, RESET);
	}
	if(dir==CCW){
		HAL_GPIO_WritePin(DIR_MOTOR1_A_GPIO_Port, DIR_MOTOR1_A_Pin, RESET);
		HAL_GPIO_WritePin(DIR_MOTOR1_B_GPIO_Port, DIR_MOTOR1_B_Pin, SET);
	}
}


void MOTOR1_set_speed(uint8_t speed){

//	if(speed>=htim4.Instance->ARR)
//		speed = htim4.Instance->ARR;

	__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_2, speed);
}

void MOTOR1_read_wheel_angle(float *angle){
	  int counter_value = TIM2->CNT;

//	  if(counter_value1 != past_counter_value1){
		  *angle = (360.0f/(960.0f*2))*((float)counter_value);
//	  }
		   	//  past_counter_value1=counter_value1;
}


void MOTOR2_init(){
	MOTOR2_set_dir(CW);
	MOTOR2_set_speed(0);

	HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);

}
void MOTOR2_set_dir(MOTOR_dir dir){
	if(dir==CW){
		HAL_GPIO_WritePin(DIR_MOTOR2_A_GPIO_Port, DIR_MOTOR2_A_Pin, SET);
		HAL_GPIO_WritePin(DIR_MOTOR2_B_GPIO_Port, DIR_MOTOR2_B_Pin, RESET);
	}
	if(dir==CCW){
		HAL_GPIO_WritePin(DIR_MOTOR2_A_GPIO_Port, DIR_MOTOR2_A_Pin, RESET);
		HAL_GPIO_WritePin(DIR_MOTOR2_B_GPIO_Port, DIR_MOTOR2_B_Pin, SET);
	}
}


void MOTOR2_set_speed(uint8_t speed){

//	if(speed>=htim4.Instance->ARR)
//		speed = htim4.Instance->ARR;

	__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1, speed);
}

void MOTOR2_read_wheel_angle(float *angle){
	  int counter_value = TIM3->CNT;

//	  if(counter_value1 != past_counter_value1){
		  *angle = (360.0f/(960.0f*2))*((float)counter_value);
//	  }
		   	//  past_counter_value1=counter_value1;
}
