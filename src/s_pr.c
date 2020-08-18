#include "../includes/ft_printf.h"

static	void	ft_putstr_len(char *s, int len)
{
	if (s)
	{
		while (len > 0)
		{
			ft_putchar(*s);
			s++;
			len--;
		}
	}
}

void			s_pr(t_cp *z, va_list ap)
{
	char	*s;
	char	*res;
	int		len;

	s = va_arg(ap, char *);
	len = 0;
	len += !s ? 6 : (int)ft_strlen(s);
	res = !s ? "(null)" : s;
	z->precision = z->precision < 0 ? len : z->precision;
	z->precision = z->precision < len ? z->precision : len;
	z->n_chars += z->precision;
	if (z->minus_flag == 1)
	{
		ft_putstr_len(res, z->precision);
		z->n_chars += print_width(z->width - z->precision, ' ');
	}
	else
	{
		z->n_chars += print_width(z->width - z->precision, z->zero_flag ? '0'
				: ' ');
		ft_putstr_len(res, z->precision);
	}
}
