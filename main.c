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

	printf("o|%.0f\n", 5.0f);
	ft_printf("m|%f\n", 5.0f);
}
