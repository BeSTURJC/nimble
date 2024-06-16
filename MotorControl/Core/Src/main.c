/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <motorControl.h>
#include "flowControl.h"
#include "main.h"
#include "MPC.h"
#include <string.h>
#include "stdlib.h"
#include "cmsis_os.h"
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <uxr/client/transport.h>
#include <rmw_microxrcedds_c/config.h>
#include <rmw_microros/rmw_microros.h>
#include <std_msgs/msg/int32.h>
#include <std_msgs/msg/float32.h>
#include <std_msgs/msg/float64.h>
#include <std_msgs/msg/string.h>

#include <frame_data/msg/frame_data.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticTask_t osStaticThreadDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define Mode_Position 1
#define Mode_Velocity 2
#define Mode_SensorPosition 3
#define Mode_SensorVelocity 4
#define Mode_MPC 5
#define Mode_Stop 6
#define Mode_Verbose 7
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;
TIM_HandleTypeDef htim5;

UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_rx;
DMA_HandleTypeDef hdma_usart2_tx;

/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
uint32_t defaultTaskBuffer[ 3000 ];
osStaticThreadDef_t defaultTaskControlBlock;
const osThreadAttr_t defaultTask_attributes = {
		.name = "defaultTask",
		.cb_mem = &defaultTaskControlBlock,
		.cb_size = sizeof(defaultTaskControlBlock),
		.stack_mem = &defaultTaskBuffer[0],
		.stack_size = sizeof(defaultTaskBuffer),
		.priority = (osPriority_t) osPriorityNormal,
};
/* USER CODE BEGIN PV */
int16_t pos_R=0;int16_t pos_L=0;
float pos_Rp=0;float pos_Lp=0;
float pos_Rc=0;float pos_Lc=0;
float vel_R=0;float vel_L=0;
uint16_t resolucion=3600*2;
uint8_t ready;
char res_string[50];
uint8_t data[9]="";
uint8_t Pdata[200]="aaaaaaaa";
uint8_t newdata=1;
struct mode mode;
struct controlSignals controlS;
struct controlData SpeedControlMotor1;
struct controlData SpeedControlMotor2;
struct controlData PosControlMotor1;
struct controlData PosControlMotor2;

struct MPCData myControl;

//////// Declaración de variables del sensor óptico //////////
uint16_t  	valor_DR=0;
float 		dist = 0.0;
float dist_act=0.0;
float 		alfa = 0.2; // Filtro EMA
#define  d1 4
#define  d2 50
#define  v1 2.2
#define  v2 0.55
#define  escala 8.059e-4 //3.3/1023
#define  dist_min 11.32
#define  dist_max 22.5
#define  vel_min 0.0
#define  vel_max 100.0
float pos_actual = 0.0;
float contador=0.0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM5_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM4_Init(void);
void StartDefaultTask(void *argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM4)
	{ // REVISAR CLOCKS CON PEDRO
		pos_R=__HAL_TIM_GET_COUNTER(&htim1);
		pos_L=__HAL_TIM_GET_COUNTER(&htim3);

		ready=1; //Ocurre cada 10ms
		pos_Rp=pos_Rc;
		pos_Lp=pos_Lc;
		pos_Rc=pos_R*360.0/resolucion+pos_Rc;
		pos_Lc=pos_L*360.0/resolucion+pos_Lc;

		vel_R=fabs(pos_Rc-pos_Rp)/(360.0)*100.0*60.0;
		vel_L=fabs(pos_Lc-pos_Lp)/(360.0)*100.0*60.0;

		TIM3->CNT=0;
		TIM1->CNT=0;
		contador = contador+1.0;
	}
	if (htim->Instance == TIM2) {
		HAL_IncTick();
	}

	//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	printData(data,&mode, &controlS);
	HAL_UART_Transmit_DMA(&huart2, mode.res_string, sizeof(res_string));
	newdata=1;

}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	//__NOP();
	HAL_ADC_Start_IT(&hadc1);
}

//Variable global y callback suscriber
int32_t valueFramePos = 0;
int32_t valueMax2 = 0;
const char *r;
char valueControl [15];
const std_msgs__msg__String *msg4;

