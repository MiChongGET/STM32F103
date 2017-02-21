#ifndef _KEY_H_
#define _KEY_H_
#define KEY_UP   (GPIOA->IDR &(1<<0))  //PA0
#define KEY_LEFT (GPIOE->IDR &(1<<2)) //PE2
#define KEY_DOWN (GPIOE->IDR &(1<<3)) //PE3
#define KEY_RIGTH (GPIOE->IDR &(1<<4))//PE4
int Get_key_value(void);
void KEY(void);
#endif