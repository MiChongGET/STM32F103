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
//		//��ʱ��
		Led_init();
		//��˸
		//LED_SS();
		
		//��ˮ��
		//LED_LS();
		
		//������
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
   

		//����ͨ��
		USART1_init(9600);
		
		
		while(1){
			//������ĸa��ʹ�÷�������
//			data = USART1_Receivebyte();
//			if(data == 'a'){
//			BEEP(50000);
//			
//			}
			printf("������");
		}
	}

	