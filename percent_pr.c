#include "includes/ft_printf.h"

int			percent_pr(t_cp *z)
{
	if (z->minus_flag == 1)
	{
		ft_putchar('%');
		print_width(z->width - 1, z->zero_flag == 1 ? '0' : ' ');
	}
	else
	{
		print_width(z->width - 1, z->zero_flag == 1 ? '0' : ' ');
		ft_putchar('%');
	}
	return (0);
}
