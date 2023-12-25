#include"main.h"

#define SET(REG,BIT) REG |= (1<<BIT)
#define READ(reg,bit)	(reg>>bit&1)

enum RCC_APB1_BITS{
	I2C1_CLK_ENABLEN = 21

};

enum RCC_APB2_BITS{
	AF_ENABLE = 0

};
class I2C
{
private:
	I2C_TypeDef *mI2C;
	GPIO_TypeDef * mGPIO;

public:
	I2C(I2C_TypeDef *I2C_Reg, GPIO_TypeDef * GPIO_Reg): mI2C(I2C_Reg), mGPIO(GPIO_Reg)
	{
		/* enable clock of I2C1 */
		SET(RCC->APB1ENR,I2C1_CLK_ENABLEN);

		/* enable clock of AF */
		SET(RCC->APB2ENR,AF_ENABLE);

		/* REMAP TP I2C */
		AFIO->MAPR |= (1<<1);

		/* enable open drain, 50 MHZ to PORT B, PIN 8,9*/
		mGPIO->CRH |= 0x000000ff;

		/* Generate start bit*/
		SET(mI2C->CR1, 8);
		/* Enable for peripheral */
		SET(mI2C->CR1, 0);
		/* I2C Freq Input = 2MHZ */
		mI2C->CR2 = 0x00000002;
	}
	bool confirmTransmission()
	{
		while(READ(mI2C->SR1, 7) == 0);
		return true;
	}

	bool TX_Char(char data)
	{
		mI2C->DR = (uint32_t) data;
		/* blocked until DR is empty */
		return confirmTransmission();
	}

	uint8_t RX_Char()
	{
		/* blocked until DR is not empty */
		while(READ(mI2C->SR1, 6) == 0);

		return (uint8_t) mI2C->DR;
	}

};


int main()
{

	while(1)
	{


	}

}
