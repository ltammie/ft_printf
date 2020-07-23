#include "includes/ft_printf.h"

static void print_min_flag(t_cp *z, char *s, int len)
{
	len = (int)ft_strlen(s);
	if (z->minus_flag == 1)
	{
		ft_putstr(s);
		print_width(z->width - len, ' ');
	}
	else
	{
		print_width(z->width - len, z->zero_flag ? '0' : ' ');
		ft_putstr(s);
	}
}

static char *add_prefix(t_cp *z, char *str, int flag)
{
	if (z->hash_flag == 1 && z->arg_type == 'o')
		if (str[0] != '0')
			str = ft_strjoin("0", str);
	if (z->hash_flag == 1 && z->arg_type == 'x' && flag ==  0)
		str = ft_strjoin("0x", str);
	if (z->hash_flag == 1 && z->arg_type == 'X' && flag == 0)
		str = ft_strjoin("0X", str);
	return (str);
}

static void print_0p_0v(char *s, t_cp *z, int len, int flag)
{
	s = ft_strdup("");
	s = add_prefix(z, s, flag);
	len = (int)ft_strlen(s);
	if (z->minus_flag == 1)
	{
		ft_putstr(s);
		print_width(z->width - len, ' ');
	}
	else
	{
		print_width(z->width - len, z->zero_flag ? '0' : ' ');
		ft_putstr(s);
	}
}

static void print_0p_0f(char *s, t_cp *z, int len, int flag)
{
	char	*tmp;
	int 	fix_len;

	fix_len = 0;
	if (z->hash_flag == 1)
	{
		fix_len = z->arg_type == 'o'? 1 : 0;
		fix_len = ft_char_int_str("xX\0", z->arg_type) == 1 ? 2 : fix_len;
	}
	if (z->width > (len + fix_len))
	{
		tmp = (char *)malloc(sizeof(char) * (z->width - len - fix_len));
		s = ft_strjoin(ft_memset(tmp, '0', (size_t)(z->width - len - fix_len)), s);
		free(tmp);
	}
	s = add_prefix(z, s, flag);
	ft_putstr(s);
}

int			u_pr(t_cp *z, va_list ap)
{
	char			*s;
	char 			*tmp;
	int				len;
	int 			zero_value_flag;

	s = ft_ulltoa_base(u_cast(z, ap), get_base(z->arg_type));
	if (z->arg_type == 'x')
		s = ft_str_to_lower(s);
	len = (int)ft_strlen(s);
	zero_value_flag = ft_strcmp(s, "0") == 0 ? 1 : 0;
	if (ft_strcmp(s, "0") == 0 && z->precision == 0)
	{
		print_0p_0v(s, z, len, zero_value_flag);
		return (0);
	}
	if (len < z->precision)
	{
		tmp = (char *)malloc(sizeof(char) * (z->precision - len));
		s = ft_strjoin(ft_memset(tmp, '0', z->precision - len), s);
		free(tmp);
	}
	if (z->precision == -1 && z->zero_flag == 1)
	{
		print_0p_0f(s, z, len, zero_value_flag);
		return (0);
	}
	s = add_prefix(z, s, zero_value_flag);
	print_min_flag(z, s, len);
	return (0);
}
