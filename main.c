#include "includes/ft_printf.h"

int 	main(void)
{
//	ft_printf("mine str|%-*.1s\n", 3, "ez");
//	printf("orig str|%-*.1s\n", 3, "ez");

//	ft_printf("mine str|%-20.3s\n", "abcde");
//	printf("orig str|%-20.3s\n", "abcde");

	ft_printf("mine str|%07d\n", -54);
	printf("orig str|%07d\n", -54);
	return (0);
}
