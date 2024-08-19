#ifndef __BSP_CTL_H
#define __BSP_CTL_H
#include "main.h"


typedef enum _led_on_off{

    off,
    on

}led_onoff;

typedef struct _ctl_t{

   uint8_t power_on;

   uint8_t power_off;


}ctl_t;

extern ctl_t gctl_t;

void bsp_ctl_init(void);

void rgb_led_all_off(void);



//red led
void red_led_1_on(void);

void red_led_2_on(void);

void red_led_3_on(void);

void red_led_4_on(void);

void red_led_5_on(void);
//rgb green led 
//void green_led_1_on(void);

//void green_led_2_on(void);

void green_bsp_LedOn(uint8_t _no) ; //bsp_LedOn

//blue led 
void blue_led_1_on(void);

void blue_led_4_on(void);


void red_led_all_on(void);



#endif 

