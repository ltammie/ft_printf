#include "../includes/ft_printf.h"

static	t_cp	*ft_new_t_cp(void)
{
	t_cp *new_t_cp;

	if (!(new_t_cp = (t_cp*)malloc(sizeof(t_cp))))
		exit(-1);
	new_t_cp->hash_flag = 0;
	new_t_cp->zero_flag = 0;
	new_t_cp->minus_flag = 0;
	new_t_cp->pf = 0;
	new_t_cp->sf = 0;
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
	new_t_cp->lf = 0;
	new_t_cp->n_chars = 0;
	new_t_cp->no_spec = 0;
	new_t_cp->percent_index = 0;
	return (new_t_cp);
}

t_cp			*ft_parse(const char *str, int index)
{
	t_cp *res;

	res = ft_new_t_cp();
	res->percent_index = index - 1;
	index = parse_flags(str, index, res);
	index = parse_width(str, index, res);
	index = parse_precision(str, index, res);
	index = parse_length(str, index, res);
	parse_type(str, index, res);
	return (res);
}
