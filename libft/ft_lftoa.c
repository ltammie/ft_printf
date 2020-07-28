#include "libft.h"
#include <stdio.h>

static double		ft_round(int precision)
{
	long double	adder;

	adder = 0.05;
	while (precision > 1)
	{
		adder /= 10;
		precision--;
	}
	return (adder);
}

char				*ft_lftoa(long double n, int precision)
{
	long long	int_part;
	long double	fraction;
	char		*number[2];
	int			i;

	i = 0;
	int_part = (long long)n;
	fraction = (long double)(n - int_part) * (n < 0 ? -1 : 1);
	if ((int)(fraction * 10) % 10 >= 5 && precision <= 0)
		if (int_part % 2 != 0)
			int_part += int_part > 0 ? 1 : -1;
	number[0] = ft_lltoa(int_part);
	if (precision > 0)
	{
		number[1] = ft_strnew(i);
		fraction += ft_round(precision);
		while (i < precision)
		{
			fraction *= 10;
			number[1][i++] = ((unsigned long long)fraction % 10) + '0';
			fraction -= (unsigned long long)fraction;
		}
		number[0] = ft_strjoin(ft_strjoin(number[0], "."), number[1]);
	}
	return (number[0]);
}
