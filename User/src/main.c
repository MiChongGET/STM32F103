#include "stm32f10x.h"
#include "stdio.h"

void delay(u32 time){
		while(time--);
	}
int main()
	{
		//��ʱ��
		RCC -> APB2ENR |= 1<<3;
		//����GPIO��PB5Ϊ���ģʽ
		GPIOB->CRL &= ~(0xf<<20);
		GPIOB->CRL |= 3<<30;
		//���ö˿�����Ĵ���
		//����LED��
		while(1){
		GPIOB->ODR |= 1<<5;
		delay(500000);
		GPIOB->ODR |= ~(1<<5);
		delay(500000);
		}
	}