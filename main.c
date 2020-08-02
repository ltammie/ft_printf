#include "includes/ft_printf.h"


//delete
#include <math.h>
#include <float.h>

int 	main(void)
{
//	ft_printf("mine str|%-*.1s\n", 3, "ez");
//	printf("orig str|%-*.1s\n", 3, "ez");

//	ft_printf("mine str|%s\n", "abcde");
//	printf("orig str|%s\n", "abcde");

	printf("o|%.29f\n", 0.029030f);
	ft_printf("m|%f\n", 0.029030f);
}
