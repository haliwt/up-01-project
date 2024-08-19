#ifndef __BSP_LED_H
#define __BSP_LED_H
#include "main.h"


#define GPIO_1_SET_LOW()        do{GPIO_1_GPIO_Port ->BSRR |=(uint32)GPIO_1_Pin << 16;}while(0)
#define GPIO_1_SET_HIGH()       do{GPIO_1_GPIO_Port ->BSRR |= GPIO_1_Pin;}while(0)

#define GPIO_2_SET_LOW()        do{GPIO_2_GPIO_Port ->BSRR |=(uint32)GPIO_2_Pin << 16;}while(0)
#define GPIO_2_SET_HIGH()       do{GPIO_2_GPIO_Port ->BSRR |= GPIO_2_Pin;}while(0)

#define GPIO_3_SET_LOW()        do{GPIO_3_GPIO_Port ->BSRR |=(uint32)GPIO_3_Pin << 16;}while(0)
#define GPIO_3_SET_HIGH()       do{GPIO_3_GPIO_Port ->BSRR |= GPIO_3_Pin;}while(0)


#define GPIO_4_SET_LOW()        do{GPIO_4_GPIO_Port ->BSRR |=(uint32)GPIO_4_Pin << 16;}while(0)
#define GPIO_4_SET_HIGH()        do{GPIO_4_GPIO_Port ->BSRR |= GPIO_4_Pin;}while(0)

#define GPIO_5_SET_LOW()        do{GPIO_5_GPIO_Port ->BSRR |=(uint32)GPIO_5_Pin << 16;}while(0)
#define GPIO_5_SET_HIGH()       do{GPIO_5_GPIO_Port ->BSRR |= GPIO_5_Pin;}while(0)



/* LEDÈ¡·´¶¨Òå */
#define LED5_TOGGLE()   do{GPIO_5_GPIO_Port->ODR ^= GPIO_5_Pin; }while(0)      /* LED0 = !LED0 */

#define LED4_TOGGLE()   do{GPIO_4_GPIO_Port->ODR ^= GPIO_4_Pin; }while(0)      /* LED1 = !LED1 */

#define LED3_TOGGLE()   do{GPIO_3_GPIO_Port->ODR ^= GPIO_3_Pin; }while(0)      /* LED1 = !LED1 */

#define LED2_TOGGLE()   do{GPIO_2_GPIO_Port->ODR ^= GPIO_2_Pin; }while(0)      /* LED1 = !LED1 */




typedef enum _led_state{

    LED_ON,
    LED_OFF,

}led_state;

typedef enum _led_rgb{

    LED_RED,
    LED_GREEN,
    LED_BLUE,

}led_rgb_state;

typedef struct _led_t{

    char    led_name[3];
    uint8_t led_on;
    uint8_t led_off;

    uint8_t led_equal_to_20ms_flag;
    uint8_t led_run_20ms_in_flag;
    uint8_t led_run_20ms_out_flag;

    uint8_t (*rgb_onoff_state)(uint8_t data);
    uint8_t (*rgb_color_state)(uint8_t color);


    uint8_t gTimer_blink_20ms;



}led_t;

extern led_t gled_t;




void LED_Init(void);


void led_rgb_run_handler(void);

uint8_t rgb_onoff_state_fun(uint8_t (*rgb_on_off_handler)(uint8_t data));

uint8_t rgb_color_state_fun(uint8_t(*rgb_color_handler)(uint8_t color));

void charlie_multiplexing_led(void);

void sys_gpio_pin_set(GPIO_TypeDef *p_gpiox, uint16_t pinx, uint8_t status);

uint8_t sys_gpio_pin_get(GPIO_TypeDef *p_gpiox, uint16_t pinx);



void rgb_led_set_input_mode(GPIO_TypeDef  *GPIOx,uint16_t pinx);


void rgb_led_set_output_mode(GPIO_TypeDef  *GPIOx,uint16_t pinx,uint8_t high_low);



void red_bsp_LedOn(uint8_t _no);
void red_bsp_LedOff(uint8_t _no);



void green_bsp_LedOn(uint8_t _no);

void blue_bsp_LedOn(uint8_t _no);



void bsp_LedOff(uint8_t _no);


void bsp_LedToggle(uint8_t _no);

uint8_t bsp_IsLedOn(uint8_t _no);



#endif 

