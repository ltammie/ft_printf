#include "../includes/ft_printf.h"

int		parse_flags(const char *str, int index, t_cp *z)
{
	while (is_flag(str[index]) == 1)
	{
		if (str[index] == '0')
			z->zero_flag = 1;
		if (str[index] == '-')
			z->minus_flag = 1;
		if (str[index] == '+')
			z->pf = 1;
		if (str[index] == ' ')
			z->sf = 1;
		if (str[index] == '#')
			z->hash_flag = 1;
		index++;
		z->length++;
	}
	return (index);
}
