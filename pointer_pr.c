#include "includes/ft_printf.h"

int 	pointer_pr(t_cp *z, va_list ap)
{
	void *p;

	p = (void*)va_arg(ap, void*);
	printf("%llu\n",(unsigned long long)p);
	if (z->precision)
		;
	return (0);
}

