#include "bsp.h"
#include "FreeRTOS.h"
#include "task.h"

#include "cmsis_os.h"



/***********************************************************************************************************
											宏定义
***********************************************************************************************************/
#define POWER_KEY_0	        (1 << 0)


/***********************************************************************************************************
											函数声明
***********************************************************************************************************/
//static void vTaskLedPro(void *pvParameters);
static void vTaskMsgPro(void *pvParameters);
static void vTaskStart(void *pvParameters);
static void AppTaskCreate (void);
static void AppObjCreate (void);
static void vTimer1Callback(xTimerHandle pxTimer);
static void vTimer2Callback(xTimerHandle pxTimer);



/***********************************************************************************************************
											变量声明
***********************************************************************************************************/

//static TaskHandle_t xHandleTaskLedPro = NULL;

static TaskHandle_t xHandleTaskMsgPro = NULL;
static TaskHandle_t xHandleTaskStart = NULL;
//static TimerHandle_t xTimers[2] = {NULL};

static TimerHandle_t           Timer1Timer_Handler;/* 定时器1句柄 */
static TimerHandle_t           Timer2Timer_Handler;/* 定时器2句柄 */


uint8_t creat_timer_success; 
volatile uint8_t power_onoff_sound;
uint8_t power_off_flag;
              



/**********************************************************************************************************
*	函 数 名: main
*	功能说明: 标准c程序入口。
*	形    参：无
*	返 回 值: 无
**********************************************************************************************************/
void freeRTOS_Handler(void)
{
	/* 创建任务 */
	AppTaskCreate();

	/* 创建任务通信机制 */
	AppObjCreate();
	
    /* 启动调度，开始执行任务 */
    vTaskStartScheduler();
}

/**********************************************************************************************************
*	函 数 名: static void vTaskLedPro(void *pvParameters)
*	功能说明: 使用函数xTaskNotifyWait接收任务vTaskTaskUserIF发送的事件标志位设置
*	形    参: pvParameters 是在创建该任务时传递的形参
*	返 回 值: 无
*   优 先 级: 2  
**********************************************************************************************************/
//static void vTaskLedPro(void *pvParameters)
//{
//
//    while(1)
//    {
//
//     if(gpro_t.gpower_on == power_on ){
//        
//        blue_led_all_on(gpro_t.works_time_out_flag);
//     }
//      vTaskDelay(10);
//
//    }
//
//}


