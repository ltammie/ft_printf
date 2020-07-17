#include "includes/ft_printf.h"

//what if there is 0 width provided?

int 	parse_width(const char *str, int index, t_cp *z)
{
	z->width = ft_atoi(&str[index]);
	z->length += get_nbr_length(z->width);
	index += get_nbr_length(z->width);
	return (index);
}
