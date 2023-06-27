#ifndef MOTOR_H_
#define MOTOR_H_

#define motor_a_pin 51
#define motor_b_pin 52
#define motor_c_pin 53
#define motor_d_pin 54

typedef unsigned char uint8_t;
typedef unsigned int uint;

void Moto_Init(void);
void Motorcw(uint speed);
void Motorcw(uint speed);
void Motorccw(uint8_t speed);
void Motorcw_angle(int angle,int speed);  //步进电机正转角度函数
void Motorccw_angle(int angle,int speed); //步进电机反转角度函数
void motor_stop(void);

#endif /* MOTOR_H_ */
