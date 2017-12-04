
/***************************************
*	author: Dong
*	specification: uart test
****************************************/

#include "stm32f2xx.h"
#include "stm32f2xx_gpio.h"
#include "stm32f2xx.h"
#include "stm32f2xx_usart.h"
#include "stm32f2xx_rcc.h"
#include "func.h"

int main()
{
	int count = 1000;
	char ch;

	uart_init();
	
	printd("start main");
	while(count)
	{
		ch = uart_receive_char();
		uart_send_char(ch);
		count--;
	}
}
