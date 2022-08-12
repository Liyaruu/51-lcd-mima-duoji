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

	
/*�������λ*/
sbit PWM=P3^7;
/*LCD1602Һ������*/
#define LCD1602_DB P0
sbit LCD1602_RS = P3^5;		//��������ѡ������
sbit LCD1602_RW = P3^6;		//��/дѡ������
sbit LCD1602_EN = P3^4;	 	//ʹ������

/*����������*/
sbit BUZZER=P2^3;

/*���������*/
sbit DU=P2^6;
sbit WE=P2^7;

/*������������*/
sbit S2=P3^0;
sbit S3=P3^1;

extern bit allow,genggai,ok,wanbi,retry,close;	//����״̬λ
#endif