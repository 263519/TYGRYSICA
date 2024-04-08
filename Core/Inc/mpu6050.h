/*
 * mpu6050.h
 *
 *  Created on: Apr 5, 2024
 *      Authors: Szymon Wesołowski, Michał Suski
 *      Based on : msalamon.pl
 */
#include <stdio.h>

#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_




#define MPU6050_ADDRESS 0xD0	// AD0 - low
//#define MPU6050_ADDRESS 0xD1	// AD0 - high

// sensor configuration
#define GYRO_CONFIG 0x1B
#define FS_SEL_GYRO_250 0
#define FS_SEL_GYRO_500 8

#define ACCEL_CONFIG 0x1C
#define AFS_SEL_ACC_2G 0
#define AFS_SEL_ACC_4G 8

#define PWR_MGMT_1 0x6B


// read values
#define ACCEL_XOUT_H 0x3B
#define ACCEL_YOUT_H 0x3D
#define ACCEL_ZOUT_H 0x3F

#define GYRO_XOUT_H 0x43
#define GYRO_YOUT_H 0x45
#define GYRO_ZOUT_H 0x47

void MPU6050_ReadAccelerometerRaw(int16_t *x, int16_t *y, int16_t *z);
void MPU6050_ReadGyrscopeRaw(int16_t *x, int16_t *y, int16_t *z);

void MPU6050_Init();
void MPU6050_Read();
#endif /* INC_MPU6050_H_ */
