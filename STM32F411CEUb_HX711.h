
#ifndef STM32F411CEUB_HX711_STM32F411CEUB_HX711_H_
#define STM32F411CEUB_HX711_STM32F411CEUB_HX711_H_

#include <main.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint16_t dout_pin;
    uint16_t clock_pin;
    GPIO_TypeDef *gpio_port;
} HX711;

int32_t HX711_Read(HX711 *DevName);
bool Is_Ready(HX711 *DevName);
void us_Delay (uint32_t us);
uint8_t Data_Reader_ShiftIn(HX711 *DevName);

#endif /* STM32F411CEUB_HX711_STM32F411CEUB_HX711_H_ */
