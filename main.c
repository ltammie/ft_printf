#include "includes/ft_printf.h"

int 	main(void)
{
//	ft_printf("mine str|%-*.1s\n", 3, "ez");
//	printf("orig str|%-*.1s\n", 3, "ez");

//	ft_printf("mine str|%-20.3s\n", "abcde");
//	printf("orig str|%-20.3s\n", "abcde");

	ft_printf("mine str|%+10.0d\n", 0);
	printf("orig str|%+.0d\n", 0);
	return (0);
}
