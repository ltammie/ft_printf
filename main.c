#include "includes/ft_printf.h"

int 	main(void)
{
//	ft_printf("mine str|%-*.1s\n", 3, "ez");
//	printf("orig str|%-*.1s\n", 3, "ez");

//	ft_printf("mine str|%-20.3s\n", "abcde");
//	printf("orig str|%-20.3s\n", "abcde");

	unsigned short us;

	us = 10;
	ft_printf("m|%5hu\n", (unsigned short)12);
	printf("o|%5hu\n", (unsigned short)12);
	return (0);
}
