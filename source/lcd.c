#include "lcd.h"
#include "main.h"

//判断液晶忙，并等待
void Read_Busy()
{
	uchar busy;
	LCD1602_DB = 0xff;
	LCD1602_RS = 0;
	LCD1602_RW = 1;
	do
	{
		LCD1602_EN = 1;
		busy = LCD1602_DB;
		LCD1602_EN = 0;
	}while(busy & 0x80); 
}

//写命令
void LCD1602_Write_Cmd(uchar cmd)
{
	Read_Busy();
	LCD1602_RS = 0;	 
	LCD1602_RW = 0;
	LCD1602_DB = cmd;
	LCD1602_EN = 1;	
	LCD1602_EN = 0;	
}

//写数据
void LCD1602_Write_Dat(uchar dat)
{
	Read_Busy();
	LCD1602_RS = 1;
	LCD1602_RW = 0;	
	LCD1602_DB = dat; 
	LCD1602_EN = 1;	
	LCD1602_EN = 0;	
}

////清屏
//void LCD1602_Clear_Screen()
//{
//	LCD1602_Write_Cmd(0x01);
//}

////打开光标闪烁
//void LCD1602_Open_Cursor()
//{
//	LCD1602_Write_Cmd(0x0F);
//}

////关闭光标显示
//void LCD1602_Close_Cursor()
//{
//	LCD1602_Write_Cmd(0x0C);
//}

//指定位置显示坐标
void LCD1602_Set_Cursor(uchar x, uchar y)
{
	if(y) x |= 0x40;//y=1
	x |= 0x80;
	LCD1602_Write_Cmd(x);
}

////在指定位置显示一个字符
//void LCD1602_Dis_OneChar(uchar x, uchar y, uchar dat)
//{
//	LCD1602_Set_Cursor(x, y);
//	LCD1602_Write_Dat(dat);	
//}

//在指定位置显示字符串
void LCD1602_Dis_Str(uchar x, uchar y, uchar *str)
{
	LCD1602_Set_Cursor(x, y);
	while(*str != '\0')	 
	{
		LCD1602_Write_Dat(*str++);
	}
}

//LCD1602初始化
void Init_LCD1602()
{
	LCD1602_Write_Cmd(0x38);
	LCD1602_Write_Cmd(0x0c);
	LCD1602_Write_Cmd(0x06);
	LCD1602_Write_Cmd(0x01);
}
