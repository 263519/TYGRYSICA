/*
 * stm_esp_transfer.h
 *
 *  Created on: 21 kwi 2024
 *      Authors: Szymon Wesołowski, Michał Suski
 *      https://medium.com/vicara-hardware-university/a-guide-to-transmitting-structures-using-stm32-uart-and-python-56b67f806566
 */

#ifndef INC_STM_ESP_TRANSFER_H_
#define INC_STM_ESP_TRANSFER_H_
#include <stdio.h>
#include <string.h>
#include "usart.h"
#include "mpu6050.h"

typedef struct {
	float roll;
	float pitch;
	uint16_t sharp_distance;
	int tof1_distance;
	int tof2_distance;


}msg_t;

void msg_t_Transmit(msg_t *msg);
void msg_t_SaveData(msg_t *msg);

#endif /* INC_STM_ESP_TRANSFER_H_ */
