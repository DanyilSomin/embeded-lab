#include "stm32f30x.h"
#include "stm32f30x_gpio.h"
#include "stm32f30x_rcc.h" 

#include "FreeRTOS.h"
#include "task.h" 

#include "usertasks.h"

GPIO_InitTypeDef gpio;

void initAll()
{
    SysTick_Config(SystemCoreClock / 1000);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);
    gpio.GPIO_Mode = GPIO_Mode_OUT;
    gpio.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_8 | GPIO_Pin_10 | GPIO_Pin_15 |
                    GPIO_Pin_11 | GPIO_Pin_14 | GPIO_Pin_12 | GPIO_Pin_13;
    GPIO_Init(GPIOE, &gpio);
}

int main (void)
{
    initAll();

    xTaskCreate( taskLed8, "TaskLed8", configMINIMAL_STACK_SIZE, NULL,
        tskIDLE_PRIORITY + 1, ( xTaskHandle * ) NULL );

    xTaskCreate( taskLed9, "TaskLed9", configMINIMAL_STACK_SIZE, NULL,
        tskIDLE_PRIORITY + 1, ( xTaskHandle * ) NULL );

    xTaskCreate( taskLed10, "TaskLed10", configMINIMAL_STACK_SIZE, NULL,
        tskIDLE_PRIORITY + 1, ( xTaskHandle * ) NULL );

    xTaskCreate( taskLed11, "TaskLed11", configMINIMAL_STACK_SIZE, NULL,
        tskIDLE_PRIORITY + 1, ( xTaskHandle * ) NULL );

    xTaskCreate( taskLedOff, "TaskLedOff", configMINIMAL_STACK_SIZE, NULL,
        tskIDLE_PRIORITY + 1, ( xTaskHandle * ) NULL );

    vTaskStartScheduler();

   //should never get here
   for (;;);
}