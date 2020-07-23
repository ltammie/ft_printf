#include "includes/ft_printf.h"

int 	main(void)
{
//	ft_printf("mine str|%-*.1s\n", 3, "ez");
//	printf("orig str|%-*.1s\n", 3, "ez");

//	ft_printf("mine str|%s\n", "abcde");
//	printf("orig str|%s\n", "abcde");

//	unsigned short us;
//
//	us = 10;
	printf("o|%+010.d\n", -43);
	ft_printf("m|%+010.d\n", -43);

	return (0);
}
