#include "includes/ft_printf.h"

void		percent_pr(t_cp *z)
{
	if (z->minus_flag == 1)
	{
		ft_putchar('%');
		z->n_chars++;
		z->n_chars += print_width(z->width - 1, z->zero_flag == 1 ? '0' : ' ');
	}
	else
	{
		z->n_chars += print_width(z->width - 1, z->zero_flag == 1 ? '0' : ' ');
		ft_putchar('%');
		z->n_chars++;
	}
}
