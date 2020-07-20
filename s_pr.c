#include "includes/ft_printf.h"

static void print_width(int width)
{
	int i;

	i = -1;
	while (++i < width)
		ft_putchar(' ');

}

int			s_pr(t_cp z, va_list ap)
{
	char	*s;
	size_t	len;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	s[z.precision] = '\0';
	len = ft_strlen(s);
	if (z.minus_flag == 1)
	{
		ft_putstr(s);
		print_width(z.width - len);
	}
	else
	{
		print_width(z.width - len);
		ft_putstr(s);
	}
	return (0);
}

