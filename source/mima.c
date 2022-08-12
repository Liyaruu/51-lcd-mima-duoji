#include "main.h"
#include "mima.h"
#include "lcd.h"

unsigned char wei,key,temp;
unsigned char oldStr[]={"000000"};
unsigned char newStr[]={"aaaaaa"};
unsigned char exStr[]={"------"};
bit allow,genggai,ok,wanbi,retry,close;

void delay(unsigned char i)
{
	uchar j,k;
  for(j=i;j>0;j--)
    for(k=125;k>0;k--);
}

void keyscan()//扫描矩阵键盘
{
	{
    P3=0xfe;
    temp=P3;
    temp=temp&0xf0;
    if(temp!=0xf0)
    {
      delay(10);
      if(temp!=0xf0)
      {	
        temp=P3;
        switch(temp)
        {
          case 0xee:
               key=0;
			   wei++;
               break;

          case 0xde:
               key=1;
			   wei++;
               break;

          case 0xbe:
               key=2;
			   wei++;
               break;

          case 0x7e:
               key=3;
			   wei++;
               break;
         }
         while(temp!=0xf0) 
        {
           temp=P3;
           temp=temp&0xf0;
         }
      }
    }
    P3=0xfd;
    temp=P3;
    temp=temp&0xf0;
    if(temp!=0xf0)
    {
      delay(10);
      if(temp!=0xf0)
      {
        temp=P3;
        switch(temp)
        {
          case 0xed:
               key=4;
			   wei++;
               break;

          case 0xdd:
               key=5;
			   wei++;
               break;

          case 0xbd:
               key=6;
			   wei++;
               break;

          case 0x7d:
               key=7;
			   wei++;
               break;
         }
         while(temp!=0xf0)
         {
           temp=P3;
           temp=temp&0xf0;
         }
      }
      }
    P3=0xfb;
    temp=P3;
    temp=temp&0xf0;
    if(temp!=0xf0)
    {
      delay(10);
      if(temp!=0xf0)
      {
        temp=P3;
        switch(temp)
        {
          case 0xeb:
               key=8;
			   wei++;
               break;

          case 0xdb:
               key=9;
			   wei++;
               break;
			   
          case 0xbb:
               genggai=1; //S16更改
			   wei=0;
               break;

          case 0x7b:
		  	   if(allow)
               ok=1;//S17为ok
               break;
         }
        while(temp!=0xf0)
         {
           temp=P3;
           temp=temp&0xf0;
         }
      }
      }
	  P3=0xf7;
    temp=P3;
    temp=temp&0xf0;
    if(temp!=0xf0)
    {
      delay(10);
      if(temp!=0xf0)
      {
        temp=P3;
        switch(temp)
        {
          case 0xe7:
		  	   retry=1;//S18重试
               break;

          case 0xd7:
		  	   close=1; //S19关闭
               break;
         }
        while(temp!=0xf0)
         {
           temp=P3;
           temp=temp&0xf0;
         }
      }
      }
}
	}

	void shumima()		//对按键采集来的数据进行分配
{
	if(!wanbi)
	{
	switch(wei)
	{
		case 1:newStr[0]=key+'0'; 
			    if(!allow)
					{
						exStr[0]='*';
					LCD1602_Dis_Str(0,1,exStr);
					}
			   else 
				 {
					 exStr[0]=key+'0';
           LCD1602_Dis_Str(0,1,exStr);
				 }
					 break;
		case 2:newStr[1]=key+'0';
				if(exStr[0]=='*')
				{
					exStr[1]='*';
					LCD1602_Dis_Str(0,1,exStr);
				}
				else 
				{
					exStr[1]=key+'0';
					LCD1602_Dis_Str(0,1,exStr);
				}
					break;
		case 3:newStr[2]=key+'0'; 
				if(exStr[0]=='*') 
				{
					exStr[2]='*';
					LCD1602_Dis_Str(0,1,exStr);
				}
				else 
				{
					exStr[2]=key+'0';
					LCD1602_Dis_Str(0,1,exStr);
				}
					break;
		case 4:newStr[3]=key+'0';
				if(exStr[0]=='*') 
				{
					 exStr[3]='*';
					LCD1602_Dis_Str(0,1,exStr);
				}
				else
				{
					exStr[3]=key+'0';
					LCD1602_Dis_Str(0,1,exStr);
				}
					break;
		case 5:newStr[4]=key+'0'; 
				if(exStr[0]=='*') 
				{
					exStr[4]='*';
					LCD1602_Dis_Str(0,1,exStr);
				}
				else 
				{
					exStr[4]=key+'0';
					LCD1602_Dis_Str(0,1,exStr);
				}
					break;
		case 6:newStr[5]=key+'0'; 
				if(exStr[0]=='*') 
				{
					exStr[5]='*';
					LCD1602_Dis_Str(0,1,exStr);
				}
				else 
				{
					exStr[5]=key+'0';
					LCD1602_Dis_Str(0,1,exStr);
				}
				wanbi=1;
				break;
	}
	}
}
void yanzheng()	  //验证密码是否正确
{
	if(wanbi)
	{
	if((oldStr[0]==newStr[0])&(oldStr[1]==newStr[1])&(oldStr[2]==newStr[2])&(oldStr[3]==newStr[3])&(oldStr[4]==newStr[4])&(oldStr[5]==newStr[5]))
	allow=1;
	}
}