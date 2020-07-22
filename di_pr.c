//#include "includes/ft_printf.h"
//
//static void print_arg(t_cp *z, char *s, int len)
//{
//	if (s[0] == '-')
//	{
//		s = ft_strsub(s, 1, len - 1);
//		len = (int)ft_strlen(s);
//		ft_putchar('-');
//		if (z->precision >= 0)
//			print_width(z->precision - len, '0');
//		ft_putstr(s);
//	}
//	else if (z->plus_flag == 1)
//	{
//		ft_putchar('+');
//		len--;
//		if (z->precision >= 0)
//			print_width(z->precision - len, '0');
//		ft_putstr(s);
//	}
//	else
//	{
//		if (z->precision >= 0)
//			print_width(z->precision - len, '0');
//		ft_putstr(s);
//	}
//}
//
//static void print_min_flag(t_cp *z, char *s, int len)
//{
//	if (z->minus_flag == 1)
//	{
//		print_arg(z, s, len);
//		print_width(z->precision > len ?  z->width - z->precision : z->width - len, ' ');
//	}
//	else
//	{
//		print_width(z->precision > len ?  z->width - z->precision : z->width - len, z->zero_flag ? '0' : ' ');
//		print_arg(z, s, len);
//	}
//}
//
//int			di_pr(t_cp *z, va_list ap)
//{
//	char			*s;
//	int				len;
//	s = ft_itoa(va_arg(ap, int));
//	if (ft_strcmp(s, "0") == 0 && z->precision == 0)
//	{
//		z->width > 0 ? print_width(z->width, ' ') : ft_putstr("");
//		return (0);
//	}
//	len = (int)ft_strlen(s);
//	if (z->plus_flag == 1 && s[0] != '-')
//		z->width--;
//	if (s[0] == '-')
//		z->plus_flag = 0;
//	print_min_flag(z, s, len);
//	return (0);
//}

#include "includes/ft_printf.h"

static void print_min_flag(t_cp *z, char *s, int len)
{
	len = ft_strlen(s);
	if (z->minus_flag == 1)
	{
		ft_putstr(s);
		print_width(z->width - len, ' ');
	}
	else
	{
		print_width(z->width - len, z->zero_flag ? '0' : ' ');
		ft_putstr(s);
	}
}

static void print_0p_0v(char *s, t_cp *z, int len)
{
	s = ft_strdup("");
	len = (int)ft_strlen(s);
	if (z->minus_flag == 1)
	{
		ft_putstr(s);
		print_width(z->width - len, ' ');
	}
	else
	{
		print_width(z->width - len, z->zero_flag ? '0' : ' ');
		ft_putstr(s);
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
	len = (int)ft_strlen(s) - (int)ft_strlen(sign);
	if (ft_strcmp(s, "0") == 0 && z->precision == 0)
	{
		print_0p_0v(s, z, len);
		return (0);
	}
	if (len < z->precision)
	{
		tmp = (char *)malloc(sizeof(char) * (z->precision - len));
		s = ft_strjoin(ft_memset(tmp, '0', z->precision - len), s);
		free(tmp);
	}
	print_min_flag(z, s, len);
	return (0);
}

