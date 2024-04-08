/*
 * mpu6050.c
 *
 *  Created on: Apr 5, 2024
 *      Authors: Szymon Wesołowski, Michał Suski
 *      Based on : msalamon.pl
 *      Kacper Maciejczak nam pomagał też <3
 */


#include "stm32f3xx_hal.h"
#include "i2c.h"
#include "mpu6050.h"

extern I2C_HandleTypeDef hi2c2;
#define I2C_TIMEOUT 10

void MPU6050_Init(){
	 // try to connect once, timeout 100 ms
	  HAL_I2C_IsDeviceReady(&hi2c2,MPU6050_ADDRESS, 1, I2C_TIMEOUT);

	  // GYRO CONFIG
	  uint8_t select_data = FS_SEL_GYRO_500;
	  ret = HAL_I2C_Mem_Write(&hi2c2, MPU6050_ADDRESS,GYRO_CONFIG, 1, &select_data, 1, I2C_TIMEOUT);

	  // ACCEL CONFIG
	  select_data =  AFS_SEL_ACC_4G;
	  HAL_I2C_Mem_Write(&hi2c2, MPU6050_ADDRESS,ACCEL_CONFIG, 1, &select_data, 1, I2C_TIMEOUT);

	  // EXIT SLEEP MODE
	  select_data = 0;
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





























