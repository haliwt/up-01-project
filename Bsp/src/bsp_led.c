#include "bsp.h"

led_t gled_t;


static uint8_t reg_led_on_off_fun(uint8_t data);

static uint8_t reg_led_color_fun(uint8_t color);


/********************************************************************************
	**
	*Function Name: void LED_Init(void)
	*Function :
	*Input Ref: 
	*Return Ref:NO
	*
*******************************************************************************/
void LED_Init(void)
{
   rgb_onoff_state_fun(reg_led_on_off_fun);

   rgb_color_state_fun(reg_led_color_fun);


}


/*******************************************************************************
*
*Function Name: void rgb_led_set_input_mode(GPIO_TypeDef *p_gpiox, uint16_t pinx)
*Function : 
*Input Ref: GPIO PORT and GPIO Pin numbers
*Return Ref:NO 
*
********************************************************************************/
void rgb_led_set_input_mode(GPIO_TypeDef  *GPIOx,uint16_t pinx)
{

  
  GPIO_InitTypeDef GPIO_InitStruct = {0};
   
    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

   GPIO_InitStruct.Pin = pinx;
   GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
   GPIO_InitStruct.Pull = GPIO_NOPULL;
   HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
//

//   
//         GPIO_InitStruct.Pin = pinx;
//         GPIO_InitStruct.Mode = GPIO_MODE_INPUT; // GPIO_MODE_INPUT = 0X0
//         GPIO_InitStruct.Pull = GPIO_PULLUP;
//    
//    
//        assert_param(IS_GPIO_MODE(GPIO_Init->Mode));
//    
//      /* Configure IO Direction mode (Input, Output, Alternate or Analog) */
//       temp = GPIOx->MODER;
//       temp &= ~(GPIO_MODER_MODE0 << (position * 2u));
//       temp |= ((GPIO_Init->Mode & GPIO_MODE) << (position * 2u));
//       GPIOx->MODER = temp;


}

#if 0
  switch(pinx){

    case GPIO_1_Pin:


    /*Configure GPIO pin Output Level GPIO_1_Pin */
    HAL_GPIO_WritePin(GPIOB, GPIO_1_Pin, GPIO_PIN_RESET);
    /*Configure GPIO pin : PtPin */
    GPIO_InitStruct.Pin = GPIO_1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP ;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

     
    /*Configure GPIO pin : PtPin */
    GPIO_InitStruct.Pin = GPIO_2_Pin|GPIO_3_Pin|GPIO_4_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


     /*Configure GPIO pin : PtPin */
    GPIO_InitStruct.Pin = GPIO_5_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);


    break;

    case GPIO_2_Pin :



         /*Configure GPIO pin Output Level GPIO_1_Pin */
        HAL_GPIO_WritePin(GPIOA, GPIO_2_Pin, GPIO_PIN_RESET);
        /*Configure GPIO pin : PtPin */
        GPIO_InitStruct.Pin = GPIO_2_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP ;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

      
       /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin =  GPIO_3_Pin|GPIO_4_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


       /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_1_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    
        /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_5_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    

    break;


    case GPIO_3_Pin :

        /*Configure GPIO pin Output Level GPIO_1_Pin */
        HAL_GPIO_WritePin(GPIOA, GPIO_3_Pin, GPIO_PIN_RESET);
        /*Configure GPIO pin : PtPin */
        GPIO_InitStruct.Pin = GPIO_3_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP ;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
        
       /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_2_Pin|GPIO_4_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


       /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_1_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    
        /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_5_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    

    break;

     case GPIO_4_Pin :


        /*Configure GPIO pin Output Level GPIO_1_Pin */
        HAL_GPIO_WritePin(GPIOA, GPIO_4_Pin, GPIO_PIN_RESET);
        /*Configure GPIO pin : PtPin */
        GPIO_InitStruct.Pin = GPIO_4_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP ;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
        
       /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_2_Pin|GPIO_3_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


       /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_1_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    
        /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_5_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    
        

    break;

    case GPIO_5_Pin :


         /*Configure GPIO pin Output Level GPIO_1_Pin */
        HAL_GPIO_WritePin(GPIOC, GPIO_5_Pin, GPIO_PIN_RESET);
        /*Configure GPIO pin : PtPin */
        GPIO_InitStruct.Pin = GPIO_5_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP ;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
        
       /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_2_Pin|GPIO_3_Pin|GPIO_4_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


       /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_1_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    
  
    

    break;



  }


  

}
#endif 

/*******************************************************************************
*
*Function Name: void rgb_led_set_output_mode(GPIO_TypeDef  *GPIOx,uint16_t pinx,uint8_t high_low)
*Function : 
*Input Ref: GPIO PORT and GPIO Pin numbers
*Return Ref:NO 
*
********************************************************************************/
void rgb_led_set_output_mode(GPIO_TypeDef  *GPIOx,uint16_t pinx,uint8_t high_low)
{

  
  GPIO_InitTypeDef GPIO_InitStruct = {0};
   
    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();


     /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOx, pinx,high_low);



  /*Configure GPIO pins : PBPin PBPin */
  GPIO_InitStruct.Pin = pinx;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);

}

