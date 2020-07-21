#include "includes/ft_printf.h"

static void print_width(int width)
{
	int i;

	i = 0;
	while (++i < width)
		ft_putchar(' ');

}

int			c_pr(t_cp *z, va_list ap)
{
	char c;

	c = va_arg(ap, int);
	if (z->minus_flag == 1)
	{
		ft_putchar(c);
		print_width(z->width);
	}
	else
	{
		print_width(z->width);
		ft_putchar(c);
	}
	return (0);
}
