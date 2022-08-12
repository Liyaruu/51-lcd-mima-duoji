#include "time.h"
#include "main.h"

uchar count=0;
uchar timer1;

void delay1s()
{
	uchar a,b,c;
	for(c=167;c>0;c--)
	for(b=171;b>0;b--)
	for(a=16;a>0;a--);
	_nop_();
}

void time0_Init()
{
	 EA=1;
	TMOD&=0x00;
	TMOD|=0x01;
	TH0=0xff;
	TL0=0xa4;
	ET0=1;
	TR0=1;
}

void time0Init() interrupt 1
{
 TR0=0;
	TH0=0xff;
	TL0=0xa4;
	if(count<=timer1)
		PWM=1;
	else
		PWM=0;
	count++;
	if(count>=200)//T=20ms
		count=0;
	TR0=1;
}	