#if 0
  switch(pinx){

    case GPIO_1_Pin:

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOB, GPIO_1_Pin, GPIO_PIN_RESET);
    /*Configure GPIO pin : PtPin */
    GPIO_InitStruct.Pin = GPIO_2_Pin|GPIO_3_Pin|GPIO_4_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
 
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);


     /*Configure GPIO pin : PtPin */
    GPIO_InitStruct.Pin = GPIO_5_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);


    break;

    case GPIO_2_Pin :

      
       /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin =  GPIO_3_Pin|GPIO_4_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
       HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


       /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_1_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
       HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    
        /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_5_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
       HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    

    break;


    case GPIO_3_Pin :
        
       /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_2_Pin|GPIO_4_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
         GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
       HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


       /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_1_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    
        /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_5_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    

    break;

     case GPIO_4_Pin :
        
       /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_2_Pin|GPIO_3_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
         GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
       HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


       /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_1_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    
        /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_5_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    
        

    break;

    case GPIO_5_Pin :
        
       /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_2_Pin|GPIO_3_Pin|GPIO_4_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


       /*Configure GPIO pin : PtPin */
       GPIO_InitStruct.Pin = GPIO_1_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    
  
    

    break;



  }


  

}

#endif 


/**
 * @brief       set GPIO of state 
 * @param       p_gpiox: GPIOA~GPIOG, GPIO of pointer
 * @param       0X0000~0XFFFF, pinx of IO,
 *   @arg       SYS_GPIO_PIN0~SYS_GPIO_PIN15, 1<<0 ~ 1<<15
 * @param       status: 0/1,  pin 
 *   @arg       0, output low level
 *   @arg       1, output high level
 * @retval      NO
 */
void sys_gpio_pin_set(GPIO_TypeDef *p_gpiox, uint16_t pinx, uint8_t status)
{
    if (status & 0X01)
    {
        p_gpiox->BSRR |= pinx;  /* set GPIO pinx = 1 */
    }
    else
    {
        p_gpiox->BSRR |= (uint32_t)pinx << 16;  /* set GPIO pinx = 0 */
    }
}


/**
 * @brief       ¶ÁÈ¡GPIOÄ³¸öÒý½ÅµÄ×´Ì¬
 * @param       p_gpiox: GPIOA~GPIOG, GPIOÖ¸Õë
 * @param       0X0000~0XFFFF, Òý½ÅÎ»ÖÃ, Ã¿¸öÎ»´ú±íÒ»¸öIO, µÚ0Î»´ú±íPx0, µÚ1Î»´ú±íPx1, ÒÀ´ÎÀàÍÆ. ±ÈÈç0X0101, ´ú±íÍ¬Ê±ÉèÖÃPx0ºÍPx8.
 *   @arg       SYS_GPIO_PIN0~SYS_GPIO_PIN15, 1<<0 ~ 1<<15
 * @retval      return value: 0 - low level, 1- high level
 */
uint8_t sys_gpio_pin_get(GPIO_TypeDef *p_gpiox, uint16_t pinx)
{
    if (p_gpiox->IDR & pinx)
    {
        return 1;   /* pinx - is low level*/
    }
    else
    {
        return 0;   /* pinx GPIO is high level */
    }
}






#if 0
void sys_gpio_set_input(GPIO_TypeDef  *GPIOx)
{

      uint32_t position = 0x00u;
    //  uint32_t iocurrent;
      uint32_t temp;


      
      GPIO_InitTypeDef GPIO_InitStruct = {0};

      /* GPIO Ports Clock Enable */
      __HAL_RCC_GPIOB_CLK_ENABLE();
      __HAL_RCC_GPIOC_CLK_ENABLE();
      __HAL_RCC_GPIOA_CLK_ENABLE();

        GPIO_InitStruct.Pin = KEY_ID_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT; // GPIO_MODE_INPUT = 0X0
        GPIO_InitStruct.Pull = GPIO_PULLUP;


       assert_param(IS_GPIO_MODE(GPIO_Init->Mode));

     /* Configure IO Direction mode (Input, Output, Alternate or Analog) */
      temp = GPIOx->MODER;
      temp &= ~(GPIO_MODER_MODE0 << (position * 2u));
      temp |= ((GPIO_Init->Mode & GPIO_MODE) << (position * 2u));
      GPIOx->MODER = temp;



}
#endif 

uint8_t rgb_onoff_state_fun(uint8_t (*rgb_on_off_handler)(uint8_t data))
{

     gled_t.rgb_onoff_state = rgb_on_off_handler;

}

uint8_t rgb_color_state_fun(uint8_t(*rgb_color_handler)(uint8_t color))
{


   gled_t.rgb_onoff_state  = rgb_color_handler;


}


/****************************************************************
*
*Function Name: static uint8_t reg_led_on_off_fun(uint8_t data)
*
*
*
*****************************************************************/
static uint8_t reg_led_on_off_fun(uint8_t data)
{



}


static uint8_t reg_led_color_fun(uint8_t color)
{




}

