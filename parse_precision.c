#include "includes/ft_printf.h"

//what if there is 0 precision provided?

int 	parse_precision(const char *str, int index, t_cp *z)
{
	if (str[index] == '.')
	{
		index++;
		z->width = ft_atoi(&str[index]);
		z->length += get_nbr_length(z->width);
		index += get_nbr_length(z->width);
	}
	else
		index++;
	return (index);
}
