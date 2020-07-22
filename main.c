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
	printf("o|%#037lX\n", 22337203685477ul);
	ft_printf("m|%#037l\nX", 22337203685477ul);

	return (0);
}
