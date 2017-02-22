#include "stm32f10x.h"
#include "stdio.h"

void USART1_init(u32 bound)
{
	// b=9.6   int a a=b  取整数部分的功能
		double temp;
		int Mantissa;
		int Fraction;
		temp = (double)(72000000)/(16*bound);//强制类型转换为double型
		Mantissa = temp;
		Fraction = (temp-Mantissa)*16;
	
		//配置串口
		RCC->APB2ENR |=(1<<2);//打开PA时钟
		RCC->APB2ENR |=(1<<14);//打开串口时钟
	
	//配置IO口		PA9	PA10
		GPIOA->CRH &=0xfffff00f;  //~(0xff<<4)位操作方式
		GPIOA->CRH |=0x000004B0;  // |=(0x4B<<4)配置TX,RX的输入输出模式,浮空输入,推挽复用输出
	
	//配置寄存器
  	USART1 ->BRR |=(Mantissa<<4)|Fraction;
			
		USART1 ->CR1 |=(0x200c);            //(1<<13);  //串口使能,
		
}

	void USART1_Sendbyte(char data)
	{
		//等待上一次发送数据完成
		while((USART1->SR&(1<<6))==0);
		//发送下次数据
		USART1->DR = data;
	} //发送函数
	
	
	char USART1_Receivebyte(void)
	{
			//等待数据接收完成
		char data;
		while ((USART1->SR&(1<<5))==0);
		data = USART1->DR;
		return data;
		
	}  //接收函数
	
	
#if 1
#pragma import(__use_no_semihosting)             
	//标准库需要的支持函数                 
struct __FILE 
{ 
	int handle; 
		/* Whatever you require here. If the only file you are using is */ 
		/* standard output using printf() for debugging, no file handling */ 
		/* is required. */ 
}; 
	/* FILE is typedef’ d in stdio.h. */ 
 FILE __stdout;       
	//定义_sys_exit()以避免使用半主机模式    
 _sys_exit(int x) 
	{ 
		x = x; 
	} 
	//重定向fputc函数
	//printf的输出，指向fputc，由fputc输出到串口
	//这里使用串口1(USART1)输出printf信息
	int fputc(int ch, FILE *f)
	{      
		while((USART1->SR&0X40)==0);//等待上一次串口数据发送完成  
		USART1->DR = (u8) ch;      	//写DR,串口1将发送数据
		return ch;
	}
	#endif 
