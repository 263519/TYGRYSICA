/*
 * mpu6050.h
 *
 *  Created on: Apr 5, 2024
 *      Authors: Szymon Wesołowski, Michał Suski
 *      Based on : msalamon.pl
 *      https://msalamon.pl/tani-laserowy-pomiar-odleglosci-z-czujnikiem-tof-vl53l0x/?utm_source=sklep_msalamon&utm_medium=product_description&utm_campaign=product_description&utm_content=Text
 */
#include "vl53l0x.h"

uint8_t Message[64];
uint8_t MessageLen;
VL53L0X_RangingMeasurementData_t RangingData;
VL53L0X_Dev_t  vl53l0x_c; // center module
VL53L0X_DEV    Dev = &vl53l0x_c;

uint32_t refSpadCount;
uint8_t isApertureSpads;
uint8_t VhvSettings;
uint8_t PhaseCal;


uint8_t Message2[64];
uint8_t MessageLen2;
VL53L0X_RangingMeasurementData_t RangingData2;
VL53L0X_Dev_t  vl53l0x_c2; // center module
VL53L0X_DEV    Dev2 = &vl53l0x_c2;

uint32_t refSpadCount2;
uint8_t isApertureSpads2;
uint8_t VhvSettings2;
uint8_t PhaseCal2;


void VL53L0X_Init(){



	 /* USER CODE BEGIN 2 */

	  MessageLen = sprintf((char*)Message, "VL53L0X test\n\r");

	  MessageLen = sprintf((char*)Message, "VL53L0X test\n\r");

	  HAL_UART_Transmit(&huart2, Message, MessageLen, 100);

	  Dev->I2cHandle = &hi2c3;
	  Dev->I2cDevAddr = 0x52;

	  HAL_GPIO_WritePin(XSHUT_TOF2_GPIO_Port, XSHUT_TOF2_Pin, GPIO_PIN_RESET); // Disable XSHUT
	  HAL_Delay(20);
	  HAL_GPIO_WritePin(XSHUT_TOF2_GPIO_Port, XSHUT_TOF2_Pin, GPIO_PIN_SET); // Enable XSHUT
	  HAL_Delay(20);

	  //
	  // VL53L0X init for Single Measurement
	  //

	  VL53L0X_WaitDeviceBooted( Dev );
	  VL53L0X_DataInit( Dev );
	  VL53L0X_StaticInit( Dev );
	  VL53L0X_PerformRefCalibration(Dev, &VhvSettings, &PhaseCal);
	  VL53L0X_PerformRefSpadManagement(Dev, &refSpadCount, &isApertureSpads);
	  VL53L0X_SetDeviceMode(Dev, VL53L0X_DEVICEMODE_SINGLE_RANGING);


	  // Enable/Disable Sigma and Signal check
	  VL53L0X_SetLimitCheckEnable(Dev, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, 1);
	  VL53L0X_SetLimitCheckEnable(Dev, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, 1);
	  VL53L0X_SetLimitCheckValue(Dev, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, (FixPoint1616_t)(0.1*65536));
	  VL53L0X_SetLimitCheckValue(Dev, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, (FixPoint1616_t)(60*65536));
	  VL53L0X_SetMeasurementTimingBudgetMicroSeconds(Dev, 33000);
	  VL53L0X_SetVcselPulsePeriod(Dev, VL53L0X_VCSEL_PERIOD_PRE_RANGE, 18);
	  VL53L0X_SetVcselPulsePeriod(Dev, VL53L0X_VCSEL_PERIOD_FINAL_RANGE, 14);
	  /* USER CODE END 2 */

}

void VL53L0X_Init2(){



	 /* USER CODE BEGIN 2 */

	  MessageLen = sprintf((char*)Message, "VL53L0X2 test\n\r");

	  MessageLen = sprintf((char*)Message, "VL53L0X2 test\n\r");

	  HAL_UART_Transmit(&huart2, Message2, MessageLen2, 100);

	  Dev2->I2cHandle = &hi2c2;
	  Dev2->I2cDevAddr = 0x52;

	  HAL_GPIO_WritePin(XSHUT_TOF1_GPIO_Port, XSHUT_TOF1_Pin, GPIO_PIN_RESET); // Disable XSHUT
	  HAL_Delay(20);
	  HAL_GPIO_WritePin(XSHUT_TOF1_GPIO_Port, XSHUT_TOF1_Pin, GPIO_PIN_SET); // Enable XSHUT
	  HAL_Delay(20);

	  //
	  // VL53L0X init for Single Measurement
	  //

	  VL53L0X_WaitDeviceBooted( Dev2 );
	  VL53L0X_DataInit( Dev2 );
	  VL53L0X_StaticInit( Dev2 );
	  VL53L0X_PerformRefCalibration(Dev2, &VhvSettings2, &PhaseCal2);
	  VL53L0X_PerformRefSpadManagement(Dev2, &refSpadCount2, &isApertureSpads2);
	  VL53L0X_SetDeviceMode(Dev2, VL53L0X_DEVICEMODE_SINGLE_RANGING);


	  // Enable/Disable Sigma and Signal check
	  VL53L0X_SetLimitCheckEnable(Dev2, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, 1);
	  VL53L0X_SetLimitCheckEnable(Dev2, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, 1);
	  VL53L0X_SetLimitCheckValue(Dev2, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, (FixPoint1616_t)(0.1*65536));
	  VL53L0X_SetLimitCheckValue(Dev2, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, (FixPoint1616_t)(60*65536));
	  VL53L0X_SetMeasurementTimingBudgetMicroSeconds(Dev2, 33000);
	  VL53L0X_SetVcselPulsePeriod(Dev2, VL53L0X_VCSEL_PERIOD_PRE_RANGE, 18);
	  VL53L0X_SetVcselPulsePeriod(Dev2, VL53L0X_VCSEL_PERIOD_FINAL_RANGE, 14);
	  /* USER CODE END 2 */

}

void VL53L0X_MeasureDistance(int *distance){
	  VL53L0X_PerformSingleRangingMeasurement(Dev, &RangingData);

		  if(RangingData.RangeStatus == 0)
		  {
			  MessageLen = sprintf((char*)Message, "Measured distance: %i\n\r", RangingData.RangeMilliMeter);
			  //HAL_UART_Transmit(&huart2, Message, MessageLen, 100);
			  *distance = RangingData.RangeMilliMeter;
		  }
}

void VL53L0X_MeasureDistance2(int *distance){
	  VL53L0X_PerformSingleRangingMeasurement(Dev2, &RangingData2);

		  if(RangingData.RangeStatus == 0)
		  {
			  MessageLen = sprintf((char*)Message, "Measured distance: %i\n\r", RangingData2.RangeMilliMeter);
			  //HAL_UART_Transmit(&huart2, Message, MessageLen, 100);
			  *distance = RangingData2.RangeMilliMeter;
		  }
}

