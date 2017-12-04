
/***************************************
*	author: Dong
*	specification: uart func
****************************************/

#include "stm32f2xx.h"
#include "stm32f2xx_gpio.h"
#include "stm32f2xx.h"
#include "stm32f2xx_usart.h"
#include "stm32f2xx_rcc.h"
#include "func.h"

/***************************************
* Name  : USART1_GPIO_Configuration
* Deion : Configures the uart1 gpio ports
* Input : None
* Output: None
* Return: None
****************************************/
void USART1_GPIO_Configuration(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
	
		RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC, ENABLE);
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_USART1, ENABLE);
		RCC_APB1PeriphClockCmd( RCC_APB2Periph_USART1, ENABLE);
		RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOA, ENABLE);
	
		/* Configure USART1_Tx as alternate push-pull */
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	
		/* Configure USART1_Rx as input floating */
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
//		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
}

/***************************************
* Name  :  USART1_Configuration
* Deion :  Configures the uart1
* Input :  None
* Output:  None
* Return:  None
****************************************/
void USART1_Configuration(void)
{
		USART_InitTypeDef USART_InitStructure;
	
		USART_InitStructure.USART_BaudRate = 115200;
		USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		USART_InitStructure.USART_StopBits = USART_StopBits_1;
		USART_InitStructure.USART_Parity = USART_Parity_No;
		USART_InitStructure.USART_HardwareFlowControl =USART_HardwareFlowControl_None;	
		USART_InitStructure.USART_Mode	=	USART_Mode_Rx | USART_Mode_Tx;
	
		/* Init the uart1 */
		USART_Init(USART1, &USART_InitStructure);
	
		/* Enable uart1 receive and send interrupts */
		/* USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); */
	
		/* Enable uart1 */
		USART_Cmd(USART1, ENABLE);
}

void USART1_send_char(u8 ch)
{
		USART_SendData(USART1, ch);
		while(!USART_GetFlagStatus(USART1, USART_FLAG_TXE));
}

u8 USART1_receive_char(void)
{
		while(!USART_GetFlagStatus(USART1, USART_FLAG_RXNE));
		return USART_ReceiveData(USART1);
}
void uart_send_char(u8 ch)
{
	USART1_send_char(ch);
}
u8 uart_receive_char(void)
{
	return USART1_receive_char();
}

void uart_init(void)
{
	USART1_GPIO_Configuration();
	
	USART1_Configuration();
}
