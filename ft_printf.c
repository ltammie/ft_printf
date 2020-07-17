#include "includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		ft_printf(const char *format, ...)
{
	int 	n_chars;
	int 	i;
	t_cp	res;
	va_list pr;

	n_chars = 0;
	i = 0;
	va_start(pr, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			res = ft_parse(format, ++i);
			printf("hashtag_flag = %d\nzero_flag = %d\nminus_flag = %d\nplus_flag = %d\nspace_flag = %d\n"
		  "width = %zu\nprecision = %zu\narg_type = %c\nlength = %zu\n", res.hashtag_flag, res.zero_flag, res.minus_flag,
		  res.plus_flag, res.space_flag, res.width, res.precision, res.arg_type, res.length);
			if (res.arg_type == 'd')
				ft_putnbr(va_arg(pr, int));
			i += res.length;
		}
		ft_putchar(format[i]);
		i++;
	}
	va_end(pr);
	return (n_chars);
}
