#include "func.h"

void printd(char *p)
{
#ifdef USER_DEBUG
	char *str = p;
	int index = 0;
	
	while(*(str + index) != '\0' && *(str + index) != 'N')
	{
		uart_send_char(*(str + index));
		index = index + 1;
	}
#else
	;
#endif
}
