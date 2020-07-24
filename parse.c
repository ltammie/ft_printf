#include "includes/ft_printf.h"

static t_cp *ft_new_t_cp(void)
{
	t_cp *new_t_cp;

	new_t_cp = (t_cp*)malloc(sizeof(t_cp)); //add malloc error
	new_t_cp->hash_flag = 0;
	new_t_cp->zero_flag = 0;
	new_t_cp->minus_flag = 0;
	new_t_cp->plus_flag = 0;
	new_t_cp->space_flag = 0;
	new_t_cp->width = 0;
	new_t_cp->precision = -1;
	new_t_cp->precision_flag = 0;
	new_t_cp->arg_type = 'z';
	new_t_cp->length = 0;
	new_t_cp->ast_w = 0;
	new_t_cp->ast_p = 0;
	new_t_cp->h_flag = 0;
	new_t_cp->hh_flag = 0;
	new_t_cp->l_flag = 0;
	new_t_cp->ll_flag = 0;
	new_t_cp->n_chars = 0;
	return (new_t_cp);
}

t_cp	*ft_parse(const char *str, int index)
{
	t_cp *res;

	res = ft_new_t_cp();

//	printf("index before parsing = %d\n", index);

	index = parse_flags(str, index, res);
//	printf("index after flags = %d\n", index);

	index = parse_width(str, index, res);
//	printf("index after width = %d\n", index);

	index = parse_precision(str, index, res);
//	printf("index after precision = %d\n", index);

	index = parse_length(str, index, res);
//	printf("index after length = %d\n", index);

	parse_type(str, index, res);
//	print_struct(res);

	return (res);
}

