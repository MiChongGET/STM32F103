#include "stm32f10x.h"
#include "key.h"

extern void delay(int time);

void KEY(void){
	RCC -> APB2ENR |= (1<<2); //打开时钟PA
	RCC -> APB2ENR |= (1<<6); //打开时钟PE
	
	//PA0
	GPIOA ->CRL &= ~(0xf<<0);
	GPIOA ->CRL |=  (0x04);

	
	//PE2
	GPIOE ->CRL &= ~(0xf<<8);
	GPIOE->CRL |= (0x04<<8);

	//PE3
	GPIOE ->CRL &= ~(0xf<<12);
	GPIOE->CRL |= (0x04<<12);

	
	//PE4
	GPIOE ->CRL &= ~(0xf<<16);
	GPIOE->CRL |= (0x04<<16);

	
	}
int Get_key_value(void)
{
	static int a=1;
	if((a==1)&&(KEY_UP==0||KEY_LEFT!=0||KEY_DOWN==0||KEY_RIGTH==0))//有按键按下
	{
		a=0;
		//延时消抖
		delay(100);
		if(KEY_UP==0)    return 1; //PA0
		if(KEY_LEFT!=0)  return 2; //PE2
		if(KEY_DOWN==0)  return 3; //PE3
		if(KEY_RIGTH==0) return 4; //PE4
	}
	else if(KEY_UP!=0||KEY_LEFT==0||KEY_DOWN!=0||KEY_RIGTH!=0)//按键抬起
	{
		a=1;
	}
	return 0;
}
