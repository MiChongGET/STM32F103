#include "stm32f10x.h"
#include "stdio.h"

void USART1_init(u32 bound)
{
	// b=9.6   int a a=b  ȡ�������ֵĹ���
		double temp;
		int Mantissa;
		int Fraction;
		temp = (double)(72000000)/(16*bound);//ǿ������ת��Ϊdouble��
		Mantissa = temp;
		Fraction = (temp-Mantissa)*16;
	
		//���ô���
		RCC->APB2ENR |=(1<<2);//��PAʱ��
		RCC->APB2ENR |=(1<<14);//�򿪴���ʱ��
	
	//����IO��		PA9	PA10
		GPIOA->CRH &=0xfffff00f;  //~(0xff<<4)λ������ʽ
		GPIOA->CRH |=0x000004B0;  // |=(0x4B<<4)����TX,RX���������ģʽ,��������,���츴�����
	
	//���üĴ���
  	USART1 ->BRR |=(Mantissa<<4)|Fraction;
			
		USART1 ->CR1 |=(0x200c);            //(1<<13);  //����ʹ��,
		
}

	void USART1_Sendbyte(char data)
	{
		//�ȴ���һ�η����������
		while((USART1->SR&(1<<6))==0);
		//�����´�����
		USART1->DR = data;
	} //���ͺ���
	
	
	char USART1_Receivebyte(void)
	{
			//�ȴ����ݽ������
		char data;
		while ((USART1->SR&(1<<5))==0);
		data = USART1->DR;
		return data;
		
	}  //���պ���
	
	
#if 1
#pragma import(__use_no_semihosting)             
	//��׼����Ҫ��֧�ֺ���                 
struct __FILE 
{ 
	int handle; 
		/* Whatever you require here. If the only file you are using is */ 
		/* standard output using printf() for debugging, no file handling */ 
		/* is required. */ 
}; 
	/* FILE is typedef�� d in stdio.h. */ 
 FILE __stdout;       
	//����_sys_exit()�Ա���ʹ�ð�����ģʽ    
 _sys_exit(int x) 
	{ 
		x = x; 
	} 
	//�ض���fputc����
	//printf�������ָ��fputc����fputc���������
	//����ʹ�ô���1(USART1)���printf��Ϣ
	int fputc(int ch, FILE *f)
	{      
		while((USART1->SR&0X40)==0);//�ȴ���һ�δ������ݷ������  
		USART1->DR = (u8) ch;      	//дDR,����1����������
		return ch;
	}
	#endif 
