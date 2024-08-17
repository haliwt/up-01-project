#ifndef __BSP_KEY_H
#define  __BSP_KEY_H
#include "main.h"

//#define KEY0        sys_gpio_pin_get(KEY0_GPIO_PORT, KEY0_GPIO_PIN)  


#define KEY_POWER_VALUE()      sys_gpio_pin_get(KEY_ID_GPIO_Port,KEY_ID_Pin)  //

typedef enum _key_state{

   KEY_DOWN,
   KEY_UP,

};

#endif 

