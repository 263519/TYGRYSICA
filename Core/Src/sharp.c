#include "sharp.h"
//https://www.arduinopak.com/Prd_Detail.aspx?Prd_ID=20041


void SHARP_get_distance(uint16_t *sharp_distance){
	if(*sharp_distance ==0)
		return;
	*sharp_distance = (37376/(*sharp_distance)) - 4;
}

////uint32_t adc_measurement;
//volatile uint32_t distance_cm;
//
//
//void SHARP_Init(){
//	//HAL_ADC_Start_DMA(&hadc2, &adc_measurement, 1);
//	HAL_ADC_Start_IT(&hadc2);
//}
//
//void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc){
////	if(adc_measurement == 0)
////			return;
//	//distance_cm = CONVERT_ADC_TO_DISTANCE(&hadc2);
//		distance_cm = HAL_ADC_GetValue(&hadc2);
//}

