#include "stm32f10x.h"

void delay(u32 time){
		while(time--);
	}
int main()
	{
		//��ʱ��PB PE PA
		RCC -> APB2ENR |= (1<<3); //��ʱ��PB
		RCC -> APB2ENR |= (1<<2); //��ʱ��PA
		RCC -> APB2ENR |= (1<<6); //��ʱ��PE
		/*RCC -> APB2END |= (1<<2)|(1<<3)|(1<<6)*/
		
		//����GPIO��PB5 PE5 PA5 PA6Ϊ�������ģʽ
		//���PB5�ĳ�ʼֵ
		GPIOB->CRL &= ~(0xf<<20);
		//����PB5Ϊ �������
		GPIOB->CRL |= (0X3<<20);
		//���ö˿�����Ĵ���
		
		//���PE5�ĳ�ʼֵ
		GPIOE ->CRL &=~(0xf<<(4*5));
			//����PE5Ϊ �������
		GPIOE->CRL |= (0X3<<20);
		
		//���PA5�ĳ�ʼֵ
		GPIOA ->CRL &=~(0xf<<(4*5));
			//����PA5Ϊ �������
		GPIOA ->CRL |= (0X3<<20);
		
		//���PA6�ĳ�ʼֵ
		GPIOA ->CRL &=~(0xf<<(4*6));
			//����PA6Ϊ �������
		GPIOA ->CRL |= (0X3<<24);
		
		
		//����LED��
		while(1){
		//��ȫ��
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

	