#include "bsp.h"

Process_T gpro_t;


uint8_t g_MainStatus = 0;	/* 状态机 */

uint8_t g_recoder_times = 0;

static void status_0(void);
static void status_1(void);
static void status_2(void);




uint8_t  bsp_CheckTimer_1(uint8_t times)
{
      return times ;

}

uint8_t  bsp_CheckTimer_2(uint8_t times)
{
      return times ;

}


/**********************************************************************************************************
*	函 数 名: bsp_RunPer10ms
*	功能说明: 该函数每隔10ms被Systick中断调用1次。详见 bsp_timer.c的定时中断服务程序。一些处理时间要求不严格的
*			任务可以放在此函数。比如：按键扫描、蜂鸣器鸣叫控制等。
*	形    参：无
*	返 回 值: 无
**********************************************************************************************************/
void bsp_RunPer10ms(void)
{
	;
}

/**********************************************************************************************************
*	函 数 名: bsp_RunPer1ms
*	功能说明: 该函数每隔1ms被Systick中断调用1次。详见 bsp_timer.c的定时中断服务程序。一些需要周期性处理的事务
*			 可以放在此函数。比如：触摸坐标扫描。
*	形    参: 无
*	返 回 值: 无
**********************************************************************************************************/
void bsp_RunPer1ms(void)
{
	;
}

/**********************************************************************************************************
*	函 数 名: bsp_Idle
*	功能说明: 空闲时执行的函数。一般主程序在for和while循环程序体中需要插入 CPU_IDLE() 宏来调用本函数。
*			 本函数缺省为空操作。用户可以添加喂狗、设置CPU进入休眠模式的功能。
*	形    参：无
*	返 回 值: 无
**********************************************************************************************************/
void bsp_Idle(void)
{
	/* --- 喂狗 */

	/* --- 让CPU进入休眠，由Systick定时中断唤醒或者其他中断唤醒 */

	/* 例如 emWin 图形库，可以插入图形库需要的轮询函数 */
	//GUI_Exec();

	/* 例如 uIP 协议，可以插入uip轮询函数 */


}


/*******************************************************************************************************
*	函 数 名: bsp_Idle
*	功能说明: 空闲时执行的函数。一般主程序在for和while循环程序体中需要插入 CPU_IDLE() 宏来调用本函数。
*			 本函数缺省为空操作。用户可以添加喂狗、设置CPU进入休眠模式的功能。
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************/

void waterfall_light_handler(void)
{

    switch (g_MainStatus)
    {
    case 0:         /* 上电执行一次。LED1闪烁3次，每次间隔1秒。3次后状态机返回。*/
        status_0(); 
        g_MainStatus = 1;   /* 转移到状态1 */
    break;

    case 1:         /* LED1 - LED4 依次流水显示。每次点亮1个LED。状态持续5秒后返回。 */
        status_1();     
        g_MainStatus = 2;   /* 转移到状态2 */
    break;

    case 2:
        status_2(); /* LED1 - LED4 依次流水显示。每次点亮3个LED, 熄灭1个。状态持续5秒后返回。*/
        g_MainStatus = 1;   /* 转移到状态1 */
    break;
    }   



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
   static uint8_t state_0 = 0xff;

   if(state_0 != g_recoder_times  ){

      state_0 = g_recoder_times;

    /* 关闭LED */
	bsp_LedOff(1);
	bsp_LedOff(2);
	bsp_LedOff(3);
	bsp_LedOff(4);
	bsp_LedOff(5);
	/* 点亮 LED1 */
	bsp_LedOn(1);


    }

    
	//bsp_StartTimer(0, 3000);		/* 定时器0是3000ms 单次定时器 */		
	//bsp_StartAutoTimer(1, 500);		/* 定时器1是500ms 自动重装定时器, 控制LED1按1Hz频率翻转闪烁 */
	
				
		//bsp_Idle();		/* CPU空闲时执行的函数，在 bsp.c */
		
		/* 这个地方可以插入其他任务 */		
		
		/* bsp_CheckTimer()检查定时器1时间是否到。函数形参表示软件定时器的ID, 值域0 - 3 */
		if(bsp_CheckTimer_1(gpro_t.timer_1_time_out_flag))	 //100ms 	
		{ 
            gpro_t.timer_1_time_out_flag=0;
            bsp_LedToggle(1);		/* 间隔100ms 翻转一次 LED1 */
            g_recoder_times ++;
            g_MainStatus = 1;
		}
		/* 检查定时器2时间是否到 */
		else if (bsp_CheckTimer_2(gpro_t.timer_2_flag))
		{
			/* 3秒定时到后退出本状态 */
			
		}
  
	
	/* 任务结束时，应该关闭定时器，因为他们会占用后台的资源 */
	//bsp_StopTimer(0);	 单次定时器如果超时到过一次后，可以不必关闭
	//bsp_StopTimer(1);
}

