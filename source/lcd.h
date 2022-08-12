#ifndef _LCD_H
#define _LCD_H
#include "main.h"


void Init_LCD1602();// LCD初始化
void LCD1602_Dis_Str(uchar x, unsigned char y, unsigned char *str);//LCD1602写字符串
//void LCD1602_Dis_OneChar(unsigned char x, unsigned char y, unsigned char	 dat);	//LCD1602写一个字节的数据
void LCD1602_Set_Cursor(unsigned char x, unsigned char y);//LCD1602设置光标显示位置
//void LCD1602_Clear_Screen();//清屏




#endif