#include "main.h"
int main(void)
{
	int val;
	HAL_Init();
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	EXTI->RTSR   |= EXIT_RTSR_TR1;
	HAL_NVIC_ENABLE_IRQ(EXTI1_Qn)
 
  	while (1)
  
}
