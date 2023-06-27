
/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-03-10     110      first implementation
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <rtthread.h>
#include <rtdevice.h>
#include "oled.h"
#include "bmp.h"
#include "motor.h"
//#include "n32g45x_rcc.h"
#include "rc522.h"

#define LED1_PIN    GET_PIN(B, 0)
#define LED2_PIN    GET_PIN(B, 1)
#define LED3_PIN    GET_PIN(C, 5)

#define LED_TASK_SIZE     256
#define LED_TASK_PRIORITY 12
#define LED_TASK_TICK     5
static rt_thread_t led_task_ptr = RT_NULL;

#define OLED_TASK_SIZE     512
#define OLED_TASK_PRIORITY 9
#define OLED_TASK_TICK     5
static rt_thread_t oled_task_ptr = RT_NULL;

#define MOTOR_TASK_SIZE     512
#define MOTOR_TASK_PRIORITY 11
#define MOTOR_TASK_TICK     5
static rt_thread_t motor_task_ptr = RT_NULL;

#define RC522_TASK_SIZE     1024
#define RC522_TASK_PRIORITY 10
#define RC522_TASK_TICK     5
static rt_thread_t rc522_task_ptr = RT_NULL;

uint8_t value;
unsigned char CT[2];
unsigned char SN[4];
unsigned char RFID[16];
unsigned char Mask_bit=0;
unsigned char card1_bit=0;
unsigned char card2_bit=0;
unsigned char card3_bit=0;
unsigned char card4_bit=0;
unsigned char total=0;
unsigned char Mask[4]={6,109,250,186};
unsigned char card_1[4]={66,193,88,0};
unsigned char card_2[4]={66,191,104,0};
unsigned char card_3[4]={62,84,28,11};
unsigned char card_4[4]={126,252,248,12};
uint8_t KEY[6]={0xff,0xff,0xff,0xff,0xff,0xff};
unsigned char RFID1[16]={0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x07,0x80,0x29,0xff,0xff,0xff,0xff,0xff,0xff};

void  led_task(void *parameter)
{
    uint32_t Speed = 500;
    rt_pin_mode(LED1_PIN, PIN_MODE_OUTPUT);

    while (1)
    {
        rt_pin_write(LED1_PIN, PIN_LOW);
        rt_thread_mdelay(Speed);
        rt_pin_write(LED1_PIN, PIN_HIGH);
        rt_thread_mdelay(Speed);
    }
}

void  oled_task(void *parameter)
{
    OLED_Init();
    OLED_Clear();
    while (1)
    {
        OLED_Clear();
        OLED_ShowCHinese(6+2,0,22);//使
        OLED_ShowCHinese(24+2,0,23);//用
        OLED_ShowCHinese(42+2,0,24);//国
        OLED_ShowCHinese(60+2,0,25);//民
        OLED_ShowCHinese(78+2,0,26);//技
        OLED_ShowCHinese(96+2,0,27);//术
        OLED_ShowString(12,3,"N32G455VL-STB",16);
        OLED_ShowString(26,6,"2022-09-10",16);
        rt_thread_mdelay(5000);
        OLED_Clear();
        OLED_DrawBMP(0,0,128,8,BMP4);
        rt_thread_mdelay(1500);
        if(value == 0x10)
        {
            OLED_Clear();
            Motorcw_angle(60,1);
            OLED_ShowString(12,3,"Open Success",16);
            rt_pin_mode(LED1_PIN, PIN_MODE_OUTPUT);
            rt_pin_write(LED1_PIN, PIN_HIGH);
            rt_pin_write(LED2_PIN, PIN_HIGH);
            rt_pin_write(LED3_PIN, PIN_HIGH);
            rt_thread_mdelay(5000);
            OLED_Clear();
            Motorccw_angle(60,1);
            OLED_ShowString(12,3,"Close Over",16);
            rt_thread_mdelay(8000);
         }
    }
}

void  motor_task(void *parameter)
{
    Moto_Init();
    while(1)
     {
       switch(value)
      {
       case 1:while (value){Motorcw(30);}break;
       case 2:while (value){Motorccw(30);}break;
      }
      rt_thread_mdelay(5000);
     }
}

