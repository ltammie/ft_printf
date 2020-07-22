#include "includes/ft_printf.h"

int 	main(void)
{
//	ft_printf("mine str|%-*.1s\n", 3, "ez");
//	printf("orig str|%-*.1s\n", 3, "ez");

	ft_printf("mine str|%+010.5d\n", -2);
	printf("orig str|%+010.5d\n", -2);
	return (0);
}
