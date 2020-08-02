#include "includes/ft_printf.h"

static char 	*float_to_str(t_d d, const char *str)
{
	int 		e;
	int 		i;
	int 		len;
	t_lf		*number;
	t_lf		*fraction;
	t_lf		*tmp;
	char 		*res;
	char		*fr_str;

	i = 0;
	e = (int)d.t_ds.e - 16383;
	number = new_long_number(0);
	fraction = new_long_number(0);
	len = (int)ft_strlen(str);
	if (e > 0)
	{
		tmp = pow_long(e, 2);
		while (e >= 0)
		{
			if (str[i] == '1')
				long_sum_long(number, tmp);
			long_div_two(tmp);
			e--;
			i++;
		}
	}
	e *= -1;
	tmp = pow_fraction(e, 5000);
	print_fraction(pow_fraction(20, 5000));
	while (i < len)
	{
		if (str[i] == '1')
			fraction_sum_fraction(fraction, tmp);
		fraction_mul_short(5000, tmp);
		tmp->exp++;
		e++;
		i++;
	}
	fr_str = lfraction_to_str(fraction);
	res = ft_strjoin(ft_strjoin(long_to_str(number), "."), fr_str);
	return (res);
}

void			f_pr(t_cp *z, va_list ap)
{
	char 		*str;
	char		*mantissa;
	t_d			d;

	d.d = (long double)cast_f(z, ap);
	mantissa = ft_ulltoa_base(d.t_ds.m, 2);
	if (ft_strlen(mantissa) < 64)
		mantissa = ft_strjoin(ft_fill_str('0', 64 - (int)ft_strlen(mantissa)), mantissa);
	str = float_to_str(d, mantissa);
	ft_putstr(str);

//	sign = ft_strdup("");
//	if (z->plus_flag == 1)
//		sign = ft_strdup("+");
//	if (d.t_ds.s == 1)
//		sign = ft_strdup("-");
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
}
