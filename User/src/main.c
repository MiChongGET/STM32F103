#include "stm32f10x.h"
#include "led.h"
#include "beep.h"
#include "key.h"
int main()
	{
		//打开时钟
		//Led_init();
		//闪烁
		//LED_SS();
		
		//流水灯
		//LED_LS();
		
		//呼吸灯
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

	