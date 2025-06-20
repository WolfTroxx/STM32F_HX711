#ifndef STM32F411CEUB_HX711_STM32F411CEUB_HX711_H_
#define STM32F411CEUB_HX711_STM32F411CEUB_HX711_H_

#include <main.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t dout_pin;
    uint8_t sck_pin;
    uint8_t gain;
    int32_t offset;
    float scale;
} HX711;

int32_t HX711_Read();
bool Is_Ready();
void us_Delay (uint32_t us);
uint8_t Data_Reader_ShiftIn(uint16_t DATA, uint16_t CLOCK);

#endif /* STM32F411CEUB_HX711_STM32F411CEUB_HX711_H_ */
