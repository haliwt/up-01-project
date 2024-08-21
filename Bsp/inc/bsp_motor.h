#ifndef __BSP_MOTOR_H
#define __BSP_MOTOR_H
#include "main.h"


#define ULN2003_GPIO_PORT    GPIOA


#define A_ON                             HAL_GPIO_WritePin(ULN2003_GPIO_PORT,MO_STEP_1_Pin,GPIO_PIN_SET)
#define A_OFF                            HAL_GPIO_WritePin(ULN2003_GPIO_PORT,MO_STEP_1_Pin,GPIO_PIN_RESET)

#define B_ON                             HAL_GPIO_WritePin(ULN2003_GPIO_PORT,MO_STEP_2_Pin,GPIO_PIN_SET)
#define B_OFF                            HAL_GPIO_WritePin(ULN2003_GPIO_PORT,MO_STEP_2_Pin,GPIO_PIN_RESET)

#define C_ON                             HAL_GPIO_WritePin(ULN2003_GPIO_PORT,MO_STEP_3_Pin,GPIO_PIN_SET)
#define C_OFF                            HAL_GPIO_WritePin(ULN2003_GPIO_PORT,MO_STEP_3_Pin,GPIO_PIN_RESET)

#define D_ON                             HAL_GPIO_WritePin(ULN2003_GPIO_PORT,MO_STEP_4_Pin,GPIO_PIN_SET)
#define D_OFF                            HAL_GPIO_WritePin(ULN2003_GPIO_PORT,MO_STEP_4_Pin,GPIO_PIN_RESET)





void step_motor_rotation_handler(uint8_t step,uint8_t direction);

void motor_stop_fun(void);


#endif 

