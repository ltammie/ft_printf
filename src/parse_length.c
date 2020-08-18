#include "../includes/ft_printf.h"

int		parse_length(const char *str, int index, t_cp *z)
{
	if (str[index] == 'h')
		z->h_flag = 1;
	if (str[index] == 'l')
		z->l_flag = 1;
	if (str[index] == 'L')
		z->lf = 1;
	if ((z->h_flag || z->l_flag) && !z->lf)
	{
		if (str[index + 1] == 'h' && z->h_flag)
			z->hh_flag = 1;
		if (str[index + 1] == 'l' && z->l_flag)
			z->ll_flag = 1;
	}
	index += z->h_flag + z->hh_flag + z->l_flag + z->ll_flag + z->lf;
	z->length += z->h_flag + z->hh_flag + z->l_flag + z->ll_flag + z->lf;
	return (index);
}
