#include "includes/ft_printf.h"

int 	main(void)
{
	printf("mine:\n");
	ft_printf("hello world %00000+++++---4d\n", 15);
	printf("orig:\n");
	printf("hello world %00000+++++---4d\n", 15);
	return (0);
}
