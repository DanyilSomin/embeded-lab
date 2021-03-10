#include "usertasks.h"

#include "stm32f30x.h"
#include "stm32f30x_gpio.h"
#include "stm32f30x_rcc.h" 

void taskLed8(void* parameters)
{		
    (void) parameters;
	
    for (;;) 
    {
        GPIO_ResetBits(GPIOE, GPIO_Pin_All);
        GPIO_SetBits(GPIOE, GPIO_Pin_8);
        vTaskDelay(1009);
    }
}

void taskLed9(void* parameters)
{		
    (void) parameters;
	
    for (;;) 
    {
        GPIO_ResetBits(GPIOE, GPIO_Pin_All);
        GPIO_SetBits(GPIOE, GPIO_Pin_9);
        vTaskDelay(1093);
    }
}

void taskLed10(void* parameters)
{		
    (void) parameters;
	
    for (;;) 
    {
        GPIO_ResetBits(GPIOE, GPIO_Pin_All);
        GPIO_SetBits(GPIOE, GPIO_Pin_10);
        vTaskDelay(1249);
    }
}

void taskLed11(void* parameters)
{		
    (void) parameters;
	
    for (;;) 
    {
        GPIO_ResetBits(GPIOE, GPIO_Pin_All);
        GPIO_SetBits(GPIOE, GPIO_Pin_11);
        vTaskDelay(1423);
    }
}

void taskLedOff(void* parameters)
{		
    (void) parameters;
	
    for (;;) 
    {
        GPIO_ResetBits(GPIOE, GPIO_Pin_All);
        vTaskDelay(1693);
    }
}