#include "includes/ft_printf.h"

static char 	*float_to_str(t_d d, const char *str)
{
	int 		e;
	int 		i;
	int 		len;
	t_lf		*number;
	t_lf		*fraction;
	char 		*res;

	i = 0;
	e = (int)d.t_ds.e - 1023;
	number = new_long_number(0);
	fraction = new_long_number(0);
	len = (int)ft_strlen(str);
	if (e > 0)
	{
		while (e >= 0)
		{
			if (str[i] == '1')
				long_sum_long(number, pow_long(e, 2));
			e--;
			i++;
		}
	}
	e *= -1;
	while (i < len)
	{
		if (str[i] == '1')
			long_sum_long(fraction, pow_long(e, 5));
		e++;
		i++;
	}
	res = ft_strjoin(ft_strjoin(long_to_str(number), "."), lfraction_to_str(fraction));
	return (res);
}

void			f_pr(t_cp *z, va_list ap)
{
	char		*str;
	char		*mantissa;

	t_d			d;


	d.d = (double)cast_f(z, ap);
	mantissa = ft_ulltoa_base(d.t_ds.m, 2);
	if (ft_strlen(mantissa) < 52)
		mantissa = ft_strjoin(ft_fill_str('0', 52 - (int)ft_strlen(mantissa)), mantissa);
	str = ft_strjoin("1", mantissa);
//	printf("exponent = %d\n", (int)d.t_ds.e - 1023);
//	printf("mantissa = %s\n", str);
	str = float_to_str(d, str);
	ft_putstr(str);

}
