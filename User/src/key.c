#include "stm32f10x.h"
#include "key.h"

void KEY(){
	RCC -> APB2ENR |= (1<<2); //��ʱ��PA
	RCC -> APB2ENR |= (1<<6); //��ʱ��PE
	
	GPIOA ->CRL &= ~(0Xf);
	}

void UP(){}
void DOWN(){}
void RIGHT(){}
void LEFT(){}