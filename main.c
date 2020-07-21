#include "includes/ft_printf.h"

int 	main(void)
{
//	ft_printf("mine str|%-*.1s\n", 3, "ez");
//	printf("orig str|%-*.1s\n", 3, "ez");

	ft_printf("mine str|%20.*u\n", -5, 2356);
	printf("orig str|%20.*u\n", -5, 2356);
	return (0);
}
