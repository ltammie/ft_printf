#include "includes/ft_printf.h"

#include <stdlib.h>

void		print_struct(t_cp res)
{
	printf("\nhashtag_flag = %d\n",res.hashtag_flag);
	printf("zero_flag = %d\n", res.zero_flag);
  	printf("minus_flag = %d\n", res.minus_flag);
  	printf("plus_flag = %d\n", res.plus_flag);
  	printf("space_flag = %d\n", res.space_flag);
	printf("width = %zu\n", res.width);
	printf("precision = %zu\n", res.precision);
  	printf("arg_type = %c\n", res.arg_type);
  	printf("length = %zu\n", res.length);
}

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
			print_struct(res);
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
