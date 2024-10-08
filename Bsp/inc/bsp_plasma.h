#ifndef  __BSP_PLASMA_H
#define  ___BSP_PLASMA_H
#include "main.h"



#define PLASMA_ON()             do{GPIO_PLASMA_Port-> BSRR |= GPIO_PLASMA_Pin;}while(0)
#define PLASMA_OFF()            do{GPIO_PLASMA_Port -> BRR = GPIO_PLASMA_Pin ;}while(0)






#endif 

