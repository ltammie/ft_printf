#include "includes/ft_printf.h"

#include <stdlib.h>

void		print_struct(t_cp *res)
{
	printf("\nhash_flag = %d\n",res->hash_flag);
	printf("zero_flag = %d\n", res->zero_flag);
  	printf("minus_flag = %d\n", res->minus_flag);
  	printf("plus_flag = %d\n", res->plus_flag);
  	printf("space_flag = %d\n", res->space_flag);
	printf("width = %d\n", res->width);
	printf("precision = %d\n", res->precision);
  	printf("arg_type = %c\n", res->arg_type);
	printf("length = %d\n", res->length);
	printf("ast_w = %d\n", res->ast_w);
	printf("ast_p = %d\n", res->ast_p);
	printf("h_flag = %d\n", res->h_flag);
	printf("hh_flag = %d\n", res->hh_flag);
	printf("l_flag = %d\n", res->l_flag);
	printf("ll_flag = %d\n", res->ll_flag);
}

int		ft_printf(const char *format, ...)
{
	int 	n_chars;
	int 	i;
	t_cp	*res;
	va_list ap;

	n_chars = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			res = ft_parse(format, ++i);
			pr(res, ap);
			i += res->length;
			free(res);
		}
		else
		{
			ft_putchar(format[i]);
			i++;
		}
	}
	va_end(ap);
	return (n_chars);
}
