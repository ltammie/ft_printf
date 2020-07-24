#include "includes/ft_printf.h"

static void print_min_flag(t_cp *z, char *s, int len)
{
	z->n_chars += len;
	if (z->minus_flag == 1)
	{
		ft_putstr(s);
		z->n_chars += print_width(z->width - len, ' ');
	}
	else
	{
		z->n_chars += print_width(z->width - len, ' ');
		ft_putstr(s);
	}
}

void		pointer_pr(t_cp *z, va_list ap)
{
	void	*p;
	char	*s;
	int 	len;

	p = (void*)va_arg(ap, void*);
	s = ft_ulltoa_base((unsigned long int)p, 16);
	s = ft_str_to_lower(s);
	if (p == NULL && z->precision_flag == 1 && z->precision >= 0)
		s = ft_strdup("");
	len = (int)ft_strlen(s);
	if (z->precision >= 0)
		s = ft_strjoin(ft_fill_str('0', z->precision - len), s);
	s = ft_strjoin("0x", s);
	len = (int)ft_strlen(s);
	print_min_flag(z, s, len);
}

