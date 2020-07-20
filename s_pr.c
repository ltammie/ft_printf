#include "includes/ft_printf.h"

int			s_pr(t_cp z, va_list ap)
{
	char *s;
	if (z.arg_type == 's')
		;
	s = va_arg(ap, char *);
//	print_struct(z);
	ft_putstr(s);
	return (0);
}

