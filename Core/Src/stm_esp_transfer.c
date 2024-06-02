#include "stm_esp_transfer.h"
int tof1_distance, tof2_distance;






void msg_t_Init(msg_t *msg){
	msg->roll = 0;
	msg->pitch = 0;
	msg->sharp_distance =0 ;
	msg->tof1_distance=0;
	msg->tof2_distance=0;
	msg->speed1=0;
	msg->encoder1=0;
	msg->encoder2=0;

	// do zmiany bedzie
	msg->prev_encoder1=0;
	msg->prev_encoder2=0;
	msg->x=0;
	msg->y=0;
	msg->angle=0;
	msg->prev_angle=0;


}




void msg_t_Transmit(msg_t *msg){
//	char buffer[sizeof(msg_t)];
//	memcpy(buffer, msg, sizeof(msg));


	//HAL_UART_Transmit(&huart2, (uint8_t*)buffer,sizeof(buffer),10);
//	HAL_UART_Transmit(&huart2, array,sizeof(array),10);

	//printf("encoder 1,2: %f:%f, x: %f cm y: %f cm, r_ang %frad\r\n",msg->encoder1, msg->encoder2,msg->x , msg->y, msg->angle);
	//printf("%f %f %d %d %d %f %f\r\n", msg->roll, msg->pitch, msg->sharp_distance, msg->tof1_distance, msg->tof2_distance, msg->encoder1, msg->encoder2);

	//printf("encoder 1,2: %f:%f, x: %f cm y: %f cm, r_ang %frad\r\n",msg->encoder1, msg->encoder2,msg->x , msg->y, msg->angle);
	printf("%f %f %d %d %d %f %f %f \n", msg->roll, msg->pitch, msg->sharp_distance, msg->tof1_distance, msg->tof2_distance, msg->x, msg->y,msg->angle);
	//printf("")

//	printf("SSa %d, %d, %d\r\n", msg->roll, msg->pitch, msg->sharp_distance, msg->tof1_distance, msg->tof2_distance);
	//printf("%f %f %d %d %d %f %f\r\n",2,2,2,2,2,2,2);
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
	float wheel_distance = 15.0; // cm

	float distance_R = (msg->encoder2-msg->prev_encoder2)*((wheel_diameter*M_PI)/360.0f);
	float distance_L = (msg->encoder1-msg->prev_encoder1)*((wheel_diameter*M_PI)/360.0f);

	float angle_change = (distance_R-distance_L)/wheel_distance;

	*x += ((distance_R+distance_L)/2)*cos(*angle + angle_change/2)/100;
	*y += ((distance_R+distance_L)/2)*sin(*angle + angle_change/2)/100;

	*angle += angle_change;
	*angle = fmod(*angle, 2 * M_PI);
	msg->prev_encoder1=msg->encoder1;
	msg->prev_encoder2=msg->encoder2;
}
