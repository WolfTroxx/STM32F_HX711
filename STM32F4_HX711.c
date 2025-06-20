#include "STM32F411CEUb_HX711.h"
#include <stm32f4xx_hal.h>

#define SCK_PIN       GPIO_PIN_6
#define DOUT_PIN         GPIO_PIN_7
#define GPIO_PORT        GPIOC

int32_t HX711_Read() {
    uint8_t DataArr[3];
    int32_t RawData=0;
  if (!Is_Ready()) {
	  DataArr[0]=Data_Reader_ShiftIn(DOUT_PIN, SCK_PIN);
	  DataArr[1]=Data_Reader_ShiftIn(DOUT_PIN, SCK_PIN);
	  DataArr[2]=Data_Reader_ShiftIn(DOUT_PIN, SCK_PIN);
  }
   RawData |= (DataArr[0]<<16)|(DataArr[1]<<8)|DataArr[2];
    return RawData;
}

bool Is_Ready() {
	return (HAL_GPIO_ReadPin(GPIOC, DOUT_PIN)==1); //check if pin is high
}

void us_Delay (uint32_t us) {
	    __HAL_TIM_SET_COUNTER(&htim2,0);
  uint32_t start =__HAL_TIM_GET_COUNTER(&htim2);
  while (__HAL_TIM_GET_COUNTER(&htim2)-start< us);  // check difference
  }

uint8_t Data_Reader_ShiftIn(uint16_t DATA, uint16_t CLOCK) { //data receiver shifter, moves MSB to the left
  uint8_t ByteOut;
  for (int i=0; i<8; i++) {
    HAL_GPIO_WritePin(GPIOC, CLOCK, 1);
    us_Delay(1);
    ByteOut|=HAL_GPIO_ReadPin(GPIOC, DATA)<<(7-i);
    HAL_GPIO_WritePin(GPIOC, CLOCK, 0);
    us_Delay(1);
  }
return ByteOut;
}
uint8_t Data_Reader_ShiftIn(uint16_t DATA, uint16_t CLOCK) { //data receiver shifter, moves MSB to the left
  uint8_t ByteOut;
  for (int i=0; i<8; i++) {
    HAL_GPIO_WritePin(GPIOC, CLOCK, 1);
    us_Delay(1);
    ByteOut|=HAL_GPIO_ReadPin(GPIOC, DATA)<<(7-i);
    HAL_GPIO_WritePin(GPIOC, CLOCK, 0);
  }
return ByteOut;
} 