/*
*********************************************************************************************************
*	函 数 名: vTaskMsgPro
*	功能说明: 使用函数xTaskNotifyWait接收任务vTaskTaskUserIF发送的事件标志位设置
*	形    参: pvParameters 是在创建该任务时传递的形参
*	返 回 值: 无
*   优 先 级: 2  
*********************************************************************************************************
*/
static void vTaskMsgPro(void *pvParameters)
{
    BaseType_t xResult;
	const TickType_t xMaxBlockTime = pdMS_TO_TICKS(20); /* 设置最大等待时间为50ms */
	uint32_t ulValue;
    static uint8_t dc_power_sound_flag;
    while(1)
    {
		/*
			第一个参数 ulBitsToClearOnEntry的作用（函数执行前）：
		          ulNotifiedValue &= ~ulBitsToClearOnEntry
		          简单的说就是参数ulBitsToClearOnEntry那个位是1，那么notification value
		          的那个位就会被清零。

		          这里ulBitsToClearOnEntry = 0x00000000就是函数执行前保留所有位。
		
		    第二个参数 ulBitsToClearOnExit的作用（函数退出前）：			
				  ulNotifiedValue &= ~ulBitsToClearOnExit
		          简单的说就是参数ulBitsToClearOnEntry那个位是1，那么notification value
		          的那个位就会被清零。

				  这里ulBitsToClearOnExi = 0xFFFFFFFF就是函数退出前清楚所有位。
		
		    注：ulNotifiedValue表示任务vTaskMsgPro的任务控制块里面的变量。		
		*/

 
		
	  xResult = xTaskNotifyWait(0x00000000,      
						          0xFFFFFFFF,      
						          &ulValue,        /* 保存ulNotifiedValue到变量ulValue中 */
						          xMaxBlockTime);  /* 最大允许延迟时间 */
		
		if( xResult == pdPASS )
		{
			/* 接收到消息，检测那个位被按下 */
             
			if((ulValue & POWER_KEY_0) != 0){

                 power_onoff_sound =1;
                
            }
           
      }
	  else{

          if(dc_power_sound_flag==0){
             dc_power_sound_flag++;
             buzzer_sound();
      
          }

            if(power_onoff_sound ==1){
                 power_onoff_sound++;
                 buzzer_sound();
               
            }
            
           if(power_onoff_sound==2){
               power_onoff_sound++ ; 
           
            if(gpro_t.gpower_on == power_off){
                gpro_t.gpower_on = power_on;
                gpro_t.gTimer_power_on_disp=0;
                
              }
             else{
                  gpro_t.gTimer_power_on_disp =10;
                  gpro_t.gpower_on = power_off;
                  power_off_flag = 1;
               }
            
          }
         if(gpro_t.gpower_on == power_on ){
            waterfall_light_handler();
            fan_works_handler(gpro_t.works_time_out_flag);
           #if 0
            if(gpro_t.gTimer_detecte_fan_adc > 2){
                gpro_t.gTimer_detecte_fan_adc=0;
                Get_Fan_ADC_Fun(0,5); //ADC_CHANNEL_0 

             }

            if(gpro_t.gTimer_detecte_motor_adc > 3){
                gpro_t.gTimer_detecte_motor_adc=0;
                Get_Motor_ADC_Fun(1, 5); //ADC_CHANNEL_1 
            }
            #endif 

          }
          else if(gpro_t.gpower_on == power_off ){

              
              rgb_led_all_off();
                         
              rgb_led_all_gpio_set_output(0);
              fan_stop_fun();

              if(power_off_flag ==1){
                  power_off_flag ++;
                
                    gpro_t.works_time_out_flag =0;
                   gpro_t.record_eight_minutes_times_flag=0;
                  xTimerStop((TimerHandle_t  )Timer1Timer_Handler,    /* 待停止的定时器句柄 */
                                (TickType_t     )0);        /* 等待系统停止定时器的最大时间 */

                  xTimerStop((TimerHandle_t  )Timer2Timer_Handler,    /* 待停止的定时器句柄 */
                                  (TickType_t     )0);        /* 等待系统停止定时器的最大时间 */

                  rgb_led_all_off();

               }
             gpro_t.g_MainStatus = 0;
             gpro_t.gTimer_have_a_rest_time =0;

          
          }

          blue_led_all_on(gpro_t.works_time_out_flag);
          #if 1
           if(gpro_t.gTimer_detecte_fan_adc > 2){
                gpro_t.gTimer_detecte_fan_adc=0;
                Get_Fan_ADC_Fun(0,5); //ADC_CHANNEL_0 

             }

            if(gpro_t.gTimer_detecte_motor_adc > 3){
                gpro_t.gTimer_detecte_motor_adc=0;
                Get_Motor_ADC_Fun(1, 5); //ADC_CHANNEL_1 
            }
          #endif 
          motor_run_hander();
      }
             
    }
      
 }
/**********************************************************************************************************
*	函 数 名: vTaskStart
*	功能说明: 启动任务，也就是最高优先级任务，这里用作按键扫描。
*	形    参: pvParameters 是在创建该任务时传递的形参
*	返 回 值: 无
*   优 先 级: 3  
**********************************************************************************************************/
static void vTaskStart(void *pvParameters)
{
   //BaseType_t xResult;
   ///const TickType_t xMaxBlockTime = pdMS_TO_TICKS(50); /* 设置最大等待时间为500ms */

 
    while(1)
    {
		/* 按键扫描 */
		//bsp_KeyScan();
    if(KEY_POWER_VALUE()  == KEY_DOWN){
          gpro_t.key_active_flag ++ ;
          xTaskNotify(xHandleTaskMsgPro, /* 目标任务 */
					 POWER_KEY_0,            /* 设置目标任务事件标志位bit0  */
					 eSetBits);          /* 将目标任务的事件标志位与BIT_0进行或操作，  将结果赋值给事件标志位。*/


    }
  
    vTaskDelay(10);
  }
}
/**********************************************************************************************************
*	函 数 名: AppTaskCreate
*	功能说明: 创建应用任务
*	形    参：无
*	返 回 值: 无
**********************************************************************************************************/
static void AppTaskCreate (void)
{

//
//   xTaskCreate( vTaskLedPro,     		/* 任务函数  */
//                 "vTaskLedPro",   		/* 任务名    */
//                 128,             		/* 任务栈大小，单位word，也就是4字节 */
//                 NULL,           		/* 任务参数  */
//                 1,               		/* 任务优先级次子*/
//                 &xHandleTaskLedPro );  /* 任务句柄  */



   xTaskCreate( vTaskMsgPro,     		/* 任务函数  */
                 "vTaskMsgPro",   		/* 任务名    */
                 128,             		/* 任务栈大小，单位word，也就是4字节 */
                 NULL,           		/* 任务参数  */
                 1,               		/* 任务优先级次子*/
                 &xHandleTaskMsgPro );  /* 任务句柄  */
	
	
	xTaskCreate( vTaskStart,     		/* 任务函数  */
                 "vTaskStart",   		/* 任务名    */
                 128,            		/* 任务栈大小，单位word，也就是4字节 */
                 NULL,           		/* 任务参数  */
                 2,              		/* 任务优先级最高*/
                 &xHandleTaskStart );   /* 任务句柄  */
}



