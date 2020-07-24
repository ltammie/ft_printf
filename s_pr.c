#include "includes/ft_printf.h"

void		s_pr(t_cp *z, va_list ap)
{
	char	*s;
	int		len;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	len = (int)ft_strlen(s);
	z->precision = z->precision < 0 ? len : z->precision;
	z->precision = z->precision < len ? z->precision : len;
	s = ft_strsub(s, 0, z->precision);
	len = ft_strlen(s);
	z->n_chars += len;
	if (z->minus_flag == 1)
	{
		ft_putstr(s);
		z->n_chars += print_width(z->width - len, ' ');
	}
	else
	{
		z->n_chars += print_width(z->width - len, z->zero_flag ? '0' : ' ');
		ft_putstr(s);
	}
}

