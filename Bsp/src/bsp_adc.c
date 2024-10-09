#include "bsp.h"
#include "adc.h"


/* USER CODE BEGIN 0 */

static uint16_t Get_Adc_Channel(uint32_t ch) ;     



static uint16_t Get_Adc_Average(uint32_t ch,uint8_t times);
static uint16_t Get_Motor_ADC_Channel(void)    ;

static uint16_t Get_Motor_ADC_Average(uint8_t times);


uint16_t fan_detect_voltage;
uint16_t motor_detect_voltage;
__IO uint32_t ADC_ConvertedValueLocal[ADC_CHANNEL_NUMBER];

uint16_t ADC_ConvertedValue[ADC_CHANNEL_NUMBER];




/*****************************************************************
*
	*Function Name: static uint16_t Get_Adc(uint32_t ch)  
	*Function ADC input channel be selected "which one channe"
	*Input Ref: which one ? AC_Channel_?
	*Return Ref: No
	*
	*
*****************************************************************/
static uint16_t Get_Adc_Channel(uint32_t ch)      
{
    ADC_ChannelConfTypeDef ADC1_ChanConf;

	ADC1_ChanConf.Channel=ch;                                   //Í¨µÀ
    ADC1_ChanConf.Rank= ADC_REGULAR_RANK_1;                                    //第一个序列
    ADC1_ChanConf.SamplingTime=ADC_SAMPLETIME_1CYCLE_5;//ADC_SAMPLETIME_239CYCLES_5;      //²ÉÑùÊ±¼ä               


	HAL_ADC_ConfigChannel(&hadc1,&ADC1_ChanConf);        //Í¨µÀÅäÖÃ
	
    HAL_ADC_Start(&hadc1);                               //start ADC transmit
	
    HAL_ADC_PollForConversion(&hadc1,10);                //轮询转换
 
	return (uint16_t)HAL_ADC_GetValue(&hadc1);	        	//·µ»Ø×î½üÒ»´ÎADC1¹æÔò×éµÄ×ª»»½á¹û

}

/*****************************************************************
*
	*Function Name: static uint16_t Get_Adc(uint32_t ch)  
	*Function ADC input channel be selected "which one channe"
	*Input Ref: which one ? AC_Channel_?
	*Return Ref: No
	*
	*
*****************************************************************/
static uint16_t Get_Motor_ADC_Channel(void)      
{
    ADC_ChannelConfTypeDef ADC1_ChanConf;

	ADC1_ChanConf.Channel=ADC_CHANNEL_1;                                   //Í¨µÀ
    ADC1_ChanConf.Rank= ADC_REGULAR_RANK_1;//ADC_REGULAR_RANK_2;                                    //第一个序列
    ADC1_ChanConf.SamplingTime=ADC_SAMPLETIME_1CYCLE_5;//ADC_SAMPLETIME_239CYCLES_5;      //²ÉÑùÊ±¼ä               


	HAL_ADC_ConfigChannel(&hadc1,&ADC1_ChanConf);        //Í¨µÀÅäÖÃ
	
    HAL_ADC_Start(&hadc1);                               //start ADC transmit
	
    HAL_ADC_PollForConversion(&hadc1,10);                //轮询转换
 
	return (uint16_t)HAL_ADC_GetValue(&hadc1);	        	//·µ»Ø×î½üÒ»´ÎADC1¹æÔò×éµÄ×ª»»½á¹û

}


/*****************************************************************
*
	*Function Name: static uint16_t Get_Adc(uint32_t ch)  
	*Function ADC input channel be selected "which one channe"
	*Input Ref: which one ? AC_Channel_?
	*Return Ref: No
	*
	*
*****************************************************************/
static uint16_t Get_Adc_Average(uint32_t ch,uint8_t times)
{
	uint32_t temp_val=0;
	uint8_t t;
	for(t=0;t<times;t++)
	{
		temp_val+=Get_Adc_Channel(ch);
		osDelay(10);
	}
	return temp_val/times;
} 


static uint16_t Get_Motor_ADC_Average(uint8_t times)
{
	uint32_t temp_val=0;
	uint8_t t;
	for(t=0;t<times;t++)
	{
		temp_val+=Get_Motor_ADC_Channel();
		osDelay(10);
	}
	return temp_val/times;
} 
 


//uint16_t Get_Adc_Voltage_Value(uint8_t times) 
//{
//    // 定义一个变量，用于存储计算出的电压值
//    uint16_t temp_voltage_value;
//    // 定义一个变量，用于存储读取到的模拟电压的十六进制数
//    uint16_t temp_hex_value;
//    // 读取times次，计算平均值
//    temp_hex_value = Get_Adc_Hex_Average(times);
//    // 使用公式计算出实际的电压值
//    temp_voltage_value = (temp_hex_value * 3300) / 4096; // amplification -> 1000 multiple
//    // 返回实际的电压值
//    return temp_voltage_value;
//}

/*****************************************************************
	*
	*Function Name: void Get_Fan_Adc_Fun(uint8_t channel,uint8_t times)
	*Function ADC input channel be selected "which one channe"
	*Input Ref: which one ? AC_Channel_?, hexadecimal of average
	*Return Ref: No
	*
	*
*****************************************************************/
void Get_Fan_ADC_Fun(uint8_t channel,uint8_t times)
{

    static uint8_t detect_error_times;
    uint16_t adcx;

    adcx = Get_Adc_Average(channel,times);

    fan_detect_voltage =(uint16_t)((adcx * 3300)/4096); //amplification 1000 ,3.111V -> 3111
	//HAL_Delay(5);

	if( fan_detect_voltage >  200 ){
           detect_error_times=0;
		   #if DEBUG
             printf("adc= %d",run_t.fan_detect_voltage);
		   #endif 
          
    }
	else{

       if(detect_error_times >2 && gpro_t.gpower_on == power_on){
		   	
            gpro_t.fan_warning = 1;
            buzzer_sound();//Buzzer_KeySound();
            osDelay(200);
            buzzer_sound();//Buzzer_KeySound();
            osDelay(200);
            buzzer_sound();//Buzzer_KeySound();
            osDelay(200);
            buzzer_sound();//Buzzer_KeySound();
            osDelay(200);
        }
	    detect_error_times++;

     }
   /// }
}

void Get_Motor_ADC_Fun(uint8_t channel,uint8_t times)
{

   
    uint16_t adc_fan_hex;//,fan_detect_voltage;
        
    static uint8_t detect_error_times;
        
    adc_fan_hex = Get_Motor_ADC_Average(times);

    motor_detect_voltage=(uint16_t)((adc_fan_hex* 3300)/4096); //amplification 1000 ,3.111V -> 3111
	//HAL_Delay(5);

	if(motor_detect_voltage   >  170 ){
           detect_error_times=0;
		   #if DEBUG
             printf("adc= %d",run_t.fan_detect_voltage);
		   #endif 
          
    }
	else{

	          
	 if(detect_error_times >2 && gpro_t.gpower_on == power_on){
	   		
           
           buzzer_sound();//Buzzer_KeySound();
	       osDelay(30);
		   buzzer_sound();//Buzzer_KeySound();
	       osDelay(30);
		   buzzer_sound();//Buzzer_KeySound();
	       osDelay(30);
		   buzzer_sound();//Buzzer_KeySound();
	       osDelay(30);
		   
	 }
     detect_error_times++;
              
     }

}

