#ifndef __BSP_FAN_H
#define __BSP_FAN_H
#include "main.h"


#define FAN_CTL_SetLow()     do{FAN_CTL_GPIO_Port->BSRR |= (uint32_t)FAN_CTL_Pin << 16;}while(0)

#define FAN_CTL_SetHigh()    do{FAN_CTL_GPIO_Port->BSRR |= FAN_CTL_Pin;}while(0)


void fan_output_fun(void);
void fan_stop_fun(void);

#endif 

