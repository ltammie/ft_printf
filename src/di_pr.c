#include "../includes/ft_printf.h"

static	void	ft_putstr_index(char *s, int i)
{
	while (i-- > 0)
		s++;
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

static	void	print_str(t_cp *z, char *str, int sign, int flag)
{
	int		index;

	index = str[0] == '-' ? 1 : 0;
	if (z->minus_flag)
	{
		!sign && z->sf ? ft_putchar(' ') : 0;
		str[0] == '-' ? ft_putchar('-') : 0;
		sign && str[0] != '-' ? ft_putchar('+') : 0;
		print_width(z->precision, z->precision_flag ? '0' : ' ');
		flag ? ft_putstr("") : ft_putstr_index(str, index);
		print_width(z->width, ' ');
	}
	else
	{
		!z->zero_flag ? print_width(z->width, ' ') : 0;
		!sign && z->sf ? ft_putchar(' ') : 0;
		str[0] == '-' ? ft_putchar('-') : 0;
		sign && str[0] != '-' ? ft_putchar('+') : 0;
		z->zero_flag ? print_width(z->width, '0') : 0;
		print_width(z->precision, z->precision_flag ? '0' : ' ');
		flag ? ft_putstr("") : ft_putstr_index(str, index);
	}
}

void			di_pr(t_cp *z, va_list ap)
{
	char	*s;
	int		sign;
	int		len;
	int		spec_flag;

	s = ft_lltoa(cast_di(z, ap));
	sign = s[0] == '-' ? 1 : 0;
	spec_flag = (ft_strcmp(s, "0") == 0 && z->precision == 0) ? 1 : 0;
	len = (ft_strcmp(s, "0") == 0 && z->precision == 0) ? 0
			: (int)ft_strlen(s);
	z->precision = z->precision > len - sign ? z->precision - len + sign : 0;
	sign = z->pf == 1 && s[0] != '-' ? 1 : 0;
	len += sign;
	len += z->precision;
	sign = (z->pf == 1 || s[0] == '-') ? 1 : 0;
	len += (sign == 0 || len == 0) && z->sf ? 1 : 0;
	z->width = z->width > len ? z->width - len : 0;
	len += z->width;
	print_str(z, s, sign, spec_flag);
	z->n_chars += len;
	free(s);
}
