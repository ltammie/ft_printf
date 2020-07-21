#include "includes/ft_printf.h"

int 	parse_width(const char *str, int index, t_cp *z)
{
	if (str[index] == '*')
	{
		z->ast_w = 1;
		z->length++;
		return (index + 1);
	}
	z->width = ft_atoi(&str[index]);
	z->length += get_nbr_length(z->width);
	index += get_nbr_length(z->width);
	return (index);
}
