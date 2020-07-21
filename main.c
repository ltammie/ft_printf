#include "includes/ft_printf.h"

int 	main(void)
{
//	ft_printf("mine str|%-*.1s\n", 3, "ez");
//	printf("orig str|%-*.1s\n", 3, "ez");

	ft_printf("mine str|%5.5u\n", -27);
	printf("orig str|%5.5d\n", -27);
	return (0);
}
