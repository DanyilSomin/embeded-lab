#include "blink.h"

#include <array>

extern "C"
{
    #include "stm32f30x_gpio.h"
}

constexpr std::array<uint16_t, 8> pattern = {
    GPIO_Pin_8,
    GPIO_Pin_9,
    GPIO_Pin_10,
    GPIO_Pin_11,
    GPIO_Pin_12,
    GPIO_Pin_13,
    GPIO_Pin_14,
    GPIO_Pin_15,
};

uint16_t getNextPins()
{
    static size_t i = 0;
    if (i >= pattern.size()) { i = 0; }

    return pattern[i++];
}