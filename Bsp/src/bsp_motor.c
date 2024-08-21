#include "bsp_motor.h"

#define STEPMOTOR_SPEED              1    // 定义步进电机速度，值越小，速度越快
                                           // 最小不能小于8
#define STEPMOTOR_CIRCLE_NUMBER       10   // 转动圈数
#define STEPMOTOR_DIRECTION           1    // 1：顺时针  0：逆时针


/* 私有变量 ------------------------------------------------------------------*/
// 速度，该值越小，速度越快，最小不能小于8
uint8_t speed=STEPMOTOR_SPEED;
// 转动圈数：28BYJ-48步进电机的步距角度为5.625/64，即每64个脉冲转5.625度
// 要转一圈需要360/5.625*64=4096个脉冲。
uint32_t Circle_number= 1000;
// 选择方向控制
uint8_t direction=STEPMOTOR_DIRECTION;
/* 扩展变量 ------------------------------------------------------------------*/
/* 私有函数原形 --------------------------------------------------------------*/

static void step_motor_pulse(uint8_t step,uint8_t direction);

uint16_t pulse_count; 

/***********************************************************
  * Function Name: void motor_stop_fun(void)
  * 函数功能: 
  * 输入参数: 无
  * 返 回 值: 无
  * 说    明: 
**************************************************************/
void motor_stop_fun(void)
{

    A_OFF;  B_OFF; C_OFF; D_OFF;        // 停机 
}

/**
  * 函数功能: 滴答定时器回调函数.
  * 输入参数: 无
  * 返 回 值: 无
  * 说    明: 每隔一定的时间就输出新节拍信号
  */
void step_motor_rotation_handler(uint8_t direction)
{
  static uint8_t count=0;               // 用于旋转速度控制
  static uint8_t step=0;                // 当前步进节拍
 // static uint16_t pulse_count=0;        // 脉冲计数，4096个脉冲电机旋转一圈
  
  if(Circle_number)                     // 如果等待旋转圈数不为0
  {
    count++;                            // 增加时间计数
    if(count==speed)                    // 时间计数与目标速度相对时执行下一节拍输出
    {
      step_motor_pulse(step,direction); // 输出新节拍信号
      pulse_count++;                    // 脉冲输出数增加      
      step++;                           // 节拍数增加
      if(step==8) step=0;               // 循环开始输出节拍
      count=0;                          // 清零时间计数
    }
    if(pulse_count==4096)               // 如果已经输出了4096个脉冲信号，已经转动了一圈
    {
      pulse_count=0;                    // 脉冲计数清零
      Circle_number--;                  // 等待旋转圈数减1
    }
  }
  else
  {
    A_OFF;  B_OFF; C_OFF; D_OFF;        // 停机 
  }
}


/**
  * 函数功能: 输出一个数据给ULN2003从而实现向步进电机发送一个脉冲
  * 输入参数: step：指定步进序号，可选值0~7
  *          direction：方向选择,可选值：1：顺时针,0：逆时针
  * 返 回 值: 无
  * 说    明: 无
  */
static void step_motor_pulse(uint8_t step,uint8_t direction)
{
  uint8_t temp=step;
  
  if(direction==0)    // 如果为逆时针旋转
  {
    temp=7-step;      // 调换节拍信号
  }
  switch(temp)
  {
    // 8个节拍控制：A->AB->B->BC->C->CD->D->DA
    case 0:
      A_ON;  B_OFF; C_OFF; D_OFF;
    break;
    case 1:
      A_ON;  B_ON;  C_OFF; D_OFF;
    break;
    case 2:
      A_OFF; B_ON;  C_OFF; D_OFF;
    break;
    case 3:
      A_OFF; B_ON;  C_ON;  D_OFF;
    break;
    case 4:
      A_OFF; B_OFF; C_ON;  D_OFF;
    break;
    case 5:
      A_OFF; B_OFF; C_ON;  D_ON;
    break;
    case 6:
      A_OFF; B_OFF; C_OFF; D_ON;
    break;
    case 7:
      A_ON;  B_OFF; C_OFF; D_ON;
    break;
  }
}