void subscription_callback_PosRef(const void * msgin)
{
	// Cast received message to used type
	// const std_msgs__msg__Int32 * msg3 = (const std_msgs__msg__Int32 *)msgin;
	const std_msgs__msg__Float32 * msg3 = (const std_msgs__msg__Float32 *)msgin;
	// Process message
	//pos_Rc=40;
	valueFramePos = msg3->data;

	// valueMax=valueMax+100;
	return;
}
void subscription_callback_SpeedRef(const void * msgin)
{
	// Cast received message to used type
	const std_msgs__msg__Float32 * msg5 = (const std_msgs__msg__Float32 *)msgin;
	// Process message
	//vel_R=30;
	valueMax2 = msg5->data;
	//valueMax2=valueMax2+100-1;
	return;
}
void subscription_callback_ControlMode(const void * msgin)
{
	//	msg4 = (const std_msgs__msg__String *)msgin;
	//get_message_typesupport_handle(msg4, r);
	//	strcpy(valueControl,msg4->data.data);
	// Se puede probar también memcpy()
	// según chatgpt: const std_msgs__msg__String * received_msg = (const std_msgs__msg__String *)msgin;

	return;
}


/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{

	/* USER CODE BEGIN 1 */
	float dy=(v2-v1); //0.55-2.2
	float dx=(d2-d1); //50-4
	float m =dy/dx;// -(dist_max-dist_min)/(raw_min-raw_max);
	float n = 2-m*10;
	float dist_dif = dist_max-dist_min;
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
	MX_DMA_Init();
	MX_USART2_UART_Init();
	MX_TIM1_Init();
	MX_TIM3_Init();
	MX_TIM5_Init();
	MX_ADC1_Init();
	MX_TIM4_Init();
	/* USER CODE BEGIN 2 */
	HAL_TIM_Base_Start_IT(&htim4); // REVISAR
	HAL_TIM_PWM_Init(&htim5);
	HAL_UART_Init(&huart2);
	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_2);
	HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
	HAL_ADC_Start_IT(&hadc1);

	initMainStructures(&mode, &controlS);
	initControlStructure(0.8, 0.85,&SpeedControlMotor1);
	initControlStructure(0.8, 0.85,&SpeedControlMotor2);

	initControlStructure(17, 0.822,&PosControlMotor1);
	initControlStructure(17, 0.822,&PosControlMotor2);

	/////////////  NUEVO MPC  ////////////////////7

	initMPC(&myControl);

	//////////////////////////////////////////////777

	/* USER CODE END 2 */

	/* Init scheduler */
	osKernelInitialize();

	/* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
	/* USER CODE END RTOS_MUTEX */

	/* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
	/* USER CODE END RTOS_SEMAPHORES */

	/* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
	/* USER CODE END RTOS_TIMERS */

	/* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
	/* USER CODE END RTOS_QUEUES */

	/* Create the thread(s) */
	/* creation of defaultTask */
	defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

	/* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
	/* USER CODE END RTOS_THREADS */

	/* USER CODE BEGIN RTOS_EVENTS */
	/* add events, ... */
	/* USER CODE END RTOS_EVENTS */

	/* Start scheduler */
	osKernelStart();

	/* We should never get here as control is now taken by the scheduler */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */

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

	/** Configure the main internal regulator output voltage
	 */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 336;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
	RCC_OscInitStruct.PLL.PLLQ = 7;
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
 * @brief ADC1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_ADC1_Init(void)
{

	/* USER CODE BEGIN ADC1_Init 0 */

	/* USER CODE END ADC1_Init 0 */

	ADC_ChannelConfTypeDef sConfig = {0};

	/* USER CODE BEGIN ADC1_Init 1 */

	/* USER CODE END ADC1_Init 1 */

	/** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
	 */
	hadc1.Instance = ADC1;
	hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
	hadc1.Init.Resolution = ADC_RESOLUTION_12B;
	hadc1.Init.ScanConvMode = DISABLE;
	hadc1.Init.ContinuousConvMode = ENABLE;
	hadc1.Init.DiscontinuousConvMode = DISABLE;
	hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	hadc1.Init.NbrOfConversion = 1;
	hadc1.Init.DMAContinuousRequests = DISABLE;
	hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	if (HAL_ADC_Init(&hadc1) != HAL_OK)
	{
		Error_Handler();
	}

	/** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
	 */
	sConfig.Channel = ADC_CHANNEL_4;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN ADC1_Init 2 */

	/* USER CODE END ADC1_Init 2 */

}