/*
*********************************************************************************************************
*	函 数 名: status_1
*	功能说明: 状态1。 LED1 - LED5 依次流水显示。每次点亮1个LED。状态持续5秒后返回。
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
static void status_1(void)
{
   uint8_t  led_no ;

   static uint8_t state_1 = 0xff;

   if(state_1 != g_recoder_times  ){

      state_1 = g_recoder_times;

   led_no = 1;		/* LED指示灯序号 1-5 */
	
	xTimerStart_1_Fun();//bsp_StartTimer(0, 5000);		/* 定时器0是5000ms 单次定时器 */
	//bsp_StartAutoTimer(1, 200);		/* 定时器1是500ms 自动重装定时器, 控制LED1按1Hz频率翻转闪烁 */
	bsp_LedOn(1); //led_1 is on
	
     }

		//bsp_Idle();		/* CPU空闲时执行的函数，在 bsp.c */
		
		/* 这个地方可以插入其他任务 */		
		
		/* 检查定时器0时间是否到 */
		if (gpro_t.timer_1_time_out_flag == 1)
		{
            gpro_t.timer_1_time_out_flag =0;
            g_recoder_times ++;
            g_MainStatus =2;
		}
        else if(gpro_t.timer_2_flag == 1)		/* 检查自动定时器2，间隔200ms翻转一次LED1 */
		{
            gpro_t.timer_2_flag =0;
           /* 先关闭所有的LED，然后在打开其中一个 */
			bsp_LedOff(1);
			bsp_LedOff(2);
			bsp_LedOff(3);
			bsp_LedOff(4);
            bsp_LedOff(5);
			
			if (++led_no == 6)
			{
				led_no = 1;
			}

			bsp_LedOn(led_no);	/* 点亮其中一个LED */	
		}	

 }

	/* 任务结束时，应该关闭定时器，因为他们会占用后台的资源 */
	//bsp_StopTimer(0);	 单次定时器如果超时到过一次后，可以不必关闭
	//bsp_StopTimer(1);


/*
*********************************************************************************************************
*	函 数 名: status_2
*	功能说明: 状态2.  LED1 - LED5 依次流水显示。每次点亮3个LED, 熄灭1个。状态持续5秒后返回。
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
static void status_2(void)
{
    uint8_t led_no ;		/* LED指示灯序号 1-5 */


   static uint8_t state_0 = 0xff;

   if(state_0 != g_recoder_times  ){

      state_0 = g_recoder_times;

     xTimerStart_1_Fun();//bsp_StartTimer(0, 5000);		    /* 定时器0是5000ms 单次定时器 */
	//bsp_StartAutoTimer(1, 200);		/* 定时器1是500ms 自动重装定时器, 控制LED1按1Hz频率翻转闪烁 */
   
	bsp_LedOn(1);
	led_no = 1;

    }
			
		//bsp_Idle();		/* CPU空闲时执行的函数，在 bsp.c */
		
		/* 这个地方可以插入其他任务 */		
		
		/* 检查定时器0时间是否到 */
		if (gpro_t.timer_1_time_out_flag == 1)
		{
            gpro_t.timer_1_time_out_flag = 0 ;
              g_recoder_times ++;
            g_MainStatus = 1;
		}
        else if(gpro_t.timer_2_flag ==1)		/* 检查自动定时器2，间隔200ms翻转一次LED1 */
		{
            gpro_t.timer_2_flag =0;
           /* 先打开所有的LED，然后在关闭其中一个 */
			bsp_LedOn(1);
			bsp_LedOn(2);
			bsp_LedOn(3);
			bsp_LedOn(4);
            bsp_LedOn(5);
			
			if (++led_no == 6)
			{
				led_no = 1;
			}

			bsp_LedOff(led_no);	/* 点亮其中一个LED */			
		}		
}
	
	/* 任务结束时，应该关闭定时器，因为他们会占用后台的资源 */
	//bsp_StopTimer(0);	 单次定时器如果超时过一次后，可以不必执行stop函数
	




