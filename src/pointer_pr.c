#include "../includes/ft_printf.h"

static	void	print_min_flag(t_cp *z, char *s, int flag)
{
	if (z->minus_flag == 1)
	{
		ft_putstr("0x");
		print_width(z->precision, '0');
		flag ? ft_putstr("") : ft_putstr(s);
		print_width(z->width, ' ');
	}
	else
	{
		print_width(z->width, ' ');
		ft_putstr("0x");
		print_width(z->precision, '0');
		flag ? ft_putstr("") : ft_putstr(s);
	}
}

void			pointer_pr(t_cp *z, va_list ap)
{
	void	*p;
	char	*s;
	int		len;
	int		spec_flag;

	p = (void*)va_arg(ap, void*);
	s = ft_ulltoa_base((unsigned long int)p, 16);
	ft_str_to_lower(&s);
	len = (p == NULL && z->precision_flag == 1 && z->precision >= 0) ? 0
			: (int)ft_strlen(s);
	spec_flag = (p == NULL && z->precision_flag == 1 && z->precision >= 0) ? 1
			: 0;
	z->precision = z->precision > len ? z->precision - len : 0;
	len += z->precision + 2;
	z->width = z->width > len ? z->width - len : 0;
	len += z->width;
	print_min_flag(z, s, spec_flag);
	z->n_chars += len;
	free(s);
}
