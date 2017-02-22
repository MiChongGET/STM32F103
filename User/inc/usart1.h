#ifndef _USART1_H_
#define _USART1_H_

void USART1_init(int bound);
void USART1_Sendbyte(char data);
char USART1_Receivebyte(void);


#endif