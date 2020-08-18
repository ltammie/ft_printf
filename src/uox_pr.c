#include "../includes/ft_printf.h"

static	char	*add_prefix(t_cp *z, char *str, int flag)
{
	char *res;

	if (z->hash_flag == 1 && z->arg_type == 'o' && str[0] != '0')
	{
		res = ft_strjoin("0", str);
		free(str);
		str = res;
	}
	if (z->hash_flag == 1 && z->arg_type == 'x' && flag == 0)
	{
		res = ft_strjoin("0x", str);
		free(str);
		str = res;
	}
	if (z->hash_flag == 1 && z->arg_type == 'X' && flag == 0)
	{
		res = ft_strjoin("0X", str);
		free(str);
		str = res;
	}
	return (str);
}

static	void	print_min_flag(t_cp *z, char *s, int len, int flag)
{
	s = add_prefix(z, s, flag);
	len = (int)ft_strlen(s);
	z->n_chars += len;
	if (z->minus_flag == 1)
	{
		ft_putstr(s);
		z->n_chars += print_width(z->width - len, ' ');
	}
	else
	{
		z->n_chars += print_width(z->width - len, z->zero_flag ? '0' : ' ');
		ft_putstr(s);
	}
	free(s);
}

static	void	print_0p_0v(char *s, t_cp *z, int len, int flag)
{
	free(s);
	s = ft_strdup("");
	s = add_prefix(z, s, flag);
	len = (int)ft_strlen(s);
	z->n_chars += len;
	if (z->minus_flag == 1)
	{
		ft_putstr(s);
		z->n_chars += print_width(z->width - len, ' ');
	}
	else
	{
		z->n_chars += print_width(z->width - len, z->zero_flag ? '0' : ' ');
		ft_putstr(s);
	}
	free(s);
}

static	void	print_0p_0f(char *s, t_cp *z, int len, int flag)
{
	char	*tmp;
	int		fix_len;

	fix_len = 0;
	if (z->hash_flag == 1 && flag == 0)
	{
		fix_len = ft_char_int_str("xX\0", z->arg_type) == 1 ? 2 : fix_len;
	}
	if (z->width > (len + fix_len))
	{
		tmp = ft_fill_str('0', z->width - len - fix_len);
		s = ft_strjoin_free(&tmp, &s);
	}
	s = add_prefix(z, s, flag);
	ft_putstr(s);
	z->n_chars += ft_strlen(s);
	free(s);
}

void			uox_pr(t_cp *z, va_list ap)
{
	char	*s;
	char	*tmp;
	int		len;
	int		zero_value_flag;

	s = ft_ulltoa_base(u_cast(z, ap), get_base(z->arg_type));
	z->arg_type == 'x' ? ft_str_to_lower(&s) : 0;
	len = (int)ft_strlen(s);
	zero_value_flag = ft_strcmp(s, "0") == 0 ? 1 : 0;
	if (ft_strcmp(s, "0") == 0 && z->precision == 0)
		print_0p_0v(s, z, len, zero_value_flag);
	else
	{
		if (len < z->precision)
		{
			tmp = ft_fill_str('0', z->precision - len);
			s = ft_strjoin_free(&tmp, &s);
		}
		if (z->precision == -1 && z->zero_flag == 1)
			print_0p_0f(s, z, len, zero_value_flag);
		else
			print_min_flag(z, s, len, zero_value_flag);
	}
}
