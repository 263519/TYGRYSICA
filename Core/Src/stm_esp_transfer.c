#include "stm_esp_transfer.h"

void msg_t_Transmit(){
//	char buffer[sizeof(msg_t)];
//	memcpy(buffer, msg, sizeof(msg_t));
	//uint16_t xpp = 257;

	char xd[] = "20 30 40";

	HAL_UART_Transmit(&huart2,xd,sizeof(xd), 50);

}

void msg_t_SaveData(msg_t *msg){

//   MPU6050_GetRP(&(msg->pitch), &(msg->roll));
//   VL53L0X_MeasureDistance(&(msg->tof2_distance));


}
