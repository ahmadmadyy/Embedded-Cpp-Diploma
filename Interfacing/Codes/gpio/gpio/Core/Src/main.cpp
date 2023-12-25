/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#include "main.h"
constexpr uint8_t RCC_IOPA_BIT 		= 2;
constexpr uint8_t RCC_IOPB_BIT 		= 3;
constexpr uint8_t LED_PIN_NUMBER 	= 1;
constexpr uint8_t BTN_PIN_NUM 		= 4;
typedef enum
{
	Output_mode_push_pull_max_speed_50 = 3,
	INPUT_Mode_floating_input
	/* TODO */
}Config;

void RCC_APB2_Clock_Enable(bool enabled,uint8_t pinNumber )
	{

		if(enabled)
		{
			RCC->APB2ENR |= 1<<pinNumber;
		}
		else
		{
			RCC->APB2ENR &=~ (1<<pinNumber);
		}
	}
class Led
	{
	public:
		Led(GPIO_TypeDef* GPIOPort,uint8_t pinNum, Config config): LEDPort(GPIOPort), pinNumber(pinNum)
		{
			if(pinNum<8)
				LEDPort->CRL = (config<<4*LED_PIN_NUMBER);
			else if(pinNum>=8 && pinNum < 16)
				LEDPort->CRH = (config<<4*(LED_PIN_NUMBER%8));

		}
		void ledOn()
		{
			LEDPort->ODR |= 1<<pinNumber; // setting bit
		}
		void ledOff()
		{
			LEDPort->ODR &= ~(1<<pinNumber);   // reset a bit
		}
	private:
		GPIO_TypeDef* LEDPort;
		uint8_t pinNumber;

	};
typedef enum
	{
		PRESSED,
		NOT_PRESSED
	}buttonStatus;
class Button
	{
	public:

		Button(GPIO_TypeDef* port, uint8_t pin, Config config) : mPort(port), mPin(pin)
		{
			if(mPin < 8)
			{
				mPort->CRL = (config << mPin * 4);
			}
			else
			{
				mPort->CRH = (config << (mPin%8) * 4);
			}
		}
		buttonStatus getBtnStatus()
		{

			buttonStatus value = static_cast<buttonStatus>(mPort->IDR & (1<<mPin)); // read pin 4
			return value == PRESSED ? PRESSED : NOT_PRESSED;
		}
	private:
		GPIO_TypeDef* mPort;
		uint8_t mPin;

	};

void waitMs()
	{
		  for(int i =0;i<100000;i++);
	}
int main(void)
	{
		RCC_APB2_Clock_Enable(true, RCC_IOPA_BIT);// Enable clock for GPIOA
		RCC_APB2_Clock_Enable(true, RCC_IOPB_BIT);// Enable clock for GPIOB
		Led led(GPIOA,LED_PIN_NUMBER,Output_mode_push_pull_max_speed_50);
		Button btn(GPIOB,BTN_PIN_NUM, INPUT_Mode_floating_input);
	  while (1)
	  {
		  buttonStatus btnStatus = btn.getBtnStatus();

		  if(btnStatus == PRESSED)
		  {
			  led.ledOn();
			  waitMs();
		  }
		  if(btnStatus == NOT_PRESSED)
		  {

			  led.ledOff();
		  }
	  }

	}


