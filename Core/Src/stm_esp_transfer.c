#include "stm_esp_transfer.h"
int tof1_distance, tof2_distance;
void msg_t_Transmit(msg_t *msg){
//	char buffer[sizeof(msg_t)];
//	memcpy(buffer, msg, sizeof(msg));


	//HAL_UART_Transmit(&huart2, (uint8_t*)buffer,sizeof(buffer),10);
//	HAL_UART_Transmit(&huart2, array,sizeof(array),10);
	printf("encoder 1,2: %f:%f, x: %f cm y: %f cm, r_ang %frad\r\n",msg->encoder1, msg->encoder2,msg->x , msg->y, msg->angle);
	//printf("%f %f %d %d %d %f %f\r\n", msg->roll, msg->pitch, msg->sharp_distance, msg->tof1_distance, msg->tof2_distance, msg->encoder1, msg->encoder2);
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


void calculate_position(float *x, float *y, float* angle, msg_t *msg){

	float wheel_diameter = 6.5; // cm
	float wheel_distance = 20.3; // cm

	float distance_R = (msg->encoder2)*((wheel_diameter*M_PI)/360.0f);
	float distance_L = (msg->encoder1)*((wheel_diameter*M_PI)/360.0f);

	*angle = (distance_R-distance_L)/wheel_distance;
	*x = ((distance_R+distance_L)/2)*cos(*angle/2);
	*y = ((distance_R+distance_L)/2)*sin(*angle/2);



}
