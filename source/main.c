#define _MAIN_C
#include "main.h"
#include "mima.h"
#include "time.h"
#include "lcd.h"


void main()
{
	uchar StartStr[]={"Enter the password:"};
	uchar passwordStr[]={"------"};
	uchar correctStr[]={"Correct Password"};
	uchar wrongStr[]={"Wrong Password"};
	uchar n;
	uchar k=0,g=0,h=0,i=0;
	DU=0;
	WE=0;
	time0_Init();//定时器初始化
	EA=0;
	
	while(1)
	{ 
		if(h==0)
		{
			Init_LCD1602();//LCD1602初始化
			LCD1602_Dis_Str(0,0,StartStr);
			LCD1602_Dis_Str(0,1,passwordStr);
			h=1;
		}
		keyscan();
		shumima();
		yanzheng();
		if(allow)
		{
			if(k==0)
			{
			Init_LCD1602();
			delay(5);
			LCD1602_Dis_Str(0,0,correctStr);
			}
			k=1;
			if(S2==0)
			{
				delay(20);
				if(S2==0)
				{
				EA=1;
				timer1=12;
				count=0;
				delay1s();
				EA=0;
					while(!S2);
				}
			}
			if(S3==0)
			{
				delay(20);
				if(S3==0)
				{
				EA=1;
				timer1=5;
				count=0;
				delay1s();
				EA=0;
					while(!S3);
				}
			}
			if(!genggai)
				wanbi=0;
		}
		if(wanbi==1&&allow==0)
		{
			if(i==0)
			{
			Init_LCD1602();
			delay(5);
			LCD1602_Dis_Str(0,0,wrongStr);
			i=1;
			}
		}
		if(genggai)
		{
			if(allow)
			{  
				if(g==0)
				{
				Init_LCD1602();
				LCD1602_Dis_Str(0,0,StartStr);
				for(n=0;n<6;n++)
					exStr[n]='-';
				}
				while(!wanbi)
				{
					
				 	keyscan();
					shumima();
					if(retry|close)
					{	wanbi=1;
						break;
					}
					if(g==0)
					LCD1602_Dis_Str(0,1,exStr);
					g=1;
				}
			}
		}
		if(ok)
		{	
			ok=0; wei=0;
			genggai=0;
			for(n=0;n<6;n++)
			{
				 oldStr[n]=newStr[n];
				exStr[n]='-';
			}
		}
		if(retry)
		{
		retry=0; wei=0;wanbi=0;
		for(n=0;n<6;n++)
			{
				 oldStr[n]='0';
				exStr[n]='-';
			}		
		}
		if(close)
		{
			close=0;genggai=0;
			wei=0;	wanbi=0;
			allow=0;g=0;k=0;
			h=0;i=0;
			for(n=0;n<6;n++)
			{
				 newStr[n]='0';
				exStr[n]='-';
			}
			
		}
	}
}




