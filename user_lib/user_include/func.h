
#include "stm32f2xx.h"
#include "stm32f2xx_usart.h"
#include "Define.h"

void printd(char *p);

void uart_init(void);
u8 uart_receive_char(void);
void uart_send_char(u8 ch);
