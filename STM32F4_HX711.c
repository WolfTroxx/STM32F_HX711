#include "STM32F411CEUb_HX711.h"
#include <stm32f4xx_hal.h>

void HX711_Initialize(HX711 *DevName, uint16_t DOUT_PIN, uint16_t CLOCK_PIN, GPIO_TypeDef *GPIO_PORT) {
	(*DevName).dout_pin=DOUT_PIN;
	(*DevName).clock_pin=CLOCK_PIN;
	(*DevName).gpio_port=GPIO_PORT;
}

int32_t HX711_Read(HX711 *DevName) {
    uint8_t DataArr[3];
    int32_t RawData=0;
  if (!Is_Ready(DevName)) {
	  DataArr[0]=Data_Reader_ShiftIn(DevName);
	  DataArr[1]=Data_Reader_ShiftIn(DevName);
	  DataArr[2]=Data_Reader_ShiftIn(DevName);
  }
  HAL_GPIO_WritePin(DevName->gpio_port, DevName->clock_pin, 1);
  us_Delay(1);
  HAL_GPIO_WritePin(DevName->gpio_port, DevName->clock_pin, 0);
  us_Delay(1);
   RawData |= (DataArr[0]<<16)|(DataArr[1]<<8)|DataArr[2];
   if (RawData & 0x800000) { //24 bit 2s comlement signing
     RawData |= ~0xFFFFFF;
   }
    return RawData;
}

bool Is_Ready(HX711 *DevName) {
	return (HAL_GPIO_ReadPin(DevName->gpio_port, DevName->clock_pin)==1); //check if pin is high
}

void us_Delay (uint32_t us) {
	    __HAL_TIM_SET_COUNTER(&htim2,0);
  uint32_t start =__HAL_TIM_GET_COUNTER(&htim2);
  while (__HAL_TIM_GET_COUNTER(&htim2)-start< us);  // check difference
  }

uint8_t Data_Reader_ShiftIn(HX711 *DevName) { //data receiver shifter, moves MSB to the left
  uint8_t ByteOut;
  for (int i=0; i<8; i++) {
    HAL_GPIO_WritePin(DevName->gpio_port, DevName->clock_pin , 1);
    us_Delay(1);
    ByteOut|=HAL_GPIO_ReadPin(DevName->gpio_port, DevName->dout_pin)<<(7-i);
    HAL_GPIO_WritePin(DevName->gpio_port, DevName->clock_pin , 0);
    us_Delay(1);
  }
return ByteOut;
}
