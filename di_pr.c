#include "includes/ft_printf.h"
//
//static void print_mf(t_cp *z, char *s, char *sign)
//{
//	s = ft_strjoin(sign, s);
//	if (((s[0] != '-' && s[0] != '+') || ft_strlen(s) == 0) && z->space_flag == 1)
//		s = ft_strjoin(" ", s);
//	ft_putstr(s);
//	z->n_chars += (int)ft_strlen(s);
//	z->n_chars += print_width((int)(z->width - ft_strlen(s)), ' ');
//}
//
//static void	print_0p_0f_sp(t_cp *z, char *s, char *sign)
//{
//	int sp_flag;
//
//	sp_flag = 0;
//	if (((sign[0] != '-' && sign[0] != '+') || ft_strlen(s) == 0) && z->space_flag == 1)
//	{
//		ft_putchar(' ');
//		z->n_chars++;
//		sp_flag = 1;
//	}
//	ft_putstr(sign);
//	z->n_chars += (int)ft_strlen(sign);
//	z->n_chars += print_width((int)(z->width - ft_strlen(s) - ft_strlen(sign) - sp_flag), '0');
//	ft_putstr(s);
//	z->n_chars += (int)ft_strlen(s);
//}
//
//static void print_0p_sf(t_cp *z, char *s, char *sign)
//{
//	int sp_flag;
//
//	sp_flag = 0;
//	s = ft_strjoin(sign, s);
//	if (((s[0] != '-' && s[0] != '+') || ft_strlen(s) == 0) && z->space_flag == 1)
//	{
//		ft_putchar(' ');
//		z->n_chars++;
//		sp_flag = 1;
//	}
//	z->n_chars += print_width((int)(z->width - ft_strlen(s) - sp_flag), z->zero_flag ? '0' : ' ');
//	ft_putstr(s);
//	z->n_chars += (int)ft_strlen(s);
//}
//
//static void print_min_flag(t_cp *z, char *s, char *sign)
//{
//	if (z->minus_flag == 1)
//		print_mf(z, s, sign);
//	else
//	{
//		if (z->precision == -1 && z->zero_flag == 1)
//			print_0p_0f_sp(z, s, sign);
//		else
//			print_0p_sf(z, s, sign);
//	}
//}

//void		di_pr(t_cp *z, va_list ap)
//{
//	char			*s;
//	char 			*tmp;
//	char 			*sign;
//	int				len;
//
//	s = ft_lltoa(cast_di(z, ap));
//	sign = ft_strdup("");
//	if (z->plus_flag == 1)
//		sign = ft_strdup("+");
//	if (s[0] == '-')
//	{
//		sign = ft_strdup("-");
//		s = ft_strsub(s, 1, (int)ft_strlen(s) - 1);
//	}
//	if (ft_strcmp(s, "0") == 0 && z->precision == 0)
//		s = ft_strdup("");
//	len = (int)ft_strlen(s);
//	if (z->precision > len)
//	{
//		tmp = ft_fill_str('0', z->precision - len);
//		s = ft_strjoin(tmp, s);
//		free(tmp);
//	}
//	print_min_flag(z, s, sign);
//}
//
static	void	print_str(t_cp *z, int len, char *str, int sign)
{
//	char	*res;
//
//	res = (char *)malloc(sizeof(char) * (len + 1));
	if (z->minus_flag)
	{
		!sign && z->space_flag ? ft_putchar(' ') : 0;
		str[0] == '-' ? ft_putchar('-') : 0;
		sign && str[0] != '-' ? ft_putchar('+') : 0;
		print_width(z->width, z->zero_flag || z->precision ? '0' : ' ');

	}

}

void		di_pr(t_cp *z, va_list ap)
{
	char *s;
	int sign;
	int len;

	s = ft_lltoa(cast_di(z, ap));
	sign = (z->plus_flag == 1 || s[0] == '-') ? 1 : 0;
	len = (ft_strcmp(s, "0") == 0 && z->precision == 0) ? 0 : (int) ft_strlen(s);
	len += sign;
	z->precision = z->precision > len ? z->precision - len : 0;
	len += z->precision;
	len += (sign == 0 || len == 0) && z->space_flag ? 1 : 0;
	z->width = z->width > len ? z->width - len : len;
	len += z->width;
	print_str(z, len, s, sign);
}
