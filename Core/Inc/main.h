/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define GYRO_TOF_SDA_Pin GPIO_PIN_0
#define GYRO_TOF_SDA_GPIO_Port GPIOF
#define GYRO_TOF_SCL_Pin GPIO_PIN_1
#define GYRO_TOF_SCL_GPIO_Port GPIOF
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define SHARP_Pin GPIO_PIN_6
#define SHARP_GPIO_Port GPIOA
#define GPIO1_TOF2_Pin GPIO_PIN_5
#define GPIO1_TOF2_GPIO_Port GPIOC
#define DIR_MOTOR1_A_Pin GPIO_PIN_1
#define DIR_MOTOR1_A_GPIO_Port GPIOB
#define DIR_MOTOR1_B_Pin GPIO_PIN_2
#define DIR_MOTOR1_B_GPIO_Port GPIOB
#define SHIFT_CLK_Pin GPIO_PIN_11
#define SHIFT_CLK_GPIO_Port GPIOB
#define SHIFT_SER_Pin GPIO_PIN_12
#define SHIFT_SER_GPIO_Port GPIOB
#define SHIFT_LATCH_Pin GPIO_PIN_13
#define SHIFT_LATCH_GPIO_Port GPIOB
#define XSHUT_TOF1_Pin GPIO_PIN_14
#define XSHUT_TOF1_GPIO_Port GPIOB
#define XSHUT_TOF2_Pin GPIO_PIN_15
#define XSHUT_TOF2_GPIO_Port GPIOB
#define GYRO_INT_Pin GPIO_PIN_8
#define GYRO_INT_GPIO_Port GPIOC
#define GYRO_INT_EXTI_IRQn EXTI9_5_IRQn
#define TOF2_SDA_Pin GPIO_PIN_9
#define TOF2_SDA_GPIO_Port GPIOC
#define TOF2_SCL_Pin GPIO_PIN_8
#define TOF2_SCL_GPIO_Port GPIOA
#define PWM_MOTOR_1_Pin GPIO_PIN_11
#define PWM_MOTOR_1_GPIO_Port GPIOA
#define PWM_MOTOR_2_Pin GPIO_PIN_12
#define PWM_MOTOR_2_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define STM_TX_Pin GPIO_PIN_10
#define STM_TX_GPIO_Port GPIOC
#define STM_RX_Pin GPIO_PIN_11
#define STM_RX_GPIO_Port GPIOC
#define DIR_MOTOR2_A_Pin GPIO_PIN_3
#define DIR_MOTOR2_A_GPIO_Port GPIOB
#define DIR_MOTOR2_B_Pin GPIO_PIN_4
#define DIR_MOTOR2_B_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
