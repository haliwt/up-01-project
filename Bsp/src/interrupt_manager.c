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
  static uint16_t tm0,tm160;
  static uint8_t tm1;
 
   if(htim->Instance==TIM16){

       



   }
    
   if(htim->Instance==TIM17){
    
    tm0++;  //1ms
    
   
   if(tm0>999){ //1000 *1ms = 1000ms = 1s
		tm0=0;
        tm1++;
        gpro_t.gTimer_power_on_disp++;
        gpro_t.gTimer_have_a_rest_time++ ;
        gpro_t.gTimer_detecte_fan_adc++;
        gpro_t.gTimer_detecte_motor_adc++;
        gpro_t.gTimer_motor_run_time++ ;
      // SysTick_ISR(); //WT.EDIT 2024.08.14
        //main process timer
	
	    //be used to timer 
	    if(tm1> 59){ //1 mintue
            tm1=0;
            

        }
	 
	}
  }
}







