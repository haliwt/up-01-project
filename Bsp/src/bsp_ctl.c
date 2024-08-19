#include "bsp.h"

ctl_t gctl_t;

//red led
static void red_led_1_on(void);

static void red_led_2_on(void);

static void red_led_3_on(void);

static void red_led_4_on(void);

static void red_led_5_on(void);



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
static void red_led_1_on(void)
{
 
    rgb_led_set_output_mode(GPIO_1_GPIO_Port,GPIO_1_Pin,0);
    rgb_led_set_output_mode(GPIO_2_GPIO_Port,GPIO_2_Pin,1);
   

   rgb_led_set_input_mode(GPIO_3_GPIO_Port,GPIO_3_Pin);
   rgb_led_set_input_mode(GPIO_4_GPIO_Port,GPIO_4_Pin);
   rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);


}





static void red_led_2_on(void)
{

  
     rgb_led_set_output_mode(GPIO_1_GPIO_Port,GPIO_1_Pin,1);
     rgb_led_set_output_mode(GPIO_2_GPIO_Port,GPIO_2_Pin,0);
    
 

   rgb_led_set_input_mode(GPIO_3_GPIO_Port,GPIO_3_Pin);
   rgb_led_set_input_mode(GPIO_4_GPIO_Port,GPIO_4_Pin);
   rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);


}



static void red_led_3_on(void)
{
 
  rgb_led_set_output_mode(GPIO_3_GPIO_Port,GPIO_3_Pin,1);
  rgb_led_set_output_mode(GPIO_2_GPIO_Port,GPIO_2_Pin,0);
   
   

   rgb_led_set_input_mode(GPIO_1_GPIO_Port,GPIO_1_Pin);
   rgb_led_set_input_mode(GPIO_4_GPIO_Port,GPIO_4_Pin);
   rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);


}

static void red_led_4_on(void)
{
 
  
    rgb_led_set_output_mode(GPIO_2_GPIO_Port,GPIO_2_Pin,1);
    rgb_led_set_output_mode(GPIO_3_GPIO_Port,GPIO_3_Pin,0);
   

   rgb_led_set_input_mode(GPIO_1_GPIO_Port,GPIO_1_Pin);
   rgb_led_set_input_mode(GPIO_4_GPIO_Port,GPIO_4_Pin);
   rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);


}

static void red_led_5_on(void)
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

/**********************************************************************************************************
*	函 数 名: void red_bsp_LedOn(uint8_t _no)  //bsp_LedOn
*	功能说明: 点亮指定的LED指示灯。
*	形    参:  _no : 指示灯序号，范围 1 - 5
*	返 回 值: 无
**********************************************************************************************************/
void red_bsp_LedOn(uint8_t _no, uint8_t green_flag)  //bsp_LedOn
{
	//_no--;
	static uint8_t green_led[5];
    switch(green_flag){

      case 0:

      break; 


      case 1:
        green_led[0] = 1;

      break;

      case 2:
        green_led[1] = 2;

      break;

      case 3:
          green_led[2] = 3;

      break;

      case 4:

          green_led[3]  = 4;


      break;

       case 5:

          green_led[4]  = 5;


      break;
      }


    

	if (_no == 1)
	{
        if(green_led[0] == 1){

            green_led_1_on();
        }
        else 
            red_led_1_on();//GPIO_1_GPIO_Port->BRR = GPIO_1_Pin; //BRR ->GPIO output = 0 
	}
	else if (_no == 2)
	{
        if(green_led[1] == 2){
        
             green_led_2_on();
        }
        else 
            red_led_2_on();//GPIO_2_GPIO_Port->BRR = GPIO_2_Pin;
	}
	else if (_no == 3)
	{
        if(green_led[2] == 3){
        
             green_led_3_on();
        }
        else 
          red_led_3_on();//GPIO_3_GPIO_Port->BRR = GPIO_3_Pin;
	}
	else if (_no == 4)
	{
         if(green_led[3] == 4){
        
            green_led_4_on();
         }
        else 
        red_led_4_on();//GPIO_4_GPIO_Port->BRR = GPIO_4_Pin;
	}
    else if(_no == 5)
    {
        if(green_led[4] ==5 ){
        
           green_led_5_on();
        }
        else 
        red_led_5_on();//GPIO_5_GPIO_Port->BRR = GPIO_5_Pin;

    }
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
void green_bsp_LedOn(uint8_t _no, uint8_t blue_flag)  //bsp_LedOn
{
	//_no--;

       static uint8_t blue_led[6];
        switch(blue_flag){
    
          case 6:
            
             blue_led[0] = 1;
    
          break; 
    
    
          case 7:
            blue_led[1] = 2;
    
          break;
    
          case 8:
            blue_led[2] = 3;
    
          break;
    
          case 9:
              blue_led[3] = 4;
    
          break;
    
          case 10:
    
              blue_led[4]  = 5;
    
    
          break;
    
         
      }

    

        

	if (_no == 1)
	{
        if(blue_led[0] == 1){
            blue_led_1_on();
        }
        else
           green_led_1_on();//GPIO_1_GPIO_Port->BRR = GPIO_1_Pin; //BRR ->GPIO output = 0 
	}
	else if (_no == 2)
	{
        if(blue_led[1] == 2){
            blue_led_2_on();
        }
        else
        green_led_2_on();//GPIO_2_GPIO_Port->BRR = GPIO_2_Pin;
	}
	else if (_no == 3)
	{
        if(blue_led[2] == 3){
            blue_led_3_on();
        }
        else
        green_led_3_on();//GPIO_3_GPIO_Port->BRR = GPIO_3_Pin;
	}
	else if (_no == 4)
	{
        if(blue_led[3] == 4){
            blue_led_4_on();
        }
        else
        green_led_4_on();//GPIO_4_GPIO_Port->BRR = GPIO_4_Pin;
	}
    else if(_no == 5)
    {
        if(blue_led[4] == 5){
            blue_led_5_on();
        }
        else
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
    
   
    rgb_led_set_input_mode(GPIO_1_GPIO_Port,GPIO_1_Pin);
    rgb_led_set_input_mode(GPIO_2_GPIO_Port,GPIO_2_Pin);
     rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);


    rgb_led_set_output_mode(GPIO_4_GPIO_Port,GPIO_4_Pin,0);
    rgb_led_set_output_mode(GPIO_3_GPIO_Port,GPIO_3_Pin,1);


    

}


static void blue_led_2_on(void)
{
    rgb_led_set_input_mode(GPIO_1_GPIO_Port,GPIO_1_Pin);
    rgb_led_set_input_mode(GPIO_2_GPIO_Port,GPIO_2_Pin);
    rgb_led_set_input_mode(GPIO_3_GPIO_Port,GPIO_3_Pin);
    
   
    rgb_led_set_output_mode(GPIO_5_GPIO_Port,GPIO_5_Pin,1);
    rgb_led_set_output_mode(GPIO_4_GPIO_Port,GPIO_4_Pin,0);
    
  
}


static void blue_led_3_on(void)
{
    rgb_led_set_input_mode(GPIO_1_GPIO_Port,GPIO_1_Pin);
    rgb_led_set_input_mode(GPIO_2_GPIO_Port,GPIO_2_Pin);
    rgb_led_set_input_mode(GPIO_3_GPIO_Port,GPIO_3_Pin);

    rgb_led_set_output_mode(GPIO_5_GPIO_Port,GPIO_5_Pin,0);
    rgb_led_set_output_mode(GPIO_4_GPIO_Port,GPIO_4_Pin,1);
    
}

static void blue_led_4_on(void)
{
    
    
    rgb_led_set_input_mode(GPIO_1_GPIO_Port,GPIO_1_Pin);
    rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);
    rgb_led_set_input_mode(GPIO_3_GPIO_Port,GPIO_3_Pin);

    rgb_led_set_output_mode(GPIO_2_GPIO_Port,GPIO_2_Pin,0);
    rgb_led_set_output_mode(GPIO_4_GPIO_Port,GPIO_4_Pin,1);
    


}


