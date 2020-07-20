#include "includes/ft_printf.h"

//what if there is 0 precision provided?

int 	parse_precision(const char *str, int index, t_cp *z)
{
	if (str[index] == '.')
	{
		index++;
		z->length++;
		z->precision = ft_atoi(&str[index]);
		z->length += get_nbr_length(z->precision);
		index += get_nbr_length(z->precision);
	}
	return (index);
}
