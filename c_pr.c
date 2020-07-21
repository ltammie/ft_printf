#include "includes/ft_printf.h"

int			c_pr(t_cp *z, va_list ap)
{
	char c;

	c = va_arg(ap, int);
	if (z->minus_flag == 1)
	{
		ft_putchar(c);
		print_width(z->width - 1, ' ');
	}
	else
	{
		print_width(z->width - 1, ' ');
		ft_putchar(c);
	}
	return (0);
}
