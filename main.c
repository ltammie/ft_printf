#include "includes/ft_printf.h"


//delete
#include <math.h>

int 	main(void)
{
//	ft_printf("mine str|%-*.1s\n", 3, "ez");
//	printf("orig str|%-*.1s\n", 3, "ez");

//	ft_printf("mine str|%s\n", "abcde");
//	printf("orig str|%s\n", "abcde");

	printf("o|%f\n", 343.63f);
	ft_printf("m|%f\n", 343.63f);
}
