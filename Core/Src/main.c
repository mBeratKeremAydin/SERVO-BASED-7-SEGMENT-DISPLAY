/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

int ct = 0;
int	btn1 = 0;
int	btn_onceki = 0;
int cokluBtn = 0;

void setServoAngleC(uint8_t htim_no, uint8_t tim_channel) {

    uint16_t pulse_length = 1000;

    TIM_HandleTypeDef* htim;

    switch (htim_no) {
        case 2: htim = &htim2; break;
        case 3: htim = &htim3; break;
        default: return;
    }

    uint32_t channel;
    switch (tim_channel) {
        case 1: channel = TIM_CHANNEL_1; break;
        case 2: channel = TIM_CHANNEL_2; break;
        case 3: channel = TIM_CHANNEL_3; break;
        case 4: channel = TIM_CHANNEL_4; break;
        default: return;
    }

    __HAL_TIM_SET_COMPARE(htim, channel, pulse_length);
}

void setServoAngleO(uint8_t htim_no, uint8_t tim_channel) {

    uint16_t pulse_length = 2000;

    TIM_HandleTypeDef* htim;

    switch (htim_no) {
        case 2: htim = &htim2; break;
        case 3: htim = &htim3; break;
        default: return;
    }

    uint32_t channel;
    switch (tim_channel) {
        case 1: channel = TIM_CHANNEL_1; break;
        case 2: channel = TIM_CHANNEL_2; break;
        case 3: channel = TIM_CHANNEL_3; break;
        case 4: channel = TIM_CHANNEL_4; break;
        default: return;
    }

    __HAL_TIM_SET_COMPARE(htim, channel, pulse_length);
}
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
  MX_TIM3_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
                /* USER CODE END WHILE */



            	  if (ct % 10 == 1)
            	  {
            		setServoAngleC(2,2);
            		setServoAngleO(2,3);
            		setServoAngleO(2,4);
            		setServoAngleC(3,2);
            		setServoAngleC(2,1);
            		setServoAngleC(3,1);
            		setServoAngleC(3,3);
            	  }else
            	  if (ct % 10 == 2)
            	  {
          		setServoAngleO(2,2);
          		setServoAngleO(2,3);
          		setServoAngleC(2,4);
          		setServoAngleO(3,2);
          		setServoAngleO(2,1);
          		setServoAngleC(3,1);
          		setServoAngleO(3,3);
            	  }else
            	  if (ct % 10 == 3)
            	  {
          		setServoAngleO(2,2);
          		setServoAngleO(2,3);
          		setServoAngleO(2,4);
          		setServoAngleO(3,2);
          		setServoAngleC(2,1);
          		setServoAngleC(3,1);
          		setServoAngleO(3,3);
            	  }else
            	  if (ct % 10 == 4)
            	  {
          		setServoAngleC(2,2);
          		setServoAngleO(2,3);
          		setServoAngleO(2,4);
          		setServoAngleC(3,2);
          		setServoAngleC(2,1);
          		setServoAngleO(3,1);
          		setServoAngleO(3,3);
            	  }else
            	  if (ct % 10 == 5)
            	  {
          		setServoAngleO(2,2);
          		setServoAngleC(2,3);
          		setServoAngleO(2,4);
          		setServoAngleO(3,2);
          		setServoAngleC(2,1);
          		setServoAngleO(3,1);
          		setServoAngleO(3,3);
            	  }else
            	  if (ct % 10 == 6)
            	  {
          		setServoAngleO(2,2);
          		setServoAngleC(2,3);
          		setServoAngleO(2,4);
          		setServoAngleO(3,2);
          		setServoAngleO(2,1);
          		setServoAngleO(3,1);
          		setServoAngleO(3,3);
            	  }else
            	  if (ct % 10 == 7)
            	  {
          		setServoAngleO(2,2);
          		setServoAngleO(2,3);
          		setServoAngleO(2,4);
          		setServoAngleC(3,2);
          		setServoAngleC(2,1);
          		setServoAngleC(3,1);
          		setServoAngleC(3,3);
            	  }else
            	  if (ct % 10 ==8)
            	  {
          		setServoAngleO(2,2);
          		setServoAngleO(2,3);
          		setServoAngleO(2,4);
          		setServoAngleO(3,2);
          		setServoAngleO(2,1);
          		setServoAngleO(3,1);
          		setServoAngleO(3,3);
            	  }else
            	  if (ct % 10 == 9)
            	  {
          		setServoAngleO(2,2);
          		setServoAngleO(2,3);
          		setServoAngleO(2,4);
          		setServoAngleO(3,2);
          		setServoAngleC(2,1);
          		setServoAngleO(3,1);
          		setServoAngleO(3,3);
            	  }else
            	  if (ct % 10 == 0)
            	  {
          		setServoAngleO(2,2);
          		setServoAngleO(2,3);
          		setServoAngleO(2,4);
          		setServoAngleO(3,2);
          		setServoAngleO(2,1);
          		setServoAngleO(3,1);
          		setServoAngleC(3,3);
            	  }


            	HAL_Delay(20);


				if( HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8) == 0 & HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3)==0  ){
								  cokluBtn = 0;
				}
				else if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == 1 & HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8) == 0){
				  cokluBtn = 2;
				}
				else if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8) == 1 & HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == 0){
				  cokluBtn = 1;
				}




            	  if (cokluBtn == 1) {
            		  btn1 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
            		  HAL_Delay(50);
            		  if(btn1 == 1 && btn_onceki == 0){
            		  ct++;
            		  }
            		  btn_onceki = btn1;
    			  }else
            	  if (cokluBtn == 2){
    				  HAL_Delay(1000);
    				  ct++;
    			  }




                /* USER CODE BEGIN 3 */


          /* USER CODE END 3 */

        /* USER CODE END 3 */
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
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
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 63;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 19999;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 63;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 19999;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pins : PA0 PA8 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB3 */
  GPIO_InitStruct.Pin = GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
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
  /* User can add his own implementation to report the HAL error return st	ate */
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
