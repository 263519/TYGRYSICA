/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include "vl53l0x_api.h"
#include "mpu6050.h"
#include "stm_esp_transfer.h"
#include "sharp.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
//#define CONVERT_ADC_TO_DISTANCE(adc_val)	((37376UL / adc_val) - 4)
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
float acc_x, acc_y, acc_z, gyr_x, gyr_y, gyr_z,r,p;
int16_t a_x, a_y, a_z;
int tof2_distance;
volatile uint16_t adc_value;
volatile int adc_flag;
uint8_t xd=69;
uint32_t adc_measurement;

//uint32_t dist;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_ADC2_Init();
  MX_I2C2_Init();
  MX_I2C3_Init();
  MX_USART3_UART_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */

  uint8_t mhm[] = "10";
  MPU6050_Init();
  VL53L0X_Init();
  HAL_ADC_Start_IT(&hadc2);
//  HAL_ADC_Start_DMA(&hadc2, &adc_measurement, 1);
//  HAL_TIM_Base_Start(&htim1);
  //SHARP_Init();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {


//	  MPU6050_ReadAccelerometerScaled(&acc_x, &acc_y, &acc_z);
//	  printf("acc_x: %f, acc_y: %f,acc_z: %f\r\n",acc_x, acc_y, acc_z);
//	  MPU6050_ReadAccelerometerScaled(&gyr_x, &gyr_y, &gyr_z);
//	  printf("gyr_x: %f, gyr_y: %f,gyr_z: %f\r\n",gyr_x, gyr_y, gyr_z);

	 // printf("%d", xd);
//	    if (adc_flag == 1) {
//	    	adc_flag = 0;
//	    	//printf( "Zadana wartosc to : %d\n" , dac_value);
//		    printf( "Zmierzona wartosc to : %d\r\n" , adc_value);
//
//		    //dac_value += 50;
//		   // dac_value %= 300;
//		   // HAL_DAC_SetValue(&hdac1, DAC1_CHANNEL_1, DAC_ALIGN_8B_R,dac_value);
//
//		    HAL_ADC_Start_IT(&hadc2);
//	    }
	//	   HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
		   HAL_Delay(300);
	  //dist = get_distance();
	  	//uint16_t xpp = 257;



	  //msg_t_Transmit();


	 // msg_t_Transmit(&msg);
//  MPU6050_ReadAccelerometerScaled(&acc_x, &acc_y, &acc_z);
//  printf("a_x: %fg, a_y: %fg,a_z: %fg\r\n",acc_x, acc_y, acc_z);
//  MPU6050_ReadAccelerometerRaw(&a_x, &a_y, &a_z);
//  printf("SSa_x: %d, a_y: %d,a_z: %d\r\n",a_x, a_y, a_z);
  MPU6050_GetRP(&r, &p);
  printf("roll: %f, pitch: %f\r\n",r,p);
//	  MPU6050_ReadAccelerometerRaw(&gyr_x, &gyr_y, &gyr_z);
//	  printf("gyr_x: %d, gyr_y: %d,gyr_z: %d\r\n",gyr_x, gyr_y, gyr_z);

//	  VL53L0X_MeasureDistance(&tof2_distance);
//
//	  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2|RCC_PERIPHCLK_USART3
                              |RCC_PERIPHCLK_I2C2|RCC_PERIPHCLK_I2C3
                              |RCC_PERIPHCLK_ADC12|RCC_PERIPHCLK_TIM34;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
  PeriphClkInit.Adc12ClockSelection = RCC_ADC12PLLCLK_DIV1;
  PeriphClkInit.I2c2ClockSelection = RCC_I2C2CLKSOURCE_HSI;
  PeriphClkInit.I2c3ClockSelection = RCC_I2C3CLKSOURCE_HSI;
  PeriphClkInit.Tim34ClockSelection = RCC_TIM34CLK_HCLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
	if (hadc == &hadc2) {
		adc_flag = 1;
		adc_value = HAL_ADC_GetValue(&hadc2);
	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */


  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
