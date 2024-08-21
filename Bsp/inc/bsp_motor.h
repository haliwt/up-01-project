#ifndef __BSP_MOTOR_H
#define __BSP_MOTOR_H
#include "main.h"





#define A_ON            do{MO_STEP_1_GPIO_Port ->BSRR |= MO_STEP_1_Pin;}while(0)// HAL_GPIO_WritePin(ULN2003_GPIO_PORT,MO_STEP_1_Pin,GPIO_PIN_SET)
#define A_OFF           do{MO_STEP_1_GPIO_Port ->BRR = MO_STEP_1_Pin;}while(0)//HAL_GPIO_WritePin(ULN2003_GPIO_PORT,MO_STEP_1_Pin,GPIO_PIN_RESET)

#define B_ON             do{MO_STEP_2_GPIO_Port ->BSRR |= MO_STEP_2_Pin;}while(0)//HAL_GPIO_WritePin(ULN2003_GPIO_PORT,MO_STEP_2_Pin,GPIO_PIN_SET)
#define B_OFF            do{MO_STEP_2_GPIO_Port ->BRR = MO_STEP_2_Pin;}while(0) //HAL_GPIO_WritePin(ULN2003_GPIO_PORT,MO_STEP_2_Pin,GPIO_PIN_RESET)

#define C_ON              do{MO_STEP_3_GPIO_Port ->BSRR |= MO_STEP_3_Pin;}while(0) //HAL_GPIO_WritePin(ULN2003_GPIO_PORT,MO_STEP_3_Pin,GPIO_PIN_SET)
#define C_OFF             do{MO_STEP_3_GPIO_Port ->BRR = MO_STEP_3_Pin;}while(0) // HAL_GPIO_WritePin(ULN2003_GPIO_PORT,MO_STEP_3_Pin,GPIO_PIN_RESET)

#define D_ON               do{MO_STEP_4_GPIO_Port ->BSRR |= MO_STEP_4_Pin;}while(0)//HAL_GPIO_WritePin(ULN2003_GPIO_PORT,MO_STEP_4_Pin,GPIO_PIN_SET)
#define D_OFF              do{MO_STEP_4_GPIO_Port ->BRR  = MO_STEP_4_Pin;}while(0)//HAL_GPIO_WritePin(ULN2003_GPIO_PORT,MO_STEP_4_Pin,GPIO_PIN_RESET)





void step_motor_rotation_handler(uint8_t direction);

void motor_stop_fun(void);


#endif 

