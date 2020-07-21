#include "includes/ft_printf.h"

int 	main(void)
{
//	ft_printf("mine str|%-*.1s\n", 3, "ez");
//	printf("orig str|%-*.1s\n", 3, "ez");

	ft_printf("mine str|%5.5u\n", 027);
	printf("orig str|%25.5x\n", 27);
	return (0);
}