/**********************************************************************************************************
*	函 数 名: bsp_LedOn
*	功能说明: 点亮指定的LED指示灯。
*	形    参:  _no : 指示灯序号，范围 1 - 5
*	返 回 值: 无
**********************************************************************************************************/
void red_bsp_LedOn(uint8_t _no)  //bsp_LedOn
{
	//_no--;

	if (_no == 1)
	{
		red_led_1_on();//GPIO_1_GPIO_Port->BRR = GPIO_1_Pin; //BRR ->GPIO output = 0 
	}
	else if (_no == 2)
	{
		red_led_2_on();//GPIO_2_GPIO_Port->BRR = GPIO_2_Pin;
	}
	else if (_no == 3)
	{
		red_led_3_on();//GPIO_3_GPIO_Port->BRR = GPIO_3_Pin;
	}
	else if (_no == 4)
	{
		red_led_4_on();//GPIO_4_GPIO_Port->BRR = GPIO_4_Pin;
	}
    else if(_no == 5)
    {
        red_led_5_on();//GPIO_5_GPIO_Port->BRR = GPIO_5_Pin;

    }
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
		red_led_1_on();//GPIO_1_GPIO_Port->BRR = GPIO_1_Pin; //BRR ->GPIO output = 0 
	}
	else if (_no == 2)
	{
		red_led_2_on();//GPIO_2_GPIO_Port->BRR = GPIO_2_Pin;
	}
	else if (_no == 3)
	{
		red_led_3_on();//GPIO_3_GPIO_Port->BRR = GPIO_3_Pin;
	}
	else if (_no == 4)
	{
		red_led_4_on();//GPIO_4_GPIO_Port->BRR = GPIO_4_Pin;
	}
    else if(_no == 5)
    {
        red_led_5_on();//GPIO_5_GPIO_Port->BRR = GPIO_5_Pin;

    }
}


/**********************************************************************************************************
*	函 数 名: void red_bsp_LedOff(uint8_t _no)
*	功能说明: 熄灭指定的LED指示灯。
*	形    参:  _no : 指示灯序号，范围 1 - 4
*	返 回 值: 无
**********************************************************************************************************/
void red_bsp_LedOff(uint8_t _no)
{
	//_no--;

	if (_no == 1)
	{
		//GPIO_1_GPIO_Port->BSRR = GPIO_1_Pin;   // GPIO output is high = "1"
	}
	else if (_no == 2)
	{
		//GPIO_1_GPIO_Port->BSRR = GPIO_2_Pin;
	}
	else if (_no == 3)
	{
		//GPIO_1_GPIO_Port->BSRR = GPIO_3_Pin;
	}
	else if (_no == 4)
	{
		//GPIO_1_GPIO_Port->BSRR = GPIO_4_Pin;
	}
    else if(_no == 5)
    {
        //GPIO_5_GPIO_Port->BSRR = GPIO_5_Pin;

    }
}

/**********************************************************************************************************
*	函 数 名: bsp_LedToggle
*	功能说明: 翻转指定的LED指示灯。
*	形    参:  _no : 指示灯序号，范围 1 - 4
*	返 回 值: 按键代码
**********************************************************************************************************/
void bsp_LedToggle(uint8_t _no)
{
	if (_no == 1)
	{
		GPIO_1_GPIO_Port->ODR ^= GPIO_1_Pin;
	}
	else if (_no == 2)
	{
		GPIO_2_GPIO_Port->ODR ^= GPIO_2_Pin;
	}
	else if (_no == 3)
	{
		GPIO_3_GPIO_Port->ODR ^= GPIO_3_Pin;
	}
	else if (_no == 4)
	{
		GPIO_4_GPIO_Port->ODR ^= GPIO_4_Pin;
	}
    else if (_no == 5)
	{
		GPIO_5_GPIO_Port->ODR ^= GPIO_5_Pin;
	}
}

/*
*********************************************************************************************************
*	函 数 名: bsp_IsLedOn
*	功能说明: 判断LED指示灯是否已经点亮。
*	形    参:  _no : 指示灯序号，范围 1 - 4
*	返 回 值: 1表示已经点亮，0表示未点亮
*********************************************************************************************************
*/
uint8_t bsp_IsLedOn(uint8_t _no)
{
	if (_no == 1)
	{
		if ((GPIO_1_GPIO_Port->ODR &  GPIO_1_Pin) == 0)
		{
			return 1;
		}
		return 0;
	}
	else if (_no == 2)
	{
		if ((GPIO_2_GPIO_Port->ODR &  GPIO_2_Pin) == 0)
		{
			return 1;
		}
		return 0;
	}
	else if (_no == 3)
	{
		if ((GPIO_3_GPIO_Port->ODR &  GPIO_3_Pin) == 0)
		{
			return 1;
		}
		return 0;
	}
	else if (_no == 4)
	{
		if ((GPIO_4_GPIO_Port->ODR &  GPIO_4_Pin) == 0)
		{
			return 1;
		}
		return 0;
	}
    else if (_no == 5)
	{
		if ((GPIO_5_GPIO_Port->ODR &  GPIO_5_Pin) == 0)
		{
			return 1;
		}
		return 0;
	}

	return 0;
}


