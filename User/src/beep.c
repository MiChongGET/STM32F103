#include "stm32f10x.h"
#include "beep.h"
#include "key.h"
//�۲�ԭ��ͼ �ҵ��ܽ�
//�鿴ϵͳ��� �ҵ��ܽŶ�Ӧ��ʱ���� ���ڶ��£�
//����ʱ�� �������£�
//����io�� ���ڰ��£�
//����������ݼĴ��� ���ڰ��£�

void BEEP(){
		RCC -> APB2ENR |= (1<<3); //��ʱ��PB
	  GPIOB->CRH &= ~(0xf);
		GPIOB->CRH |= 0x3;
	while(1){
		
		GPIOB->ODR |= (1<<8);//��
		delay_been(5000000);
		GPIOB->ODR &= ~(1<<8);//����
		delay_been(5000000);
		//���������������
		if(KEY_LEFT!=0||KEY_DOWN==0||KEY_UP==0){
			break;
		}
		}
	}
	void delay_been(int time){
	 while(time--);
	 }