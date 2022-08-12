#ifndef _MAIN_H
#define _MAIN_H

#include <reg52.h>
#include <intrins.h>
typedef unsigned char uchar;

extern unsigned char wei,key,temp;
extern unsigned char oldStr[];
extern unsigned char newStr[];
extern unsigned char exStr[];
extern uchar count;
extern uchar timer1;

	
/*脉冲调制位*/
sbit PWM=P3^7;
/*LCD1602液晶引脚*/
#define LCD1602_DB P0
sbit LCD1602_RS = P3^5;		//命令数据选择引脚
sbit LCD1602_RW = P3^6;		//读/写选择引脚
sbit LCD1602_EN = P3^4;	 	//使能引脚

/*蜂鸣器引脚*/
sbit BUZZER=P2^3;

/*数码管引脚*/
sbit DU=P2^6;
sbit WE=P2^7;

/*独立键盘引脚*/
sbit S2=P3^0;
sbit S3=P3^1;

extern bit allow,genggai,ok,wanbi,retry,close;	//各个状态位
#endif