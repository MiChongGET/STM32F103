#include "stm32f10x.h"
#include "beep.h"
//观察原理图 找到管脚
//查看系统框架 找到管脚对应的时钟线 （第二章）
//配置时钟 （第六章）
//配置io口 （第八章）
//配置输出数据寄存器 （第八章）

void BEEN(){
		RCC -> APB2ENR |= (1<<3); //打开时钟PB
	  GPIOB->CRH &= ~(0xf);
		GPIOB->CRH |= 0x3;
	while(1){
		GPIOB->ODR |= (1<<8);//响
		delay_been(5000000);
		GPIOB->ODR &= ~(1<<8);//不响
		delay_been(5000000);
		}
	}
	void delay_been(int time){
	 while(time--);
	 }