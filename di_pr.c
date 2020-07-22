#include "includes/ft_printf.h"

static void print_arg(t_cp *z, char *s, int len)
{
	if (s[0] == '-')
	{
		s = ft_strsub(s, 1, len - 1);
		ft_putchar('-');
	}
	if (z->plus_flag == 1)
		ft_putchar('+');
	if (z->precision >= 0)
		print_width(z->precision - len, '0');
	ft_putstr(s);
}

static void print_min_flag(t_cp *z, char *s, int len)
{
	if (z->minus_flag == 1)
	{
		print_arg(z, s, len);
		print_width(z->precision > len ?  z->width - z->precision : z->width - len, ' ');
	}
	else
	{
		print_width(z->precision > len ?  z->width - z->precision : z->width - len, z->zero_flag ? '0' : ' ');
		print_arg(z, s, len);
	}
}

int			di_pr(t_cp *z, va_list ap)
{
	char			*s;
	int				len;

	s = ft_itoa(va_arg(ap, int));
	if (ft_strcmp(s, "0") == 0 && z->precision == 0)
	{
		z->width > 0 ? print_width(z->width, ' ') : ft_putstr("");
		return (0);
	}
	len = (int)ft_strlen(s);
	if (z->plus_flag == 1 && s[0] != '-')
		z->width--;
	if (s[0] == '-')
		z->plus_flag = 0;
	print_min_flag(z, s, len);
	return (0);
}
