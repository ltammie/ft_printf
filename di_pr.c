#include "includes/ft_printf.h"

static void print_min_flag(t_cp *z, char *s, char *sign)
{

	if (z->minus_flag == 1)
	{
		s = ft_strjoin(sign, s);
		ft_putstr(s);
		print_width(z->width - ft_strlen(s), ' ');
	}
	else
	{
		if (z->precision == -1 && z->zero_flag == 1)
		{
			ft_putstr(sign);
			print_width(z->width - ft_strlen(s) - ft_strlen(sign), '0');
			ft_putstr(s);
		}
		else
		{
			s = ft_strjoin(sign, s);
			print_width(z->width - ft_strlen(s), z->zero_flag ? '0' : ' ');
			ft_putstr(s);
		}
	}
}

int			di_pr(t_cp *z, va_list ap)
{
	char			*s;
	char 			*tmp;
	char 			*sign;
	int				len;

	s = ft_itoa(va_arg(ap, int));
	sign = ft_strdup("");
	if (z->plus_flag == 1)
		sign = ft_strdup("+");
	if (s[0] == '-')
	{
		sign = ft_strdup("-");
		s = ft_strsub(s, 1, (int)ft_strlen(s) - 1);
	}
	if (ft_strcmp(s, "0") == 0 && z->precision == 0)
		s = ft_strdup("");
	len = (int)ft_strlen(s);
	if (z->precision > len)
	{
		tmp = (char *)malloc(sizeof(char) * (z->precision - len));
		s = ft_strjoin(ft_memset(tmp, '0', z->precision - len), s);
		free(tmp);
	}
	print_min_flag(z, s, sign);
	return (0);
}

