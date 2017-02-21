#include "stm32f10x.h"
#include "key.h"

void KEY(){
	RCC -> APB2ENR |= (1<<2); //打开时钟PA
	RCC -> APB2ENR |= (1<<6); //打开时钟PE
	
	GPIOA ->CRL &= ~(0Xf);
	}

void UP(){}
void DOWN(){}
void RIGHT(){}
void LEFT(){}