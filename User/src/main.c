#include "stm32f10x.h"
#include "led.h"

int main()
	{
		//打开时钟
		Led_init();
		//闪烁
		//LED_SS();
		
		//流水灯
		LED_LS();
	}

	