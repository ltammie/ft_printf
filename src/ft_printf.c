#include "../includes/ft_printf.h"

static	int		print_all(const char *format, va_list ap)
{
	int		i;
	int		n_chars;
	t_cp	*res;

	i = 0;
	n_chars = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			res = ft_parse(format, ++i);
			n_chars += res->no_spec ? 0 : pr(res, ap);
			i += res->no_spec ? 0 : res->length;
			free(res);
		}
		else
		{
			ft_putchar(format[i]);
			i++;
			n_chars++;
		}
	}
	return (n_chars);
}

int				ft_printf(const char *format, ...)
{
	int		n_chars;
	va_list	ap;

	va_start(ap, format);
	n_chars = print_all(format, ap);
	va_end(ap);
	return (n_chars);
}