/**
 * @brief TIM1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM1_Init(void)
{

	/* USER CODE BEGIN TIM1_Init 0 */

	/* USER CODE END TIM1_Init 0 */

	TIM_Encoder_InitTypeDef sConfig = {0};
	TIM_MasterConfigTypeDef sMasterConfig = {0};

	/* USER CODE BEGIN TIM1_Init 1 */

	/* USER CODE END TIM1_Init 1 */
	htim1.Instance = TIM1;
	htim1.Init.Prescaler = 0;
	htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim1.Init.Period = 65535;
	htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim1.Init.RepetitionCounter = 0;
	htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
	sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
	sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
	sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
	sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
	sConfig.IC1Filter = 10;
	sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
	sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
	sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
	sConfig.IC2Filter = 10;
	if (HAL_TIM_Encoder_Init(&htim1, &sConfig) != HAL_OK)
	{
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN TIM1_Init 2 */

	/* USER CODE END TIM1_Init 2 */

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

	TIM_Encoder_InitTypeDef sConfig = {0};
	TIM_MasterConfigTypeDef sMasterConfig = {0};

	/* USER CODE BEGIN TIM3_Init 1 */

	/* USER CODE END TIM3_Init 1 */
	htim3.Instance = TIM3;
	htim3.Init.Prescaler = 0;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim3.Init.Period = 65535;
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
	sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
	sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
	sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
	sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
	sConfig.IC1Filter = 10;
	sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
	sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
	sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
	sConfig.IC2Filter = 10;
	if (HAL_TIM_Encoder_Init(&htim3, &sConfig) != HAL_OK)
	{
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN TIM3_Init 2 */

	/* USER CODE END TIM3_Init 2 */

}

/**
 * @brief TIM4 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM4_Init(void)
{

	/* USER CODE BEGIN TIM4_Init 0 */

	/* USER CODE END TIM4_Init 0 */

	TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	TIM_MasterConfigTypeDef sMasterConfig = {0};

	/* USER CODE BEGIN TIM4_Init 1 */

	/* USER CODE END TIM4_Init 1 */
	htim4.Instance = TIM4;
	htim4.Init.Prescaler = 84;
	htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim4.Init.Period = 10000;
	htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
	{
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
	{
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN TIM4_Init 2 */

	/* USER CODE END TIM4_Init 2 */

}

/**
 * @brief TIM5 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM5_Init(void)
{

	/* USER CODE BEGIN TIM5_Init 0 */

	/* USER CODE END TIM5_Init 0 */

	TIM_MasterConfigTypeDef sMasterConfig = {0};
	TIM_OC_InitTypeDef sConfigOC = {0};

	/* USER CODE BEGIN TIM5_Init 1 */

	/* USER CODE END TIM5_Init 1 */
	htim5.Instance = TIM5;
	htim5.Init.Prescaler = 84;
	htim5.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim5.Init.Period = 100;
	htim5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim5.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
	if (HAL_TIM_PWM_Init(&htim5) != HAL_OK)
	{
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim5, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 0;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if (HAL_TIM_PWM_ConfigChannel(&htim5, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
	{
		Error_Handler();
	}
	if (HAL_TIM_PWM_ConfigChannel(&htim5, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN TIM5_Init 2 */

	/* USER CODE END TIM5_Init 2 */
	HAL_TIM_MspPostInit(&htim5);

}

/**
 * @brief USART2 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART2_UART_Init(void)
{

	/* USER CODE BEGIN USART2_Init 0 */

	/* USER CODE END USART2_Init 0 */

	/* USER CODE BEGIN USART2_Init 1 */

	/* USER CODE END USART2_Init 1 */
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart2) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN USART2_Init 2 */

	/* USER CODE END USART2_Init 2 */

}

/**
 * Enable DMA controller clock
 */
static void MX_DMA_Init(void)
{

	/* DMA controller clock enable */
	__HAL_RCC_DMA1_CLK_ENABLE();

	/* DMA interrupt init */
	/* DMA1_Stream5_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);
	/* DMA1_Stream6_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA1_Stream6_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(DMA1_Stream6_IRQn);

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
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(di2M2_GPIO_Port, di2M2_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|Dir_L_Pin|Dir_R_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin : B1_Pin */
	GPIO_InitStruct.Pin = B1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pin : LD2_Pin */
	GPIO_InitStruct.Pin = LD2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pin : di2M2_Pin */
	GPIO_InitStruct.Pin = di2M2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(di2M2_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : PB0 Dir_L_Pin Dir_R_Pin */
	GPIO_InitStruct.Pin = GPIO_PIN_0|Dir_L_Pin|Dir_R_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/* USER CODE BEGIN MX_GPIO_Init_2 */
	/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
/* Funciones declaradas en microros_utils para permitir el transporte con el hardware*/
bool cubemx_transport_open(struct uxrCustomTransport * transport);
bool cubemx_transport_close(struct uxrCustomTransport * transport);
size_t cubemx_transport_write(struct uxrCustomTransport* transport, const uint8_t * buf, size_t len, uint8_t * err);
size_t cubemx_transport_read(struct uxrCustomTransport* transport, uint8_t* buf, size_t len, int timeout, uint8_t* err);

void * microros_allocate(size_t size, void * state);
void microros_deallocate(void * pointer, void * state);
void * microros_reallocate(void * pointer, size_t size, void * state);
void * microros_zero_allocate(size_t number_of_elements, size_t size_of_element, void * state);
/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */

std_msgs__msg__Float32 msg_PosRef;
std_msgs__msg__Float32 msg_SpeedRef;
std_msgs__msg__Float32 msg_ControlMode;

void StartDefaultTask(void *argument)
{
	/* USER CODE BEGIN 5 */

	// micro-ROS configuration
	/* Se llama a las funciones declaradas anteriormente para la comunicación con el HW*/
	rmw_uros_set_custom_transport(
			true,
			(void *) &huart2,
			cubemx_transport_open,
			cubemx_transport_close,
			cubemx_transport_write,
			cubemx_transport_read);

	rcl_allocator_t freeRTOS_allocator = rcutils_get_zero_initialized_allocator();
	freeRTOS_allocator.allocate = microros_allocate;
	freeRTOS_allocator.deallocate = microros_deallocate;
	freeRTOS_allocator.reallocate = microros_reallocate;
	freeRTOS_allocator.zero_allocate =  microros_zero_allocate;

	if (!rcutils_set_default_allocator(&freeRTOS_allocator)) {
		printf("Error on default allocators (line %d)\n", __LINE__);
	}

	// micro-ROS app
	//VARIABLES
	rcl_publisher_t publisher;
	rcl_publisher_t publisher_framePos;
	rcl_publisher_t publisher_frameVel;
	rcl_publisher_t publisher_framePosRef;
	rcl_publisher_t publisher_frameVelRef;
	rcl_publisher_t publisher_frameSensor;
	rcl_publisher_t publisher_contador;

	rcl_publisher_t publisher_intento;
	//rcl_publisher_t publisher_frameMode;
	std_msgs__msg__Float32 msg_framePos;
	std_msgs__msg__Float32 msg_frameVel;
	std_msgs__msg__Float32 msg_framePosRef;
	std_msgs__msg__Float32 msg_frameVelRef;
	std_msgs__msg__Float32 msg_frameSensor;
	std_msgs__msg__Float32 msg_contador;
	//std_msgs__msg__String msg_frameMode;

	frame_data__msg__FrameData intento;

	rcl_node_t node;
	rclc_support_t support;
	rcl_allocator_t allocator = rcl_get_default_allocator();

	// Instancias de inicialización, creación de nodo, publisher, etc.
	//create init_options
	rclc_support_init(&support, 0, NULL, &allocator);

	// create node
	rclc_node_init_default(&node, "controlST", "", &support);

	// create publishers
	rclc_publisher_init_default(
			&publisher_framePos,
			&node,
			ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32),
			"frame_position");
	rclc_publisher_init_default(
			&publisher_frameVel,
			&node,
			ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32),
			"frame_speed");
	rclc_publisher_init_default(
			&publisher_framePosRef,
			&node,
			ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32),
			"frame_positionRef");
	rclc_publisher_init_default(
			&publisher_frameVelRef,
			&node,
			ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32),
			"frame_speedRef");
	rclc_publisher_init_default(
			&publisher_frameSensor,
			&node,
			ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32),
			"frame_sensor_distance");
	/*rclc_publisher_init_default(
			&publisher_frameMode,
			&node,
			ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String),
			"frame_mode");*/
	rclc_publisher_init_default(
			&publisher_contador,
			&node,
			ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32),
			"frame_contador");

	/*rclc_publisher_init_default(
				&publisher_intento,
				&node,
				ROSIDL_GET_MSG_TYPE_SUPPORT(frame_data, msg, FrameData),
				"intento");*/

	// create suscribers
	rcl_subscription_t subscriber;
	rcl_subscription_t subscriber_PosRef;
	rcl_subscription_t subscriber_SpeedRef;
	rcl_subscription_t subscriber_ControlMode;

	const char * topic_name  = "PositionReference"; //COMx
	const char * topic_name2 = "SpeedReference"; //"COMx"; //"SpeedReference";
	const char * topic_name5 = "ControlMode";

	//rclc_subscription_init_default(&subscriber, &node, type_support, topic_name);
	rclc_subscription_init_best_effort(&subscriber_SpeedRef, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32), topic_name2);
	rclc_subscription_init_best_effort(&subscriber_ControlMode, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32), topic_name5);
	rclc_subscription_init_best_effort(&subscriber_PosRef, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32), topic_name);
	//  rclc_subscription_init_default(&subscriber1,&node,ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),"nombre_del_primer_topic",&topic1_callback,ON_NEW_DATA);


	std_msgs__msg__String__init(&msg_ControlMode);
	std_msgs__msg__Float32__init(&msg_PosRef);
	std_msgs__msg__Float32__init(&msg_SpeedRef);

	// create timer
	rcl_timer_t timer;
	const unsigned int timer_rate = 100;  // 1 Hz (arbitrary value)

	// create executor
	const size_t num_handles = 3;  // number of subscribers & timers. ¿¿Serían 5??
	rclc_executor_t executor=rclc_executor_get_zero_initialized_executor();
	rclc_executor_init(&executor, &support.context, num_handles, &allocator);
	// Para agregarle al ejecutor el suscriptor
	// rclc_executor_add_subscription(&executor, &subscriber1, &refPos, subscription_callback, ON_NEW_DATA); //refPos antes era msg_PosRef
	rclc_executor_add_subscription(&executor, &subscriber_PosRef, &msg_PosRef, subscription_callback_PosRef, ON_NEW_DATA);
	rclc_executor_add_subscription(&executor, &subscriber_SpeedRef, &msg_SpeedRef, subscription_callback_SpeedRef, ON_NEW_DATA);
	rclc_executor_add_subscription(&executor, &subscriber_ControlMode, &msg_ControlMode, subscription_callback_ControlMode, ON_NEW_DATA);

	float dy=(v2-v1); //0.55-2.2
	float dx=(d2-d1); //50-4
	float m =dy/dx;// -(dist_max-dist_min)/(raw_min-raw_max);
	float n = 2-m*10;
	float dist_dif = dist_max-dist_min;

	//msg_ControlMode.data=3;
	for(;;)
	{
		if(ready){
			ready=0;
			valor_DR=ADC1->DR;
			dist_act = (valor_DR*escala-n)/m;
			dist = (alfa*dist_act) + ((1-alfa)*dist);
			if (dist>=dist_max) dist=dist_max;
			if (dist<=dist_min) dist=dist_min-0.5;

			if(msg_ControlMode.data==1){
				controlS.positionReference = msg_PosRef.data;
				PosControlMotor1.error=controlS.positionReference-pos_Rc;
				TIM5->CCR1=applyPosControl(&PosControlMotor1);
				TIM5->CCR2=applyPosControl(&PosControlMotor1);
				if (PosControlMotor1.rotDirection){
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
				}
				else{
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
				}
			}
			else if(msg_ControlMode.data==2){
				controlS.speedReference = msg_SpeedRef.data;//*150.0;
				SpeedControlMotor1.error=controlS.speedReference-vel_R;
				TIM5->CCR1=applySpeedControl(&SpeedControlMotor1);
				SpeedControlMotor1.speedReference=controlS.speedReference;
				TIM5->CCR2=applySpeedControl(&SpeedControlMotor1);
				if (controlS.direction){
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
				}
				else{
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
				}
			}

			else if(msg_ControlMode.data==3){
				pos_Rp=0; pos_Lp=0; pos_Rc=0; pos_Lc=0;
				if (dist<=dist_min){
					controlS.positionReference=0; //Quedarse en la posición actual
				}
				else if(dist>dist_min && dist<dist_max){
					controlS.positionReference=((96/dist_dif)*dist)-(96*dist_min/dist_dif);
				}
				else if(dist>=dist_max){
					controlS.positionReference=96; // 11 cms corresponden a 96 grados de giro de la rueda
				}
				PosControlMotor1.error=controlS.positionReference-pos_Rc;
				TIM5->CCR1=applyPosControl(&PosControlMotor1);
				TIM5->CCR2=applyPosControl(&PosControlMotor1);
				if (PosControlMotor1.rotDirection){
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
				}
				else{
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
				}
			}
			else if(msg_ControlMode.data==4){
				if (dist<=dist_min){
					controlS.speedReference=vel_min;
				}
				else if(dist>dist_min && dist<dist_max){
					//controlS.speedReference=((50.0/23.0)*dist)-(550.0/23.0);
					controlS.speedReference=((vel_max/dist_dif)*dist)-(vel_max*dist_min/dist_dif);
				}
				else if(dist>=dist_max){
					controlS.speedReference=vel_max;
				}
				// controlS.speedReference = msg_SpeedRef.data;
				SpeedControlMotor1.error=controlS.speedReference-vel_R;
				TIM5->CCR1=applySpeedControl(&SpeedControlMotor1);
				SpeedControlMotor1.speedReference=controlS.speedReference;
				TIM5->CCR2=applySpeedControl(&SpeedControlMotor1);
				if (controlS.direction){
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
				}
				else{
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
				}
			}
			else if(msg_ControlMode.data==5){
				controlS.speedReference = msg_SpeedRef.data*150.0;
				TIM5->CCR1=runController(vel_R,controlS.speedReference,&myControl); //runController(vel_R,controlS.speedReference,myControl);
				TIM5->CCR2=TIM5->CCR1;

				if (controlS.direction){
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
				}
				else{
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
				}
			}
			else if(msg_ControlMode.data==6){
				TIM5->CCR1=0;
				TIM5->CCR2=0;
			}
		}
		msg_framePos.data=pos_Rc;
		msg_frameVel.data=vel_R;
		msg_frameSensor.data=dist;
		msg_contador.data=contador;
		msg_framePosRef.data=controlS.positionReference;
		msg_frameVelRef.data=controlS.speedReference;


		//rosidl_runtime_c__String__assign(&msg_frameMode.data, valueControl);
		//strcpy(&msg_frameMode.data,valueControl);
		rcl_ret_t ret = rcl_publish(&publisher_framePos, &msg_framePos, NULL);
		rcl_ret_t ret2 = rcl_publish(&publisher_frameVel, &msg_frameVel, NULL);
		rcl_ret_t ret5 = rcl_publish(&publisher_framePosRef, &msg_framePosRef, NULL);
		rcl_ret_t ret6 = rcl_publish(&publisher_frameVelRef, &msg_frameVelRef, NULL);
		rcl_ret_t ret3 = rcl_publish(&publisher_frameSensor, &msg_frameSensor, NULL);
		rcl_ret_t ret4 = rcl_publish(&publisher_contador, &msg_contador, NULL);
		//rcl_ret_t ret4 = rcl_publish(&publisher_frameMode, &msg_frameMode, NULL);

		/*if (ret != RCL_RET_OK)
		{
			printf("Error publishing (line %d)\n", __LINE__);
		}*/
		//Para suscribirse
		rclc_executor_spin_some(&executor, 1* (1000 * 1000));

		//osDelay(10);
	}
	/* USER CODE END 5 */
}

/**
 * @brief  Period elapsed callback in non blocking mode
 * @note   This function is called  when TIM2 interrupt took place, inside
 * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
 * a global variable "uwTick" used as application time base.
 * @param  htim : TIM handle
 * @retval None
 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
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
