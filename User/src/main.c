#include "stm32f10x.h"

void delay(u32 time){
		while(time--);
	}
int main()
	{
		//��ʱ��
		RCC -> APB2ENR |= (1<<3);
		//����GPIO��PB5Ϊ���ģʽ
		//���PB5�ĳ�ʼֵ
		GPIOB->CRL &= ~(0xf<<20);
		//����PB5Ϊ �������
		GPIOB->CRL |= (0X3<<20);
		//���ö˿�����Ĵ���
		//����LED��
		while(1){
		GPIOB->ODR |= (1<<5);
		delay(500000);
		GPIOB->ODR &= ~(1<<5);
		delay(500000);
		}
	}