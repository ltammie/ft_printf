#include "includes/ft_printf.h"

int 	main(void)
{
	ft_printf("mine str|%*.*%|%+# 0-*.1s\n", -10, -3, 3, "ez");
	printf("orig str|%*.*%|%-*.1s\n", -10, -3, 3, "ez");
	return (0);
}
