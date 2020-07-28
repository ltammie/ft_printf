#include "includes/ft_printf.h"


//delete
#include <math.h>

int 	main(void)
{
//	ft_printf("mine str|%-*.1s\n", 3, "ez");
//	printf("orig str|%-*.1s\n", 3, "ez");

//	ft_printf("mine str|%s\n", "abcde");
//	printf("orig str|%s\n", "abcde");

	printf("o|%.6f\n", 1201.5f);
	ft_printf("m|%.6f\n", 1201.5f);
}
