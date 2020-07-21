#include "includes/ft_printf.h"

int			u_pr(t_cp *z, va_list ap)
{
	unsigned int u;

	u = va_arg(ap, unsigned int);
	if (z->precision)
		;
	ft_putstr(ft_utoa(u));
	return (0);
}
