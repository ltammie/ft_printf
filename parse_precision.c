#include "includes/ft_printf.h"

//what if there is 0 precision provided?

int 	parse_precision(const char *str, int index, t_cp *z)
{
	if (str[index] == '.')
	{
		index++;
		z->length++;
		if (str[index] == '*')
		{
			z->ast_p = 1;
			z->length++;
			return (index + 1);
		}
		z->precision = ft_atoi(&str[index]);
		z->length += get_nbr_length(z->precision);
		index += get_nbr_length(z->precision);
		if (z->precision < 0)
		{
			z->length++;
			index++;
			z->precision = -1;
		}
	}
	return (index);
}
