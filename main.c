#include "includes/ft_printf.h"

int 	main(void)
{
	ft_printf("mine str|%*.000000003s\n", -5, "cake");
	printf("orig str|%*.000000003s\n", -5, "cake");
	return (0);
}
