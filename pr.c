#include "includes/ft_printf.h"

int 	pr(t_cp parsed_str, va_list ap)
{

	if (parsed_str.arg_type == 'c')
		c_pr(parsed_str, ap);
	if (parsed_str.arg_type == 's')
		s_pr(parsed_str, ap);
	return (0);
}
