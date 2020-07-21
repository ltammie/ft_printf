#include "includes/ft_printf.h"

int			percent_pr(t_cp *z)
{
	if (z->minus_flag == 1)
	{
		ft_putchar('%');
		print_width(z->width, ' ');
	}
	else
	{
		print_width(z->width, ' ');
		ft_putchar('%');
	}
	return (0);
}
