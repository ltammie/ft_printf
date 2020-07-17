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
			res = parse(format, ++i);
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
