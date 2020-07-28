#include "libft.h"
#include <stdio.h>

static double		ft_ftoa_adder(int precision)
{
	double	adder;

	adder = 0.05;
	while (precision-- > 1)
		adder /= 10;
	return (adder);
}

char				*ft_ftoa(double n, int precision)
{
	long long	int_part;
	double		fraction;
	char		*number[2];
	int			i;
	int 		first_digit;

	i = 0;
	int_part = (long long)n;
	fraction = (double)(n - int_part) * (n < 0 ? -1 : 1);
	first_digit = (int)(fraction * 10) % 10;
	if (first_digit >= 5)
		if (int_part % 2 != 0)
			int_part++;
	number[0] = ft_lltoa(int_part);
	if (precision > 0)
	{
		number[1] = ft_strnew(i);
		fraction += ft_ftoa_adder(precision);
		while (i < precision)
		{
			fraction *= 10;
			number[1][i++] = ((unsigned long long)fraction % 10) + '0';
		}
		number[0] = ft_strjoin(ft_strjoin(number[0], "."), number[1]);
	}
	return (number[0]);
}
