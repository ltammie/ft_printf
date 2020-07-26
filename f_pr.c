#include "includes/ft_printf.h"

void			f_pr(t_cp *z, va_list ap)
{
	char		*str;
	char		*mantissa;
	int 		e;
	int 		i;
	t_d			d;
	t_lf		*number;

	d.d = (double)cast_f(z, ap);
	mantissa = ft_ulltoa_base(d.t_ds.m, 2);
	if (ft_strlen(mantissa) < 52)
		mantissa = ft_strjoin(ft_fill_str('0', 52 - (int)ft_strlen(mantissa)), mantissa);
	str = ft_strjoin("1", mantissa);
	printf("mantissa = %s\n", str);

	//long arithmentics
	i = 0;
	e = (int)d.t_ds.e - 1023;
	number = new_long_number();
	while (e >= 0)
	{
		if (str[i] == '1')
			long_sum_long(number, pow2(e));
		e--;
		i++;
	}
	print_number(number);
}
