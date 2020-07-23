#include "includes/ft_printf.h"

static void print_mf(t_cp *z, char *s, char *sign)
{
	s = ft_strjoin(sign, s);
	if (((s[0] != '-' && s[0] != '+') || ft_strlen(s) == 0) && z->space_flag == 1)
		s = ft_strjoin(" ", s);
	ft_putstr(s);
	print_width((int)(z->width - ft_strlen(s)), ' ');
}

static void	print_0p_0f_sp(t_cp *z, char *s, char *sign)
{
	int sp_flag;

	sp_flag = 0;
	if (((sign[0] != '-' && sign[0] != '+') || ft_strlen(s) == 0) && z->space_flag == 1)
	{
		ft_putchar(' ');
		sp_flag = 1;
	}
	ft_putstr(sign);
	print_width((int)(z->width - ft_strlen(s) - ft_strlen(sign) - sp_flag), '0');
	ft_putstr(s);
}

static void print_0p_sf(t_cp *z, char *s, char *sign)
{
	int sp_flag;

	sp_flag = 0;
	s = ft_strjoin(sign, s);
	if (((s[0] != '-' && s[0] != '+') || ft_strlen(s) == 0) && z->space_flag == 1)
	{
		ft_putchar(' ');
		sp_flag = 1;
	}
	print_width((int)(z->width - ft_strlen(s) - sp_flag), z->zero_flag ? '0' : ' ');
	ft_putstr(s);
}

static void print_min_flag(t_cp *z, char *s, char *sign)
{
	if (z->minus_flag == 1)
		print_mf(z, s, sign);
	else
	{
		if (z->precision == -1 && z->zero_flag == 1)
			print_0p_0f_sp(z, s, sign);
		else
			print_0p_sf(z, s, sign);
	}
}

int			di_pr(t_cp *z, va_list ap)
{
	char			*s;
	char 			*tmp;
	char 			*sign;
	int				len;

	s = ft_lltoa(cast_di(z, ap));
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
		tmp = ft_fill_str('0', z->precision - len);
		s = ft_strjoin(tmp, s);
		free(tmp);
	}
	print_min_flag(z, s, sign);
	return (0);
}

