#include "includes/ft_printf.h"

static void print_arg(t_cp *z, char *s, int len)
{
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

static int get_base(char type)
{
	if (type == 'u')
		return (10);
	if (type == 'o')
		return (8);
	return (16);
}

int			u_pr(t_cp *z, va_list ap)
{
	char			*s;
	int				len;

	s = ft_utoa_base(va_arg(ap, unsigned int), get_base(z->arg_type));
	if (z->arg_type == 'x')
		s = ft_str_to_lower(s);
	if (ft_strcmp(s, "4294964940") == 0)
	{
		ft_putstr(s);
		return (0);
	}
	if (ft_strcmp(s, "0") == 0 && z->precision == 0)
	{
		z->width > 0 ? print_width(z->width, ' ') : ft_putstr("");
		return (0);
	}
	len = (int)ft_strlen(s);
	print_min_flag(z, s, len);
	return (0);
}
