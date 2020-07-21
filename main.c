#include "includes/ft_printf.h"

int 	main(void)
{
//	ft_printf("mine char|%3c\n", 'e');
//	printf("orig char|%3c\n", 'e');

	ft_printf("mine str|%*.*s\n", -5, -3, "cake");
	printf("orig str|%*.*s\n", -5, -3, "cake");
	return (0);
}
