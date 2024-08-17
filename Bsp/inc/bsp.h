#ifndef __BSP_H
#define __BSP_H
#include <stdio.h>
#include <stdlib.h>

#include "main.h"

#include "gpio.h"
#include "bsp_freertos.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "bsp_motor.h"
#include "bsp_led_list.h"
#include "bsp_buzzer.h"
#include "bsp_timer.h"
#include "bsp_ctl.h"
#include "interrupt_manager.h"
#include "bsp_freertos.h"

#include "tim.h"
#include "adc.h"

#include "FreeRTOS.h"
#include "task.h"



/* 定义 BSP 版本号 */
#define __STM32G030_BSP_VERSION	  	"1.0"

/* CPU空闲时执行的函数 */
//#define CPU_IDLE()		bsp_Idle()

#define  USE_FreeRTOS      1

#if USE_FreeRTOS == 1
	#include "FreeRTOS.h"
	#include "task.h"
	#define DISABLE_INT()    taskENTER_CRITICAL()
	#define ENABLE_INT()     taskEXIT_CRITICAL()
#else
	/* 开关全局中断的宏 */
	#define ENABLE_INT()	__set_PRIMASK(0)	/* 使能全局中断 */
	#define DISABLE_INT()	__set_PRIMASK(1)	/* 禁止全局中断 */
#endif

typedef struct _bsp_process{

     uint8_t  timer_1_time_out_flag ;
     uint8_t timer_2_flag;



}Process_T;


extern Process_T gpro_t;




void bsp_init(void);

void waterfall_light_handler(void);

uint8_t  bsp_CheckTimer_1(uint8_t times);

uint8_t  bsp_CheckTimer_2(uint8_t times);



#endif 
