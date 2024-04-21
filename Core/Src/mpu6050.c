/*
 * mpu6050.c
 *
 *  Created on: Apr 5, 2024
 *      Authors: Szymon Wesołowski, Michał Suski
 *      Based on : msalamon.pl
 *      Kacper Maciejczak nam pomagał też <3
 */



#include "mpu6050.h"

extern I2C_HandleTypeDef hi2c2;
#define I2C_TIMEOUT 10

float acc_scale;
float gyr_scale;

void MPU6050_Init(){
	  // try to connect once, timeout 100 ms
	  HAL_I2C_IsDeviceReady(&hi2c2,MPU6050_ADDRESS, 1, I2C_TIMEOUT);

	  MPU6050_SelectGyrscopeAccelerometerRatio(AFS_SEL_ACC_2G, FS_SEL_GYRO_250);
	  // EXIT SLEEP MODE
	  uint8_t select_data = 0;
	  HAL_I2C_Mem_Write(&hi2c2, MPU6050_ADDRESS, PWR_MGMT_1, 1, &select_data, 1, I2C_TIMEOUT);

}

void MPU6050_ReadAccelerometerRaw(int16_t *x, int16_t *y, int16_t *z){
	uint8_t data[6];
	HAL_I2C_Mem_Read(&hi2c2, MPU6050_ADDRESS, ACCEL_XOUT_H, 1, data, 6, I2C_TIMEOUT);

	*x = ((int16_t)data[0] << 8) | data[1];
	*y = ((int16_t)data[2] << 8) | data[3];
	*z = ((int16_t)data[4] << 8) | data[5];

}

void MPU6050_ReadGyrscopeRaw(int16_t *x, int16_t *y, int16_t *z){
	uint8_t data[6];
	HAL_I2C_Mem_Read(&hi2c2, MPU6050_ADDRESS,  GYRO_XOUT_H, 1, data, 6, I2C_TIMEOUT);

	*x = ((int16_t)data[0] << 8) | data[1];
	*y = ((int16_t)data[2] << 8) | data[3];
	*z = ((int16_t)data[4] << 8) | data[5];

}

void MPU6050_SelectGyrscopeAccelerometerRatio(uint8_t acc_range, uint8_t gyro_range){
	  // GYRO CONFIG
	  uint8_t select_data = FS_SEL_GYRO_500;
	  HAL_I2C_Mem_Write(&hi2c2, MPU6050_ADDRESS,GYRO_CONFIG, 1, &select_data, 1, I2C_TIMEOUT);

	  // ACCEL CONFIG
	  select_data =  AFS_SEL_ACC_4G;
	  HAL_I2C_Mem_Write(&hi2c2, MPU6050_ADDRESS,ACCEL_CONFIG, 1, &select_data, 1, I2C_TIMEOUT);

	switch(gyro_range){
		// LSB SENSITIVITY - LSB/g - register map of device
		case 0:
			acc_scale = 16384.f;
			break;
		case 1:
			acc_scale = 8192.f;
			break;
		case 2:
			acc_scale = 4096.f;
			break;
		case 3:
			acc_scale = 2048.f;
			break;
	}

	switch(acc_range){

		case 0:
			gyr_scale = 131.f;
			break;
		case 1:
			gyr_scale = 65.5f;
			break;
		case 2:
			gyr_scale = 32.8f;
			break;
		case 3:
			gyr_scale = 16.4f;
			break;
		}

}

void MPU6050_ReadGyroscopeScaled(float *x, float *y, float *z){
	int16_t gyr_x, gyr_y, gyr_z;
	MPU6050_ReadAccelerometerRaw(&gyr_x, &gyr_y, &gyr_z);

	*x = (float)gyr_x / gyr_scale;
	*y = (float)gyr_y / gyr_scale;
	*z = (float)gyr_y / gyr_scale;
}

void MPU6050_ReadAccelerometerScaled(float *x, float *y, float *z){
	int16_t acc_x, acc_y, acc_z;
	MPU6050_ReadAccelerometerRaw(&acc_x, &acc_y, &acc_z);

	*x = (float)acc_x / acc_scale;
	*y = (float)acc_y / acc_scale;
	*z = (float)acc_y / acc_scale;
}

void MPU6050_GetRP(float *r, float *p){
	float a_x, a_y, a_z;
	MPU6050_ReadAccelerometerScaled(&a_x, &a_y, &a_z);

	*r = atan2(a_y, a_z) * 180.0 / M_PI;
	*p = -(atan2(a_x, sqrt(a_y*a_y + a_z*a_z)) * 180.0) / M_PI;

	*r += 135.0f;
	*p += 69.0f;

}




























