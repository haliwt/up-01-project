#include "bsp.h"

ctl_t gctl_t;


//led_onoff led_state;


void bsp_ctl_init(void)
{

    Buzzer_Sound_Fun_Init();


}

void red_led_1_on(void)
{
 
    rgb_led_set_output_mode(GPIO_1_GPIO_Port,GPIO_1_Pin,0);
    rgb_led_set_output_mode(GPIO_2_GPIO_Port,GPIO_2_Pin,1);
   

   rgb_led_set_input_mode(GPIO_3_GPIO_Port,GPIO_3_Pin);
   rgb_led_set_input_mode(GPIO_4_GPIO_Port,GPIO_4_Pin);
   rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);


}





void red_led_2_on(void)
{

  
     rgb_led_set_output_mode(GPIO_1_GPIO_Port,GPIO_1_Pin,1);
     rgb_led_set_output_mode(GPIO_2_GPIO_Port,GPIO_2_Pin,0);
    
 

   rgb_led_set_input_mode(GPIO_3_GPIO_Port,GPIO_3_Pin);
   rgb_led_set_input_mode(GPIO_4_GPIO_Port,GPIO_4_Pin);
   rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);


}



void red_led_3_on(void)
{
 
  rgb_led_set_output_mode(GPIO_3_GPIO_Port,GPIO_3_Pin,1);
  rgb_led_set_output_mode(GPIO_2_GPIO_Port,GPIO_2_Pin,0);
   
   

   rgb_led_set_input_mode(GPIO_1_GPIO_Port,GPIO_1_Pin);
   rgb_led_set_input_mode(GPIO_4_GPIO_Port,GPIO_4_Pin);
   rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);


}

void red_led_4_on(void)
{
 
  
    rgb_led_set_output_mode(GPIO_2_GPIO_Port,GPIO_2_Pin,1);
    rgb_led_set_output_mode(GPIO_3_GPIO_Port,GPIO_3_Pin,0);
   

   rgb_led_set_input_mode(GPIO_1_GPIO_Port,GPIO_1_Pin);
   rgb_led_set_input_mode(GPIO_4_GPIO_Port,GPIO_4_Pin);
   rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);


}

void red_led_5_on(void)
{
 
  
    rgb_led_set_output_mode(GPIO_3_GPIO_Port,GPIO_3_Pin,0);
    rgb_led_set_output_mode(GPIO_4_GPIO_Port,GPIO_4_Pin,1);
     
    
     rgb_led_set_input_mode(GPIO_1_GPIO_Port,GPIO_1_Pin);
     rgb_led_set_input_mode(GPIO_2_GPIO_Port,GPIO_2_Pin);
     rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);
  

}






//rgb blue led 

void blue_led_1_on(void)
{
 
  
    rgb_led_set_output_mode(GPIO_3_GPIO_Port,GPIO_3_Pin,1);
    rgb_led_set_output_mode(GPIO_4_GPIO_Port,GPIO_4_Pin,0);
     
    
     rgb_led_set_input_mode(GPIO_1_GPIO_Port,GPIO_1_Pin);
     rgb_led_set_input_mode(GPIO_2_GPIO_Port,GPIO_2_Pin);
     rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);
}


void blue_led_4_on(void)
{
 
  
    rgb_led_set_output_mode(GPIO_4_GPIO_Port,GPIO_4_Pin,1);
    rgb_led_set_output_mode(GPIO_2_GPIO_Port,GPIO_2_Pin,0);
   

   rgb_led_set_input_mode(GPIO_1_GPIO_Port,GPIO_1_Pin);
   rgb_led_set_input_mode(GPIO_3_GPIO_Port,GPIO_3_Pin);
   rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);


}


/********************************************************************************
*
* Function Name: void red_led_all_on(void)
* Function : 5pcs of grb red led turn on
* Input Ref:NO
* Return Ref:NO
*
********************************************************************************/
void red_led_all_on(void)
{

led_1:   red_led_1_on();
    osDelay(3);
    red_led_2_on();
     osDelay(3);
    red_led_3_on();
     osDelay(3);
    red_led_4_on();
     osDelay(3);
    red_led_5_on();
     osDelay(3);
    if(gpro_t.rgb_red_led_time_out == 1){
        goto led_1;
    }

}

/********************************************************************************
*
* Function Name: 
* Function : 5pcs of grb red led turn on
* Input Ref:NO
* Return Ref:NO
*
********************************************************************************/
void rgb_led_all_off(void)
{
   rgb_led_all_set_input_mode();

}




