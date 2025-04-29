#ifndef __BSP_CTL_H
#define __BSP_CTL_H
#include "main.h"



#define LED_CTL_OPEN()     do{LED_CTL_GPIO_Port ->BSRR |= LED_CTL_Pin; }while(0)
#define LED_CTL_CLOSE()    do{LED_CTL_GPIO_Port ->BSRR |=(uint32_t)LED_CTL_Pin << 16;}while(0)


typedef enum _led_on_off{

    off,
    on

}led_onoff;

typedef struct _ctl_t{

   uint8_t power_on;

   uint8_t power_off;

   uint8_t green_led[5];
   uint8_t red_led[5];
   uint8_t blue_led[5];

   uint8_t rgb_color_array[11];

   uint8_t motor_run_direction;

   uint8_t gTimer_timer_led_color_changed;

   


}ctl_t;

extern ctl_t gctl_t;

void bsp_ctl_init(void);

void rgb_led_all_off(void);






void red_bsp_LedOn(uint8_t _no,uint8_t flag);


void green_bsp_LedOn(uint8_t _no,uint8_t flag) ; //bsp_LedOn

void blue_bsp_LedOn(uint8_t _no,uint8_t flag)  ;



//blue led 



void red_led_all_on(void);



void blue_led_all_on(uint8_t on_flag);



void LED_CTL_Iinit(void);


#endif 