static void blue_led_5_on(void)
{
    
    rgb_led_set_input_mode(GPIO_1_GPIO_Port,GPIO_1_Pin);
    rgb_led_set_input_mode(GPIO_5_GPIO_Port,GPIO_5_Pin);
    rgb_led_set_input_mode(GPIO_3_GPIO_Port,GPIO_3_Pin);

    rgb_led_set_output_mode(GPIO_2_GPIO_Port,GPIO_2_Pin,1);
    rgb_led_set_output_mode(GPIO_4_GPIO_Port,GPIO_4_Pin,0);
    
    
}

/**********************************************************************************************************
*	函 数 名: void blue_bsp_LedOn(uint8_t _no) 
*	功能说明: 点亮指定的LED指示灯。
*	形    参:  _no : 指示灯序号，范围 1 - 5
*	返 回 值: 无
**********************************************************************************************************/
void blue_bsp_LedOn(uint8_t _no, uint8_t blue_end_flag)  
{
	//_no--;

    
   if(blue_end_flag == 11 && gpro_t.works_time_out_flag == 0){

        gpro_t.works_time_out_flag = 1;

   }
          
   if(gpro_t.works_time_out_flag == 0){
	if (_no == 1)
	{
		blue_led_1_on();//GPIO_1_GPIO_Port->BRR = GPIO_1_Pin; //BRR ->GPIO output = 0 
	}
	else if (_no == 2)
	{
		blue_led_2_on();//GPIO_2_GPIO_Port->BRR = GPIO_2_Pin;
	}
	else if (_no == 3)
	{
		blue_led_3_on();//GPIO_3_GPIO_Port->BRR = GPIO_3_Pin;
	}
	else if (_no == 4)
	{
		blue_led_4_on();//GPIO_4_GPIO_Port->BRR = GPIO_4_Pin;
	}
    else if(_no == 5)
    {
        blue_led_5_on();//GPIO_5_GPIO_Port->BRR = GPIO_5_Pin;

    }

    }
}


/**************************************************************************
*
*	函 数 名: void red_bsp_LedOn_1_green_led(uint8_t number)
*	功能说明: 
*	形    参:  _no :点亮LED 号码
*	返 回 值: 无
*
****************************************************************************/
void blue_led_all_on(uint8_t on_flag)
{
   if(on_flag == 1){


    
   led_2:   blue_led_1_on();
       osDelay(3);
       blue_led_2_on();
        osDelay(3);
       blue_led_3_on();
        osDelay(3);
       blue_led_4_on();
        osDelay(3);
       blue_led_5_on();
        osDelay(3);
       if(on_flag == 1){
           goto led_2;
       }
   }
  
}

