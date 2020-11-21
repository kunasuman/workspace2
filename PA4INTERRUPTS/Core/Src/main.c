#include "main.h"
#include<stdio.h>

int _write(int file,char *ptr,int len)
{
	int DataIdx;
	for(DataIdx=0;DataIdx<len;DataIdx++)
	{
		ITM_sendchar(*ptr++);
	}
	return len;
}
void EXIT_IRQHandler()
{
	printf("on");
	GPIOA->ODR |=GPIO_ODR_ODR_4;
	EXTI->PR   |=EXTI_PR_PR1;
}

int main (void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER4_0;
	EXTI->IMR    |= EXTI_IMR_MR1;
	EXTI->RTSR   |= EXTI_RTSR_TR1;
	HAL_NVIC_EnableIRQ(EXTI1_IRQn);
	while(1);
}
