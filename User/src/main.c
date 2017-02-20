#include "stm32f10x.h"
#include "stdio.h"

void delay(u32 time){
		while(time--);
	}
int main()
	{
		//打开时钟
		RCC -> APB2ENR |= 1<<3;
		//配置GPIO口PB5为输出模式
		GPIOB->CRL &= ~(0xf<<20);
		GPIOB->CRL |= 3<<30;
		//配置端口输出寄存器
		//点亮LED灯
		while(1){
		GPIOB->ODR |= 1<<5;
		delay(500000);
		GPIOB->ODR |= ~(1<<5);
		delay(500000);
		}
	}