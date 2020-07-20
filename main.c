#include "includes/ft_printf.h"

int 	main(void)
{
//	ft_printf("mine char|%3c\n", 'e');
//	printf("orig char|%3c\n", 'e');

	ft_printf("mine str|%.1s\n", "boi");
	printf("orig str|%.1s\n", "boi");
	return (0);
}
