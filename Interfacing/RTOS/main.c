/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

/*
 * Configure the processor for use with the Atmel demo board.  This is very
 * minimal as most of the setup is performed in the startup code.
 */
void clock_72(void);

/*
 * The idle hook is just used to stream data to the USB port.
 */
void vApplicationIdleHook( void );
/*-----------------------------------------------------------*/
void vApplicationStackOverflowHook( xTaskHandle *pxTask,signed char *pcTaskName );
/*
 * Setup hardware then start all the demo
 application tasks.
 */


void BlueLedTask(void *pvParameter);

int main( void )
 {

	RCC->APB2ENR = (1<<2) | (1<<4);
	GPIOC->CRH = (3<<20); //PC13 is output
	GPIOA->CRL = (3<<4) | (3<<8); //led PA1 and PA2 are output pins

	xTaskCreate(BlueLedTask,"LedTask", 300, NULL, 4, NULL);


	vTaskStartScheduler();


	while(1);

	return 0;
}

void GreenLedTask(void *pvParameter)
{
 	while(1)
	{
		GPIOA->ODR ^= (1<<1);

		vTaskDelay(1000/portTICK_PERIOD_MS);
	}
}

void BlueLedTask(void *pvParameter)
{
 	while(1)
	{
		GPIOA->ODR ^= (1<<1);
		vTaskDelay(100/portTICK_PERIOD_MS);
	}
}
