#include "bsp.h"

ctl_t gctl_t;


//led_onoff led_state;
static void green_led_1_on(void);
static void green_led_2_on(void);
static void green_led_3_on(void);
static void green_led_4_on(void);
static void green_led_5_on(void);

//led blue 
static void blue_led_1_on(void);
static void blue_led_2_on(void);
static void blue_led_3_on(void);
static void blue_led_4_on(void);
static void blue_led_5_on(void);






/********************************************************************************
*
* Function Name: void bsp_ctl_init(void)
* Function : 
* Input Ref:NO
* Return Ref:NO
*
********************************************************************************/
void bsp_ctl_init(void)
{

    Buzzer_Sound_Fun_Init();


}
/********************************************************************************
*
* Function Name:void red_led_1_on(void)
* Function : 
* Input Ref:NO
* Return Ref:NO
*
********************************************************************************/
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

/********************************************************************************
*
* Function Name: vod green_led_1_on(void)
* Function : 5pcs of grb red led turn on
* Input Ref:NO
* Return Ref:NO
*
********************************************************************************/
static void green_led_1_on(void)
{
    
    rgb_led_set_input_mode(GPIO_2_GPIO_Port,GPIO_2_Pin);
    rgb_led_set_input_mode(GPIO_4_GPIO_Port,GPIO_4_Pin);
    rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);


    rgb_led_set_output_mode(GPIO_1_GPIO_Port,GPIO_1_Pin,0);
    rgb_led_set_output_mode(GPIO_3_GPIO_Port,GPIO_3_Pin,1);


    
   


}


static void green_led_2_on(void)
{
    
    rgb_led_set_output_mode(GPIO_1_GPIO_Port,GPIO_1_Pin,1);
    rgb_led_set_output_mode(GPIO_3_GPIO_Port,GPIO_3_Pin,0);
    
    
       
     rgb_led_set_input_mode(GPIO_2_GPIO_Port,GPIO_2_Pin);
     rgb_led_set_input_mode(GPIO_4_GPIO_Port,GPIO_4_Pin);
     rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);


    


}


static void green_led_3_on(void)
{
    
   
    rgb_led_set_input_mode(GPIO_1_GPIO_Port,GPIO_1_Pin);
    rgb_led_set_input_mode(GPIO_2_GPIO_Port,GPIO_2_Pin);
    rgb_led_set_input_mode(GPIO_4_GPIO_Port,GPIO_4_Pin);


    rgb_led_set_output_mode(GPIO_5_GPIO_Port,GPIO_5_Pin,1);
    rgb_led_set_output_mode(GPIO_3_GPIO_Port,GPIO_3_Pin,0);
    
   

}

static void green_led_4_on(void)
{
    
   
    rgb_led_set_input_mode(GPIO_1_GPIO_Port,GPIO_1_Pin);
    rgb_led_set_input_mode(GPIO_2_GPIO_Port,GPIO_2_Pin);
    rgb_led_set_input_mode(GPIO_4_GPIO_Port,GPIO_4_Pin);


    rgb_led_set_output_mode(GPIO_3_GPIO_Port,GPIO_3_Pin,1);
    rgb_led_set_output_mode(GPIO_5_GPIO_Port,GPIO_5_Pin,0);


    

}


static void green_led_5_on(void)
{
    
    rgb_led_set_input_mode(GPIO_2_GPIO_Port,GPIO_2_Pin);
    rgb_led_set_input_mode(GPIO_4_GPIO_Port,GPIO_4_Pin);
    rgb_led_set_input_mode(GPIO_3_GPIO_Port,GPIO_3_Pin);


    rgb_led_set_output_mode(GPIO_1_GPIO_Port,GPIO_1_Pin,0);
    rgb_led_set_output_mode(GPIO_5_GPIO_Port,GPIO_5_Pin,1);
    
}



/**********************************************************************************************************
*	函 数 名: void green_bsp_LedOn(uint8_t _no) 
*	功能说明: 点亮指定的LED指示灯。
*	形    参:  _no : 指示灯序号，范围 1 - 5
*	返 回 值: 无
**********************************************************************************************************/
void green_bsp_LedOn(uint8_t _no)  //bsp_LedOn
{
	//_no--;

	if (_no == 1)
	{
		green_led_1_on();//GPIO_1_GPIO_Port->BRR = GPIO_1_Pin; //BRR ->GPIO output = 0 
	}
	else if (_no == 2)
	{
		green_led_2_on();//GPIO_2_GPIO_Port->BRR = GPIO_2_Pin;
	}
	else if (_no == 3)
	{
		green_led_3_on();//GPIO_3_GPIO_Port->BRR = GPIO_3_Pin;
	}
	else if (_no == 4)
	{
		green_led_4_on();//GPIO_4_GPIO_Port->BRR = GPIO_4_Pin;
	}
    else if(_no == 5)
    {
        green_led_5_on();//GPIO_5_GPIO_Port->BRR = GPIO_5_Pin;

    }
}


/********************************************************************************
*
* Function Name: static void blue_led_1_on(void)
* Function : 5pcs of grb blue led turn on
* Input Ref:NO
* Return Ref:NO
*
********************************************************************************/
static void blue_led_1_on(void)
{
    
    rgb_led_set_output_mode(GPIO_4_GPIO_Port,GPIO_4_Pin,0);
    rgb_led_set_output_mode(GPIO_3_GPIO_Port,GPIO_3_Pin,1);


    rgb_led_set_input_mode(GPIO_1_GPIO_Port,GPIO_1_Pin);
    rgb_led_set_input_mode(GPIO_2_GPIO_Port,GPIO_2_Pin);
    rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);


}


static void blue_led_2_on(void)
{
    
   
    rgb_led_set_output_mode(GPIO_2_GPIO_Port,GPIO_2_Pin,0);
        rgb_led_set_output_mode(GPIO_4_GPIO_Port,GPIO_4_Pin,1);
    
    
        rgb_led_set_input_mode(GPIO_1_GPIO_Port,GPIO_1_Pin);
        rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);
        rgb_led_set_input_mode(GPIO_3_GPIO_Port,GPIO_3_Pin);
    

    


}


static void blue_led_3_on(void)
{
    
   
    rgb_led_set_output_mode(GPIO_2_GPIO_Port,GPIO_2_Pin,1);
      rgb_led_set_output_mode(GPIO_4_GPIO_Port,GPIO_4_Pin,0);
    
    
        rgb_led_set_input_mode(GPIO_1_GPIO_Port,GPIO_1_Pin);
        rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);
        rgb_led_set_input_mode(GPIO_3_GPIO_Port,GPIO_3_Pin);


   


}

static void blue_led_4_on(void)
{
    
    


}


static void blue_led_5_on(void)
{
    
    
}



