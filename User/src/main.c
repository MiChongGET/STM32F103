#include "stm32f10x.h"
#include "led.h"

int main()
	{
		//��ʱ��
		Led_init();
		//��˸
		//LED_SS();
		
		//��ˮ��
		//LED_LS();
		
		//������
		while(1){
		LED_HX(3,1000);
		}
	}

	