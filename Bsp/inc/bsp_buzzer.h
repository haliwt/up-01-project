#ifndef __BSP_BUZZER_H
#define __BSP_BUZZER_H
#include "main.h"


extern void (*buzzer_sound)(void);

void Buzzer_Sound_Fun_Init(void);



void Buzzer_KeySound_Handler(void(*sound_handler)(void));




void Buzzer_KeySound(void);



#endif 

