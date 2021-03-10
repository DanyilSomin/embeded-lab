#include "stm32f30x.h"
#include "stm32f30x_exti.h"
#include "stm32f30x_gpio.h"
#include "stm32f30x_rcc.h"

#include "blink.h"

void initAll();

int main()
{
    initAll();

    while(1)
    {
    }
}

void initAll()
{
    SysTick_Config(SystemCoreClock / 1000);
    
    // leds
    GPIO_InitTypeDef gpio_led;
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);
    gpio_led.GPIO_Mode = GPIO_Mode_OUT;
    gpio_led.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_15 |
                    GPIO_Pin_11 | GPIO_Pin_14 | GPIO_Pin_12 | GPIO_Pin_13;
    GPIO_Init(GPIOE, &gpio_led);

    EXTI_InitTypeDef EXTI_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    // button
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);

    //Configure Button EXTI line
    EXTI_InitStructure.EXTI_Line = EXTI_Line0;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

    //set priotity
    NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;


    NVIC_Init(&NVIC_InitStructure);
}

void EXTI0_IRQHandler(void)
{
    EXTI_ClearITPendingBit(EXTI_Line0);
    static uint16_t current = 0;
    GPIO_ResetBits(GPIOE, UINT16_MAX);
    current = getNextPins();
    GPIO_SetBits(GPIOE, current);
    
}

// #include "stm32f30x.h"
// #include "stm32f30x_exti.h"
// #include "stm32f30x_gpio.h"
// #include "stm32f30x_rcc.h"

// #include "blink.h"

// void initAll();

// int main()
// {
//     initAll();

//     while(1)
//     {
//     }
// }

// void initAll()
// {
//     SysTick_Config(SystemCoreClock / 1000);
    
//     // leds
//     GPIO_InitTypeDef gpio_led;
//     RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);
//     gpio_led.GPIO_Mode = GPIO_Mode_OUT;
//     gpio_led.GPIO_Pin = GPIO_Pin_8;
//     GPIO_Init(GPIOE, &gpio_led);

//     EXTI_InitTypeDef EXTI_InitStructure;
//     NVIC_InitTypeDef NVIC_InitStructure;
//     GPIO_InitTypeDef GPIO_InitStructure;

//     // button
//     GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
//     GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
//     GPIO_Init(GPIOA, &GPIO_InitStructure);

//     SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);

//     //Configure Button EXTI line
//     EXTI_InitStructure.EXTI_Line = EXTI_Line0;
//     EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//     EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
//     EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//     EXTI_Init(&EXTI_InitStructure);

//     //set priotity
//     NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
//     NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
//     NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
//     NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;


//     NVIC_Init(&NVIC_InitStructure);
// }

// void EXTI0_IRQHandler(void)
// {
//     EXTI_ClearITPendingBit(EXTI_Line0);

//     static int on = 0;

//     if (!on)
//     {
//         GPIO_SetBits(GPIOE, GPIO_Pin_8);    
//     }
//     else
//     {
//         GPIO_ResetBits(GPIOE, GPIO_Pin_8);
//     }

//     on = !on;
// }