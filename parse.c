#include "includes/ft_printf.h"

static t_cp *ft_new_t_cp(void)
{
	t_cp *new_t_cp;

	new_t_cp = (t_cp*)malloc(sizeof(t_cp)); //add malloc error
	new_t_cp->hashtag_flag = 0;
	new_t_cp->zero_flag = 0;
	new_t_cp->minus_flag = 0;
	new_t_cp->plus_flag = 0;
	new_t_cp->space_flag = 0;
	new_t_cp->width = 0;
	new_t_cp->precision = 0;
	new_t_cp->arg_type = 0;
	new_t_cp->length = 0;
	return (new_t_cp);
}

t_cp	ft_parse(const char *str, int index)
{
	t_cp *res;

	res = ft_new_t_cp();

	index = parse_flags(str, index, res);
	index = parse_width(str, index, res);
	index = parse_precision(str, index, res);
	parse_type(str, index, res);
	return (*res);
}