/*
*********************************************************************************************************
*	函 数 名: AppObjCreate
*	功能说明: 创建任务通信机制
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
static void AppObjCreate (void)
{
	
	//const TickType_t  xTimerPer[2] = {100, 100}; //100ms
	
	/* 
	  1. 创建定时器，如果在RTOS调度开始前初始化定时器，那么系统启动后才会执行。
	  2. 统一初始化两个定时器，他们使用共同的回调函数，在回调函数中通过定时器ID来区分
	     是那个定时器的时间到。当然，使用不同的回调函数也是没问题的。
	*/
	
		Timer1Timer_Handler = xTimerCreate("Timer",          /* 定时器名字 */
							       (TickType_t ) 30000,    /* 定时器周期,单位时钟节拍  ,定时器超时时间 */
							       pdFALSE, /*一次性定时器*/ //pdTRUE,          /* 周期性 */
							       (void *) 1,      /* 定时器ID */
							       vTimer1Callback); /* 定时器回调函数 */


       Timer2Timer_Handler = xTimerCreate("Timer",          /* 定时器名字 */
                                   (TickType_t )200,    /* 定时器周期,单位时钟节拍  ,定时器超时时间 */
                                   pdTRUE,          /* 周期性 */
                                   (void *) 2,      /* 定时器ID */
                                   vTimer2Callback); /* 定时器回调函数 */

                                   

		if(Timer1Timer_Handler == NULL || Timer2Timer_Handler == NULL)
		{
			/* 没有创建成功，用户可以在这里加入创建失败的处理机制 */
            creat_timer_success = 1;
		}

	
}

/*
*********************************************************************************************************
*	函 数 名: vTimer1Callback
*	功能说明: 定时器回调函数
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
static void vTimer1Callback(xTimerHandle pxTimer)
{
	

   gpro_t.timer_1_time_out_flag=1;
    

	//configASSERT(pxTimer);

	/* 获取那个定时器时间到 */
	//ulTimerID = (uint32_t)pvTimerGetTimerID(pxTimer);
	
	/* 处理定时器1任务 */
	//bsp_CheckTimer_1(gpro_t.timer_1_time_out_flag);
	
	
}

/*
*********************************************************************************************************
*	函 数 名: vTimer2Callback
*	功能说明: 定时器回调函数
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
static void vTimer2Callback(xTimerHandle pxTimer)
{
	gpro_t.timer_2_time_out_flag =1;

	//configASSERT(pxTimer);

	/* 获取那个定时器时间到 */
	//ulTimerID = (uint32_t)pvTimerGetTimerID(pxTimer);
	
	
	
	/* 处理定时器2任务 */
	//bsp_CheckTimer_2(gpro_t.timer_2_time_out_flag);
}



void xTimerStart_1_Fun(void)
{
   	xTimerStart((TimerHandle_t  )Timer1Timer_Handler,   /* 待启动的定时器句柄 */
                 (TickType_t   )60000);        /* 等待系统启动定时器的最大时间 5000ms */


}

void xTimerStart_2_Fun(void)
{
   	xTimerStart((TimerHandle_t  )Timer2Timer_Handler,   /* 待启动的定时器句柄 */
                 (TickType_t   )200);        /* 等待系统启动定时器的最大时间 5000ms */


}


void xTimerStop_2_Fun(void)
{
     xTimerStop((TimerHandle_t  )Timer2Timer_Handler,    /* 待停止的定时器句柄 */
                 (TickType_t     )10);        /* 等待系统停止定时器的最大时间 */

}

void xTimerStop_1_Fun(void)
{
    xTimerStop((TimerHandle_t  )Timer1Timer_Handler,    /* 待停止的定时器句柄 */
                                (TickType_t     )10);        /* 等待系统停止定时器的最大时间 */


}

