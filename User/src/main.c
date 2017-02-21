#include "stm32f10x.h"

void delay(u32 time){
		while(time--);
	}
int main()
	{
		//打开时钟PB PE PA
		RCC -> APB2ENR |= (1<<3); //打开时钟PB
		RCC -> APB2ENR |= (1<<2); //打开时钟PA
		RCC -> APB2ENR |= (1<<6); //打开时钟PE
		/*RCC -> APB2END |= (1<<2)|(1<<3)|(1<<6)*/
		
		//配置GPIO口PB5 PE5 PA5 PA6为推挽输出模式
		//清除PB5的初始值
		GPIOB->CRL &= ~(0xf<<20);
		//配置PB5为 推挽输出
		GPIOB->CRL |= (0X3<<20);
		//配置端口输出寄存器
		
		//清除PE5的初始值
		GPIOE ->CRL &=~(0xf<<(4*5));
			//配置PE5为 推挽输出
		GPIOE->CRL |= (0X3<<20);
		
		//清除PA5的初始值
		GPIOA ->CRL &=~(0xf<<(4*5));
			//配置PA5为 推挽输出
		GPIOA ->CRL |= (0X3<<20);
		
		//清除PA6的初始值
		GPIOA ->CRL &=~(0xf<<(4*6));
			//配置PA6为 推挽输出
		GPIOA ->CRL |= (0X3<<24);
		
		
		//点亮LED灯
		while(1){
		//灯全灭
		GPIOB->ODR |= (1<<5);
		GPIOE->ODR |= (1<<5);
		GPIOA->ODR |= (1<<5);
		GPIOA->ODR |= (1<<6);
			
			
		delay(500000);
		GPIOB->ODR &= ~(1<<5);
		GPIOE->ODR &= ~(1<<5);
		GPIOA->ODR &= ~(1<<5);
		GPIOA->ODR &= ~(1<<6);
			
		delay(500000);
		}
	}

	