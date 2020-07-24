#include "includes/ft_printf.h"


//delete
#include <math.h>

int 	main(void)
{
//	ft_printf("mine str|%-*.1s\n", 3, "ez");
//	printf("orig str|%-*.1s\n", 3, "ez");

//	ft_printf("mine str|%s\n", "abcde");
//	printf("orig str|%s\n", "abcde");

	printf("o|%010.1p\n", 0);
	ft_printf("m|%010.1p\n", 0);

//	float	n;
////	int 	S;
//	int 	M;
//	float 	E;
//
//	n = 23.23f;
//
//	M = (int)n;
//	printf("M = %d\n", M);
//	E = log2f(n);
//	printf("E = %f\n", E);
//	E = powf(2, E);
//	printf("number_back = %f\n", E);
//	return (0);
}
