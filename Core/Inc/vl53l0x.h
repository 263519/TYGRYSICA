/*
 * mpu6050.h
 *
 *  Created on: Apr 9, 2024
 *      Authors: Szymon Wesołowski, Michał Suski
 *      Based on : msalamon.pl
 */

#ifndef INC_VL53L0X_H_
#define INC_VL53L0X_H_


#include "vl53l0x_api.h"
#include "usart.h"
#include "i2c.h"

void VL53L0X_Init();
void VL53L0X_MeasureDistance(int *distance);
void VL53L0X_Init2();
void VL53L0X_MeasureDistance2(int *distance);


#endif /* INC_VL53L0X_H_ */
