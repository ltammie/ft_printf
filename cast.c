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
	else if (z->hh_flag)
		n = (unsigned int)((unsigned short)va_arg(ap, unsigned int));
	else
		n = (unsigned int)va_arg(ap, unsigned int);
	return ((unsigned long long)n);
}

long long			cast_di(t_cp *z, va_list ap)
{
	if (z->ll_flag)
		return ((long long)va_arg(ap, long long));
	else if (z->l_flag)
		return ((long long)va_arg(ap, long));
	else if (z->hh_flag)
		return ((long long)((char)va_arg(ap, int)));
	else if (z->hh_flag)
		return ((long long)((short)va_arg(ap, int)));
	return ((long long)va_arg(ap, int));
}

long double			cast_f(t_cp *z, va_list ap)
{
	if (z->L_flag)
		return ((long double)va_arg(ap, long double));
	return ((long double)va_arg(ap, double));
}