void  rc522_task(void *parameter)
{
      unsigned char status;
      unsigned char s=0x08;
      u8 t;
      u8 j;

      InitRc522();    //初始化射频卡模块
      rt_pin_mode(LED1_PIN, PIN_MODE_OUTPUT);
      rt_pin_write(LED1_PIN, PIN_HIGH);
      while(1)
      {
         status = PcdRequest(PICC_REQALL,CT);
         if(status==MI_OK)    //寻卡成功
         {
            value = 0x00;
            OLED_Clear();
            OLED_ShowString(2,3,"PcdRequest_MI_OK",16);
            status=MI_ERR;
            status = PcdAnticoll(SN);   //防止冲撞
          }
         if (status==MI_OK)     //防止冲撞成功
          {
             OLED_Clear();
             OLED_ShowString(2,3,"PcdAnticoll_MI_OK",16);
             status=MI_ERR;
             rt_pin_write(LED1_PIN, PIN_HIGH);
             rt_pin_write(LED2_PIN, PIN_HIGH);
             ShowID(0,200,SN);   //在OLED屏上显示卡的ID号
             OLED_Clear();
             OLED_ShowString(2,3,"The Card ID is:",16);
             for(j=0;j<4;j++)
              {
                 OLED_ShowNum(0,116+j*16,SN[j],3,16);
              }
              if((SN[0]==Mask[0])&&(SN[1]==Mask[1])&&(SN[2]==Mask[2])&&(SN[3]==Mask[3]))
              {
                 Mask_bit=1;
                 OLED_Clear();
                 OLED_ShowString(2,3,"The User is:Mask",16);
               }
               if((SN[0]==card_1[0])&&(SN[1]==card_1[1])&&(SN[2]==card_1[2])&&(SN[3]==card_1[3]))
               {
                 card1_bit=1;
                 OLED_Clear();
                 OLED_ShowString(2,3,"The User is:card_1",16);
               }
                if((SN[0]==card_2[0])&&(SN[1]==card_2[1])&&(SN[2]==card_2[2])&&(SN[3]==card_2[3]))
               {
                 card2_bit=1;
                 OLED_Clear();
                 OLED_ShowString(2,3,"The User is:card_2",16);
               }
               if((SN[0]==card_3[0])&&(SN[1]==card_3[1])&&(SN[2]==card_3[2])&&(SN[3]==card_3[3]))
               {
                 card3_bit=1;
                 OLED_Clear();
                 OLED_ShowString(2,3,"The User is:card_3",16);
               }
               if((SN[0]==card_4[0])&&(SN[1]==card_4[1])&&(SN[2]==card_4[2])&&(SN[3]==card_4[3]))
               {
                 card4_bit=1;
                 OLED_Clear();
                 OLED_ShowString(2,3,"The User is:card_4",16);
               }
               total=card1_bit+card2_bit+card3_bit+card4_bit+Mask_bit;
               OLED_Clear();
               OLED_ShowString(2,3,"total:",16);
               OLED_ShowNum(2,6,total,2,16);
               status =PcdSelect(SN);
               //Reset_RC522();
             }
             else
             {
                 rt_pin_write(LED1_PIN, PIN_LOW);
                 rt_pin_write(LED2_PIN, PIN_HIGH);
              }
              if(status==MI_OK)   //选卡成功
              {
                 OLED_Clear();
                 OLED_ShowString(2,3,"PcdSelect_MI_OK  ",16);
                 status=MI_ERR;
                 status =PcdAuthState(0x60,0x09,KEY,SN);
              }
              if(status==MI_OK)   //验证成功
              {
                 OLED_Clear();
                 OLED_ShowString(2,3,"PcdAuthState_MI_OK  ",16);
                 status=MI_ERR;
                 status=PcdRead(s,RFID);
              }
              if(status==MI_OK)    //读卡成功
              {
                 OLED_Clear();
                 OLED_ShowString(2,3,"READ_MI_OK",16);
                 status=MI_ERR;
                 rt_thread_mdelay(100);
                 value = 0x10;
              }

            }
}

int main(void)
{
     led_task_ptr = rt_thread_create("led_task",
                              led_task, RT_NULL,
                              LED_TASK_SIZE,
                              LED_TASK_PRIORITY,
                              LED_TASK_TICK);
      oled_task_ptr = rt_thread_create("oled_task",
                              oled_task, RT_NULL,
                              OLED_TASK_SIZE,
                              OLED_TASK_PRIORITY,
                              OLED_TASK_TICK);
      motor_task_ptr = rt_thread_create("motor_task",
                              motor_task,RT_NULL,
                              MOTOR_TASK_SIZE,
                              MOTOR_TASK_PRIORITY,
                              MOTOR_TASK_TICK);
      rc522_task_ptr = rt_thread_create("rc522_task",
                              rc522_task,RT_NULL,
                              RC522_TASK_SIZE,
                              RC522_TASK_PRIORITY,
                              RC522_TASK_TICK);
      rt_thread_startup(oled_task_ptr);
      rt_thread_startup(led_task_ptr);
      rt_thread_startup(motor_task_ptr);
      rt_thread_startup(rc522_task_ptr);

      return 0;
}
