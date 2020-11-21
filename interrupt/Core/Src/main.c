#include"main.h"
#include<stdio.h>
int _write(int file, char *ptr, int len)
{
    int DataIdx;
    for (DataIdx = 0; DataIdx < len; DataIdx++)
    {

        ITM_SendChar(*ptr++);
    }
    return len;
}
void EXTI1_IRQHandler()
{
	printf("am handler\n");
	EXTI->PR |=EXTI_PR_PR1;
}
int main (void)
{
	RCC->AHB1ENR |=RCC_AHB1ENR_GPIOAEN;
	EXTI->IMR    |=EXTI_IMR_MR1;
	EXTI->RTSR   |=EXTI_RTSR_TR1;
	HAL_NVIC_EnableIRQ(EXTI1_IRQn);
	while(1);
}
