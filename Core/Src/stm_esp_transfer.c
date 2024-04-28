#include "stm_esp_transfer.h"
int tof1_distance, tof2_distance;
void msg_t_Transmit(msg_t *msg){
//	char buffer[sizeof(msg_t)];
//	memcpy(buffer, msg, sizeof(msg));


	//HAL_UART_Transmit(&huart2, (uint8_t*)buffer,sizeof(buffer),10);
//	HAL_UART_Transmit(&huart2, array,sizeof(array),10);

	 printf("%f %f %d %d %d %d\r\n", msg->roll, msg->pitch, msg->sharp_distance, msg->tof1_distance, msg->tof2_distance, msg->speed1);
//	printf("SSa %d, %d, %d\r\n", msg->roll, msg->pitch, msg->sharp_distance, msg->tof1_distance, msg->tof2_distance);
}

void msg_t_SaveData(msg_t *msg){

// MPU6050_GetRP(&(msg->pitch), &(msg->roll));
// msg->sharp_distance = 30;
// VL53L0X_MeasureDistance(&(msg->tof2_distance));
// VL53L0X_MeasureDistance(&(msg->tof1_distance));
	  MPU6050_GetRP(&(msg->pitch), &(msg->roll));
	  SHARP_get_distance(&(msg->sharp_distance));
      VL53L0X_MeasureDistance2(&tof2_distance);
	  VL53L0X_MeasureDistance(&tof1_distance);
      msg->tof1_distance = tof1_distance;
	  msg->tof2_distance = tof2_distance;

}
