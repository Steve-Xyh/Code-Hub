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
#include "adc.h"
#include "dma.h"
#include "gpio.h"
#include <math.h>

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
#define MAX_Delta (15.0/100.0)      //The max difference is 15%.
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint32_t ADC_Value[120];
uint32_t Pressure_1,Pressure_2,Pressure_3;
double delta_1,delta_2,delta_3;
uint8_t i;



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void LEDSwitchOn(GPIO_TypeDef* LedPort, uint16_t LedPin);
void LEDSwitchOff(GPIO_TypeDef* LedPort, uint16_t LedPin);
void LED_KEY_SwitchOn(GPIO_TypeDef* KeyPort, uint16_t KeyPin,GPIO_TypeDef* LedPort, uint16_t LedPin);

int pressButton(int press_1,int press_2,int press_3);

int maxValue(int a,int b,int c);
int max2v(int a,int b);
double calDelta(double a,double b,double c);
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
  /* MCU Configuration--------------------------------------------------------*/
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
  /* Configure the system clock */
  SystemClock_Config();
  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();


  /* USER CODE BEGIN 2 */
  HAL_ADC_Start_DMA(&hadc1,(uint32_t*)&ADC_Value,120);
  HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,0);
  HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,0);
  HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin,0);
  /* USER CODE END 2 */

  /* Infinite loop */
  while (1)
  {
    HAL_Delay(500);
    Pressure_1=Pressure_2=Pressure_3=0;

    for(i=0;i<100;){
      Pressure_1+=ADC_Value[i++];
      Pressure_2+=ADC_Value[i++];
      Pressure_3+=ADC_Value[i++];
    }
    Pressure_1/=40;               //Calculate the average amount.
    Pressure_2/=40;
    Pressure_3/=40;


    if(pressButton(Pressure_1,Pressure_2,Pressure_3)==1){
      LEDSwitchOn(LED1_GPIO_Port,LED1_Pin);
      
      LEDSwitchOff(LED2_GPIO_Port,LED2_Pin);
      LEDSwitchOff(LED3_GPIO_Port,LED3_Pin);
    }

    if(pressButton(Pressure_1,Pressure_2,Pressure_3)==2){
      LEDSwitchOn(LED2_GPIO_Port,LED2_Pin);

      LEDSwitchOff(LED1_GPIO_Port,LED1_Pin);
      LEDSwitchOff(LED3_GPIO_Port,LED3_Pin);
    }

    if(pressButton(Pressure_1,Pressure_2,Pressure_3)==3){
      LEDSwitchOn(LED3_GPIO_Port,LED3_Pin);

      LEDSwitchOff(LED1_GPIO_Port,LED1_Pin);
      LEDSwitchOff(LED2_GPIO_Port,LED2_Pin);
    }

    if(pressButton(Pressure_1,Pressure_2,Pressure_3)==0){
      LEDSwitchOn(LED1_GPIO_Port,LED1_Pin);
      LEDSwitchOn(LED2_GPIO_Port,LED2_Pin);
      LEDSwitchOn(LED3_GPIO_Port,LED3_Pin);
    }
  }
}


/* USER CODE BEGIN 4 */
int pressButton(int press_1,int press_2,int press_3)
{
  int maxv=maxValue(press_1,press_2,press_3);
  
  if(maxv==press_1){
    double err=calDelta(press_1,press_2,press_3);
    if(err>=MAX_Delta)return 1;
  }

  if(maxv==press_2){
    double err=calDelta(press_2,press_1,press_3);
    if(err>=MAX_Delta)return 2;
  }

  if(maxv==press_3){
    double err=calDelta(press_3,press_1,press_2);
    if(err>=MAX_Delta)return 3;
  }
  return 0;
}

int maxValue(int a,int b,int c) //Calculate the biggest number among 3 of them.
{
  if(a>=max2v(b,c))return a;
  if(b>=max2v(a,c))return b;
  return c;
}

int max2v(int a,int b)          //Compare 2 numbers.
{
  if(a>=b)return a;
  else return b;
}

double calDelta(double a,double b,double c)
{
  double averageDelta=(fabs(a-b)+fabs(a-c))/2.0;
  double result=averageDelta/((b+c)/2.0);
  return result;
};

void LED_KEY_SwitchOn(GPIO_TypeDef* KeyPort, uint16_t KeyPin,GPIO_TypeDef* LedPort, uint16_t LedPin)
{
  if(!HAL_GPIO_ReadPin(KeyPort,KeyPin)){
    HAL_Delay(20);            //延时去抖动
    if(!HAL_GPIO_ReadPin(KeyPort,KeyPin)){
        HAL_GPIO_WritePin(LedPort,LedPin,1);
        while(HAL_GPIO_ReadPin(KeyPort,KeyPin));
    }
  }
}

void LEDSwitchOn(GPIO_TypeDef* LedPort, uint16_t LedPin)
{
  HAL_GPIO_WritePin(LedPort,LedPin,1);
}

void LEDSwitchOff(GPIO_TypeDef* LedPort, uint16_t LedPin)
{
  HAL_GPIO_WritePin(LedPort,LedPin,0);
}
/* USER CODE END 4 */






















/********************************************Auto Generated*******************************************/

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
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
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

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
