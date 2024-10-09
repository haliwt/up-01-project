#include "interrupt_manager.h"
#include "bsp.h"

uint8_t color_flag;


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
  static uint8_t tm1,tm2,tm20;
  
  
    
   if(htim->Instance==TIM17){
    
    tm0++;  //1ms
    
   
   if(tm0>999){ //1000 *1ms = 1000ms = 1s
		tm0=0;
        tm1++;
  
      
        gpro_t.gTimer_detecte_fan_adc++;
        gpro_t.gTimer_detecte_motor_adc++;
        gpro_t.gTimer_motor_run_time++ ;
      // SysTick_ISR(); //WT.EDIT 2024.08.14
        //main process timer
	
	    //be used to timer 
	    if(tm1> 59){ //1 mintue
            tm1=0;
            tm2++;
           if(tm2 > 3){
            
            gctl_t.gTimer_timer_led_color_changed ++ ;

           if(gpro_t.works_time_out_flag  ==1 &&  gctl_t.gTimer_timer_led_color_changed > 0){
                 gctl_t.gTimer_timer_led_color_changed =0;
                 color_flag++;
           
                 if(color_flag  == 1){
                    gctl_t.red_led[0] = 0;
                    gctl_t.green_led[0] = 1;
                 }
                 else if(color_flag  == 2){
                     gctl_t.red_led[1] = 0;
                    gctl_t.green_led[1] = 1;

                  }
                 else if(color_flag  == 3){
                     gctl_t.red_led[2] = 0;
                    gctl_t.green_led[2] = 1;
                  }
                 else if(color_flag  == 4){
                     gctl_t.red_led[3] = 0;
                    gctl_t.green_led[3] = 1;
                 }
                 else if(color_flag  == 5){
                     gctl_t.red_led[4] = 0;
                    gctl_t.green_led[4] = 1;

                  }
                 else if(color_flag == 6){
                    gctl_t.green_led[0] = 0;
                    gctl_t.red_led[0] = 1;
                  }
                 else if(color_flag  == 7){
                    gctl_t.green_led[1] = 0;
                    gctl_t.red_led[1] = 1;

                   }
                 else if(color_flag  == 8){
                    gctl_t.green_led[2] = 0;
                    gctl_t.red_led[2] = 1;
                 }
                 else if(color_flag  == 9){
                    gctl_t.green_led[3] = 0;
                    gctl_t.red_led[3] = 1;
                 }
                 else if(color_flag  == 10){
                    gctl_t.green_led[4] = 0;
                    gctl_t.red_led[4] = 1;
                 }
                
                 if(color_flag == 10){
                    color_flag = 0;
                     gpro_t.works_time_out_flag  =0; //over interval time restart works motor and fan.
                     gpro_t.motor_stop_run_flag = 0;
                     gpro_t.gTimer_motor_run_time =0;

                  }

            }
                    
           }
            

        }
	 
	}
  }
  else if(htim->Instance==TIM16){

    tm20++;
    if(tm20 > 4){
        tm20= 0;
      if(gpro_t.gpower_on == power_on && gpro_t.motor_stop_run_flag ==0){
          step_motor_rotation_handler(gctl_t.motor_run_direction);

        }

    }


   }
}







