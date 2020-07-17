#include "includes/ft_printf.h"

static t_cp new_t_cp(void)
{
	t_cp new_t_cp;

	new_t_cp.flag = 0;
	new_t_cp.width = 0;
	new_t_cp.precision = 0;
	new_t_cp.arg_type = 'z'; // change later
	new_t_cp.length = 0;
	return (new_t_cp);
}

t_cp	parse(const char *str, int index)
{
	t_cp res;

	res = new_t_cp();
	while (str[index] != '\0')
	{
		res.length++;
		if (str[index] == 'd')
		{
			res.arg_type = 'd';
			break;
		}
		index++;
	}
	return (res);
}
