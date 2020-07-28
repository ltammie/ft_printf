#include "includes/ft_printf.h"

int 	parse_length(const char *str, int index, t_cp *z)
{
	while (ft_char_int_str("%cspuoxXdif\0" , str[index]) != 1)
	{
		if (str[index] == 'h')
		{
			if (z->h_flag == 1)
				z->hh_flag = 1;
			z->h_flag = 1;
		}
		if (str[index] == 'l')
		{
			if (z->l_flag == 1)
				z->ll_flag = 1;
			z->l_flag = 1;
		}
		if (str[index] == 'L')
			z->L_flag = 1;
		index++;
		z->length++;
	}
	return (index);
}
