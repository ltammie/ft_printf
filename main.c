#include "includes/ft_printf.h"

int 	main(void)
{
	ft_printf("mine str|%-*.1s\n", 3, "ez");
	printf("orig str|%-*.1s\n", 3, "ez");

//	ft_printf("mine str|%u\n", -2);
//	printf("orig str|%020u\n", -2);
	return (0);
}
