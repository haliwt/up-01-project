#ifndef __BSP_CTL_H
#define __BSP_CTL_H
#include "main.h"

typedef struct _ctl_t{

   uint8_t power_on;

   uint8_t power_off;


}ctl_t;

extern ctl_t gctl_t;

void bsp_ctl_init(void);



#endif 

