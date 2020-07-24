#include "includes/ft_printf.h"

void		c_pr(t_cp *z, va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	if (z->minus_flag == 1)
	{
		ft_putchar(c);
		z->n_chars++;
		z->n_chars += print_width(z->width - 1, ' ');
	}
	else
	{
		z->n_chars += print_width(z->width - 1, ' ');
		ft_putchar(c);
		z->n_chars ++;
	}
}
