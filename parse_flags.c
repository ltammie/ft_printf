#include "includes/ft_printf.h"



int 	parse_flags(const char *str, int index, t_cp *z)
{
	while (is_nonzero_digit(str[index]) != 1)
	{
		printf("index in flag parsing = %d\n", index);
		if (str[index] == '0')
			z->zero_flag = 1;
		if (str[index] == '-')
			z->minus_flag = 1;
		if (str[index] == '+')
			z->plus_flag = 1;
		if (str[index] == ' ')
			z->space_flag = 1;
		if (str[index] == '#')
			z->hashtag_flag = 1;
		index++;
		z->length++;
	}
	return (index);
}
