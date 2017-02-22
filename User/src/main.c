#include "stm32f10x.h"
#include "led.h"
#include "beep.h"
#include "key.h"
#include "usart1.h"
#include "stdio.h"
int main()
	{
		int data;
		int key_value;
//		//打开时钟
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
	
//		KEY();
//		
//		while(1){
//			
//				key_value = Get_key_value();
//				switch(key_value){
//					case 1:LED_HX(5000);break;
//					case 2:LED_LS(); break;
//					case 3:LED_SS(); break;
//					case 4:BEEP(); break;
//				}
//		}
   

		//串口通信
		USART1_init(9600);
		
		
		while(1){
			//发送字母a会使得蜂鸣器响
//			data = USART1_Receivebyte();
//			if(data == 'a'){
//			BEEP(50000);
//			
//			}
			printf("赵晓东");
		}
	}

	