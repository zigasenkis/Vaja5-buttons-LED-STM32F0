/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
	int pT1 = 0;
	int pT2 = 0;
	int pT3 = 0;
	int pT4 = 0;
	float pT5 = 0;
	float pT6 = 0;
	float T5Cas;
	float T6Cas;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	GPIO_PinState T1;
	GPIO_PinState T2;
	GPIO_PinState T3;
	GPIO_PinState T4;
	GPIO_PinState T5;
	GPIO_PinState T6;
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  	  T1 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10);
	  	  T2 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11);
	  	  T3 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);
	  	  T4 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13);
	  	  T5 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14);
	  	  T6 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15);
	if(T1==1){
		for (pT1 = 0; pT1 < 10; pT1++) {
				  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
				  HAL_Delay(500);
			  }
				}
	if(T2==1){
		for (pT2 = 0; pT2 < 10; pT2++) {
			  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
			  HAL_Delay(500);
				  }
					}
	if(T3==1){
		for(pT3=0; pT3 < 5; pT3++){
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
			  		  HAL_Delay(1000);
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
			  		  HAL_Delay(1000);
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);

		}
	}
	 if (T4 == 1) {
	     HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
	     HAL_Delay(1000);
	     HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
	     for (pT4 = 0; pT4 < 6; pT4++) {
	    	 HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
	    	 HAL_Delay(500);
	      }
	     HAL_Delay(250);
	     for (pT4 = 0; pT4 < 6; pT4++) {
	         HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
	         HAL_Delay(250);
	         }
	     HAL_Delay(250);
	     for (pT4 = 0; pT4 < 6; pT4++) {
	         HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
	         HAL_Delay(500);
	         }
	     HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
	     HAL_Delay(1000);
	     HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
	     }
	 if (T5 == 1) {
	     for (pT5 = 1; pT5 <= 1000; pT5 = pT5 * 2) {
	    	 T5Cas = (1 / pT5) * 1000;
	    	 HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
	    	 HAL_Delay(T5Cas);
	    	 HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
	    	 HAL_Delay(T5Cas);
	    	 }
	     }
	 if (T6 == 1) {
	 	     for (pT6 = 1000; pT6 >= 1; pT6 = pT6 / 2) {
	 	    	T6Cas = (1 / pT6) * 1000;
	 	    	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
	 	    	HAL_Delay(T6Cas);
	 	    	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
	 	    	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
	 	    	HAL_Delay(T6Cas);
	 	    	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
	 	     }
	 	     }


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

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LD4_Pin|LD3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB10 PB11 PB12 PB13 
                           PB14 PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13 
                          |GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : LD4_Pin LD3_Pin */
  GPIO_InitStruct.Pin = LD4_Pin|LD3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
