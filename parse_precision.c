#include "includes/ft_printf.h"

int 	parse_precision(const char *str, int index, t_cp *z)
{
	if (str[index] == '.')
	{
		index++;
		z->length++;
		z->precision_flag = 1;
		if (str[index] == '*')
		{
			z->ast_p = 1;
			z->length++;
			return (index + 1);
		}
		z->precision = ft_atoi(&str[index]);
		if (z->precision < 0)
		{
			z->length++;
			index++;
			z->precision = -1;
		}
		while (ft_isdigit(str[index]))
		{
			z->length++;
			index++;
		}
	}
	return (index);
}
