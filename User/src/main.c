#include "stm32f10x.h"
#include "led.h"
#include "beep.h"
#include "key.h"
int main()
	{
		//��ʱ��
		//Led_init();
		//��˸
		//LED_SS();
		
		//��ˮ��
		//LED_LS();
		
		//������
		//while(1){
		//LED_HX(4000);
		//}
		
		//BEEN();
		KEY();
		while(1){
			if((GPIOA->IDR &(1<<0))==0){
				LED_LS();
			}
		}
	}

	