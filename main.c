#include "includes/ft_printf.h"

int 	main(void)
{
//	ft_printf("mine str|%-*.1s\n", 3, "ez");
//	printf("orig str|%-*.1s\n", 3, "ez");

	ft_printf("mine str|%#.3x\n", 0);
	printf("orig str|%#.3x\n", 0);
	return (0);
}
