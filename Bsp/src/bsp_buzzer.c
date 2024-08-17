#include "bsp.h"


void (*buzzer_sound)(void);


static void Buzzer_KeySound(void);


static void Buzzer_KeySound_Off(void);
/*
*********************************************************************************************************
*	Function Name: MODH_Poll
*	Function: ???????. 1ms ?????
*	Input Ref: ?
*	Return Ref: 0 ????? 1????????
*********************************************************************************************************
*/

void Buzzer_Sound_Fun_Init(void)
{

	Buzzer_KeySound_Handler(Buzzer_KeySound);


}


static void Buzzer_KeySound(void)
{

  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
  //HAL_Delay(20);//50 //60
  osDelay(20);
  Buzzer_KeySound_Off();
       
}

static void Buzzer_KeySound_Off(void)
{
  HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_2);
	
}


void Buzzer_KeySound_Handler(void(*sound_handler)(void))
{

   buzzer_sound = sound_handler;

}


