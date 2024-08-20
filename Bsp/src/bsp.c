#include "bsp.h"

Process_T gpro_t;



static void status_0(void);
//static void status_1(void);
static void status_2(void);


//uint8_t g_MainStatus = 0;	/* 状态机 */

uint8_t g_recoder_times = 0;

//uint8_t  led_no_state_1 ;
uint8_t led_no_state_2 ;




/*******************************************************************************************************
*	函 数 名: bsp_Idle
*	功能说明: 空闲时执行的函数。一般主程序在for和while循环程序体中需要插入 CPU_IDLE() 宏来调用本函数。
*			 本函数缺省为空操作。用户可以添加喂狗、设置CPU进入休眠模式的功能。
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************/

void waterfall_light_handler(void)
{

    switch (gpro_t.g_MainStatus)
    {
    case 0:         /* 上电执行一次。LED1闪烁3次，每次间隔1秒。3次后状态机返回。*/
        status_0(); 
        //g_MainStatus = 1;   /* 转移到状态1 */
    break;

//    case 1:         /* LED1 - LED4 依次流水显示。每次点亮1个LED。状态持续5秒后返回。 */
//        status_1();     
//      //  g_MainStatus = 2;   /* 转移到状态2 */
//    break;

    case 2:
        status_2(); /* LED1 - LED4 依次流水显示。每次点亮3个LED, 熄灭1个。状态持续5秒后返回。*/
      //  g_MainStatus = 1;   /* 转移到状态1 */
    break;
    } 

    //red_led_active_record_fun(record_eight_minutes_times_flag);

   

}

/*
*********************************************************************************************************
*	函 数 名: status_0
*	功能说明: 状态0  上电执行一次。LED1闪烁3次，每次间隔1秒。3次后状态机返回。
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
static void status_0(void)
{
        /* 检查定时器2时间是否到 */
		if(gpro_t.gTimer_led_color_switch_time > 2)
		{
			/* 3秒定时到后退出本状态 */
               rgb_led_all_off();
               g_recoder_times++ ;
               gpro_t.works_time_out_flag =0;
               gpro_t.record_eight_minutes_times_flag=0;
              gpro_t.g_MainStatus = 2;
            
            // xTimerStart_1_Fun();
			
		}
        else
           red_led_all_on();
	
	
}


uint8_t  bsp_CheckTimer_2(uint8_t times)
{

     return times;

}


/**********************************************************************************************************
*	函 数 名: status_2
*	功能说明: 状态2.  LED1 - LED5 依次流水显示。每次点亮3个LED, 熄灭1个。状态持续5秒后返回。
*	形    参：无
*	返 回 值: 无
**********************************************************************************************************/
static void status_2(void)
{
   		/* LED指示灯序号 1-5 */
   static uint8_t state_0 =0xff;

   if(state_0 != g_recoder_times  ){

      state_0 = g_recoder_times;

     xTimerStart_1_Fun();//bsp_StartTimer(0, 5000);		    /* 定时器0是5000ms 单次定时器 */

	led_no_state_2 = 1;

    }
			
		//bsp_Idle();		/* CPU空闲时执行的函数，在 bsp.c */
		
		/* 这个地方可以插入其他任务 */		
		
		/* 检查定时器0时间是否到 */
        if(gpro_t.works_time_out_flag ==0){
		if(gpro_t.timer_1_time_out_flag == 1)
		{
            gpro_t.timer_1_time_out_flag = 0 ;
            //g_recoder_times ++;
            xTimerStart_1_Fun();
           
            gpro_t.record_eight_minutes_times_flag++;
           
        }
        
        if(gpro_t.timer_2_time_out_flag ==1 && gpro_t.works_time_out_flag ==0)		/* 检查自动定时器2，间隔200ms翻转一次LED1 */
		{
            gpro_t.timer_2_time_out_flag =0;
           /* 先打开所有的LED，然后在关闭其中一个 */
		
            if(gpro_t.record_eight_minutes_times_flag < 6){

               red_bsp_LedOn(led_no_state_2,gpro_t.record_eight_minutes_times_flag);


            }
            else{

                 gpro_t.works_time_out_flag = 1;
                 gpro_t.key_active_flag = 0;
                  xTimerStop_2_Fun();
                  xTimerStop_1_Fun();
               
                  gpro_t.gTimer_led_color_switch_time = 0;

            }
            #if 0
            else if(gpro_t.record_eight_minutes_times_flag > 5 && gpro_t.record_eight_minutes_times_flag < 11){

                 green_bsp_LedOn(led_no_state_2,gpro_t.record_eight_minutes_times_flag);    /* 点亮其中一个LED */ 


            }
            else if(gpro_t.record_eight_minutes_times_flag > 10   &&   gpro_t.works_time_out_flag ==0){

               blue_bsp_LedOn(led_no_state_2,gpro_t.record_eight_minutes_times_flag)  ;
               if(gpro_t.works_time_out_flag == 1){

                  gpro_t.works_time_out_flag = 1;
                 gpro_t.key_active_flag = 0;
                  xTimerStop_2_Fun();
                  xTimerStop_1_Fun();
               
                  gpro_t.gTimer_led_color_switch_time = 0;

               }

            }
            #endif 
			
            led_no_state_2++;
            if(led_no_state_2 == 6)
			{
				led_no_state_2 = 1;
                
			}
		}
        
        }
        blue_led_all_on(gpro_t.works_time_out_flag);
                 
        
       
}
	
	




