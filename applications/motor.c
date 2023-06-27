/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-03-10     110       the first version
 */
#include "motor.h"
#include <stdint.h>
#include <rtthread.h>
#include <drivers/pin.h>

extern uint8_t value;

void Moto_Init(void)
{
  rt_pin_mode(motor_a_pin , PIN_MODE_OUTPUT );
  rt_pin_mode(motor_b_pin , PIN_MODE_OUTPUT );
  rt_pin_mode(motor_c_pin , PIN_MODE_OUTPUT );
  rt_pin_mode(motor_d_pin , PIN_MODE_OUTPUT );\
  rt_kprintf("motor_init successful\r\n");
  rt_pin_write(motor_a_pin, PIN_HIGH);
  rt_pin_write(motor_b_pin, PIN_HIGH);
  rt_pin_write(motor_c_pin, PIN_HIGH);
  rt_pin_write(motor_d_pin, PIN_HIGH);
}

 void Motorcw(uint speed)
{
    rt_pin_write(motor_a_pin, PIN_LOW);
    rt_pin_write(motor_b_pin, PIN_LOW);
    rt_pin_write(motor_c_pin, PIN_HIGH);
    rt_pin_write(motor_d_pin, PIN_HIGH);
    rt_thread_delay(speed);
    rt_pin_write(motor_d_pin, PIN_LOW);
    rt_pin_write(motor_a_pin, PIN_LOW);
    rt_pin_write(motor_b_pin, PIN_HIGH);
    rt_pin_write(motor_c_pin, PIN_HIGH);
    rt_thread_delay(speed);
    rt_pin_write(motor_c_pin, PIN_LOW);
    rt_pin_write(motor_d_pin, PIN_LOW);
    rt_pin_write(motor_a_pin, PIN_HIGH);
    rt_pin_write(motor_b_pin, PIN_HIGH);
    rt_thread_delay(speed);
    rt_pin_write(motor_b_pin, PIN_LOW);
    rt_pin_write(motor_c_pin, PIN_LOW);
    rt_pin_write(motor_d_pin, PIN_HIGH);
    rt_pin_write(motor_a_pin, PIN_HIGH);
    rt_thread_delay(speed);
}

 void Motorccw(uint8_t speed)
{
    rt_pin_write(motor_a_pin, PIN_HIGH);
    rt_pin_write(motor_b_pin, PIN_HIGH);
    rt_pin_write(motor_c_pin, PIN_LOW);
    rt_pin_write(motor_d_pin, PIN_LOW);
    rt_thread_delay(speed);
    rt_pin_write(motor_b_pin, PIN_HIGH);
    rt_pin_write(motor_c_pin, PIN_HIGH);
    rt_pin_write(motor_d_pin, PIN_LOW);
    rt_pin_write(motor_a_pin, PIN_LOW);
    rt_thread_delay(speed);
    rt_pin_write(motor_c_pin, PIN_HIGH);
    rt_pin_write(motor_d_pin, PIN_HIGH);
    rt_pin_write(motor_a_pin, PIN_LOW);
    rt_pin_write(motor_b_pin, PIN_LOW);
    rt_thread_delay(speed);
    rt_pin_write(motor_d_pin, PIN_HIGH);
    rt_pin_write(motor_a_pin, PIN_HIGH);
    rt_pin_write(motor_b_pin, PIN_LOW);
    rt_pin_write(motor_c_pin, PIN_LOW);
    rt_thread_delay(speed);
}

 //����   *һ������*   *�����*  ת0.08789�ȣ����ʵת0.08789*64=5.625�ȣ�����������Ϊ5.625�ȡ�
 //��ת��A-B-C-DΪ  *8������*  ����0.08789*8=0.70312�ȡ�����A-B-C-DΪһ�����ڣ���jΪ��Ҫ��ת��angle�Ƕ��������������
 void Motorcw_angle(int angle,int speed)
 {
     int i,j;
     j=(int)(angle/0.70312);
     for(i=0;i<j;i++)
     {
         Motorcw(speed);
     }
 }

 void Motorccw_angle(int angle,int speed)
 {
     int i,j;
     j=(int)(angle/0.70312);
     for(i=0;i<j;i++)
     {
         Motorccw(speed);
     }
 }

 void motor_stop(void)
{
    rt_pin_write(motor_a_pin, PIN_LOW);
    rt_pin_write(motor_b_pin, PIN_LOW);
    rt_pin_write(motor_c_pin, PIN_LOW);
    rt_pin_write(motor_d_pin, PIN_LOW);
}
