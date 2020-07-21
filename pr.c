#include "includes/ft_printf.h"

static void check_asterisk(t_cp *parsed_str, va_list ap)
{
	if (parsed_str->ast_w == 1)
	{
		parsed_str->width = va_arg(ap, int);
		if (parsed_str->width < 0)
		{
			parsed_str->width *= -1;
			parsed_str->minus_flag = 1;
		}
	}
	if (parsed_str->ast_p == 1)
	{
		parsed_str->precision = va_arg(ap, int);
		parsed_str->precision = parsed_str->precision < 0 ? -1 : parsed_str->precision;
	}
}

static void check_flags(t_cp *parsed_str)
{
	if (parsed_str->plus_flag == 1 && parsed_str->space_flag == 1)
		parsed_str->space_flag = 0;
	if (parsed_str->precision >= 0 && ft_char_int_str("diouxX\0", parsed_str->arg_type))
		parsed_str->zero_flag = 0;
	if (parsed_str->minus_flag == 1 && parsed_str->zero_flag == 1)
		parsed_str->zero_flag = 0;
}

int 	pr(t_cp *parsed_str, va_list ap)
{
	check_asterisk(parsed_str, ap);
	check_flags(parsed_str);
	if (parsed_str->arg_type == 'c')
		c_pr(parsed_str, ap);
	if (parsed_str->arg_type == 's')
		s_pr(parsed_str, ap);
	if (parsed_str->arg_type == '%')
		percent_pr(parsed_str);
	if (ft_char_int_str("ouxX\0", parsed_str->arg_type))
		u_pr(parsed_str, ap);
	if (parsed_str->arg_type == 'd' || parsed_str->arg_type == 'i')
		di_pr(parsed_str, ap);
	return (0);
}
