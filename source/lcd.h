#ifndef _LCD_H
#define _LCD_H
#include "main.h"


void Init_LCD1602();// LCD��ʼ��
void LCD1602_Dis_Str(uchar x, unsigned char y, unsigned char *str);//LCD1602д�ַ���
//void LCD1602_Dis_OneChar(unsigned char x, unsigned char y, unsigned char	 dat);	//LCD1602дһ���ֽڵ�����
void LCD1602_Set_Cursor(unsigned char x, unsigned char y);//LCD1602���ù����ʾλ��
//void LCD1602_Clear_Screen();//����




#endif