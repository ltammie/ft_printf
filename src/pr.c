#include "../includes/ft_printf.h"

static	void	check_asterisk(t_cp *parsed_str, va_list ap)
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
		parsed_str->precision = parsed_str->precision < 0 ?
				-1 : parsed_str->precision;
	}
}

static	void	check_flags(t_cp *parsed_str)
{
	if (parsed_str->pf == 1 && parsed_str->sf == 1)
		parsed_str->sf = 0;
	if (parsed_str->precision >= 0 && ft_char_int_str("diouxXp\0",
			parsed_str->arg_type))
		parsed_str->zero_flag = 0;
	if (parsed_str->minus_flag == 1 && parsed_str->zero_flag == 1)
		parsed_str->zero_flag = 0;
}

int				pr(t_cp *format, va_list ap)
{
	check_asterisk(format, ap);
	check_flags(format);
	if (format->no_spec)
		return (format->length + 1);
	if (format->arg_type == 'c')
		c_pr(format, ap);
	if (format->arg_type == 's')
		s_pr(format, ap);
	if (format->arg_type == 'p')
		pointer_pr(format, ap);
	if (format->arg_type == '%')
		percent_pr(format);
	if (ft_char_int_str("ouxX\0", format->arg_type))
		uox_pr(format, ap);
	if (format->arg_type == 'd' || format->arg_type == 'i')
		di_pr(format, ap);
	if (format->arg_type == 'f')
	{
		format->precision = format->precision == -1 ? 6 : format->precision;
		f_pr(format, ap);
	}
	return (format->n_chars);
}
