#include "main.h"

int _write(int file, char *ptr, int len)
{
    int DataIdx;
    for (DataIdx = 0; DataIdx < len; DataIdx++)
    {
        ITM_SendChar(*ptr++);
    }
    return len;
}

void DMA2_Stream0_IRQHandler()
{
    printf("Transfer Complete\n");
    //low flag clear registger
    DMA2->LIFCR |= DMA_LIFCR_CTCIF0;
}
void main()
{
    int i = 0;
    int a[4096];
    int b[4096];
    int c[4096];

   //clock enble
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;
    for (i = 0;i < 4096; i++)
    {
        a[i] = 70000 - i;
    }
    //data transfer direction
    DMA2_Stream0->CR |= DMA_SxCR_DIR_1;
    // memory data si and peripheral data
    DMA2_Stream0->CR |= DMA_SxCR_PSIZE_1 | DMA_SxCR_MSIZE_1;
    // memory incerement and Peripheral increment
    DMA2_Stream0->CR |= DMA_SxCR_PINC|DMA_SxCR_MINC;
    //peripheral addrs
    DMA2_Stream0->PAR   =  a;
    // memory ADDRS
    DMA2_Stream0->M0AR  =  b;
    //nubr of data items tranfer
    DMA2_Stream0->NDTR  =  4096;
    //tranfer complte interuupt enable
    DMA2_Stream0->CR |= DMA_SxCR_TCIE;
    //interrupt
    HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
    //data trnfer direction enable
    DMA2_Stream0->CR |= DMA_SxCR_EN;
    while (1);
}
