#include "includes/ft_printf.h"

unsigned long long	u_cast(t_cp *z, va_list ap)
{
	unsigned int	n;

	if (z->ll_flag)
		return ((unsigned long long)va_arg(ap, unsigned long long));
	else if (z->l_flag)
		return ((unsigned long long)va_arg(ap, unsigned long));
	else if (z->hh_flag)
		n = (unsigned int)((unsigned char)va_arg(ap, unsigned int));
	else if (z->h_flag)
		n = (unsigned int)((unsigned short)va_arg(ap, unsigned int));
	else
		n = (unsigned int)va_arg(ap, unsigned int);
	return ((unsigned long long)n);
}
