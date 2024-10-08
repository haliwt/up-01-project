#ifndef __BSP_ADC_H
#define __BSP_ADC_H
#include "main.h"

#define ADC_CHANNEL_NUMBER               2

void Get_Fan_ADC_Fun(uint8_t  channel,uint8_t times);

void Get_Motor_ADC_Fun(uint8_t channel,uint8_t times);


extern uint16_t ADC_ConvertedValue[ADC_CHANNEL_NUMBER];


#endif 

