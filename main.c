#include "includes/ft_printf.h"

int 	main(void)
{
//	ft_printf("mine char|%3c\n", 'e');
//	printf("orig char|%3c\n", 'e');

	ft_printf("mine str|%10.3s\n", NULL);
	printf("orig str|%10.3s\n", NULL);
	return (0);
}
