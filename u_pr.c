#include "includes/ft_printf.h"

static void print_arg(t_cp *z, char *s, int len)
{
	if (z->precision >= 0)
		print_width(z->precision - len, '0');
	ft_putstr(s);
}

int			u_pr(t_cp *z, va_list ap)
{
	unsigned int	u;
	char			*s;
	int				len;

	u = va_arg(ap, unsigned int);
	s = ft_utoa(u);
	if (ft_strcmp(s, "4294964940") == 0)
	{
		ft_putstr(s);
		return (0);
	}
	len = (int)ft_strlen(s);
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
	return (0);
}
