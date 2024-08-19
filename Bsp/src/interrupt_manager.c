#include "interrupt_manager.h"
#include "bsp.h"

/*******************************************************************************
	*
	*Function Name:void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
	*Function : timer timing 1ms 
	*           sys_clk = 64MHz
	*
*******************************************************************************/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  static uint16_t tm0;
  static uint8_t tm1;
 

    
   if(htim->Instance==TIM17){
    
    tm0++;  //1ms
    tm1++;
   
   

	if(tm1 > 19){
		tm1=0;
		
     }  
	
	
	if(tm0>999){ //1000 *1ms = 1000ms = 1s
		tm0=0;
        gpro_t.gTimer_led_color_switch_time++ ;
      // SysTick_ISR(); //WT.EDIT 2024.08.14
        //main process timer
	
	    //be used to timer 
	 
	}
  }
}







