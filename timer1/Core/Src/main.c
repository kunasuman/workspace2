#include "main.h"
#include<stdio.h>
int _write(int file,char *ptr,int len)
{
	int DataIdx;
	for(DataIdx=0;DataIdx<len;DataIdx++)
	{
		ITM_SendChar(*ptr++);
	}
return len;
}
void TIM2_IRQHandler()
{
	printf("auto relode\n");
	GPIOA->ODR ^= GPIO_ODR_ODR_10;
	TIM2->SR  &= ~TIM_SR_UIF;
}
int main()
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER10_0;
	TIM2->CR1    |= TIM_CR1_CEN;
	TIM2->DIER   |= TIM_DIER_UIE;

	TIM2->CNT     = 0;
	TIM2->ARR     =1000;
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
	while(1);
}
