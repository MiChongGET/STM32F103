#include "stm32f10x.h"
#include "led.h"
#include "beep.h"
#include "key.h"
int main()
	{
		int key_value;
		//打开时钟
		Led_init();
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
			
				key_value = Get_key_value();
				switch(key_value){
					case 1:LED_HX(5000);break;
					case 2:LED_LS(); break;
					case 3:LED_SS(); break;
					case 4:BEEP(); break;
				}
		}
	}

	