#include "../includes/ft_printf.h"

void		parse_type(const char *str, int index, t_cp *z)
{
	if (ft_char_int_str("cspdiouxXf%\0", str[index]))
		z->arg_type = str[index];
	else
		z->no_spec = 1;
	z->length++;
}
