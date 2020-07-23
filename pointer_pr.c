#include "includes/ft_printf.h"

int 	pointer_pr(t_cp *z, va_list ap)
{
	void *p;
	char *s;

	p = (void*)va_arg(ap, void*);
	s = ft_ulltoa_base((unsigned long int)p, 16);
	s = ft_str_to_lower(s);
	s = ft_strjoin("0x", s);
	if (z->minus_flag == 1)
	{
		ft_putstr(s);
		print_width(z->width - ft_strlen(s), ' ');
	}
	else
	{
		print_width(z->width - ft_strlen(s), ' ');
		ft_putstr(s);
	}
	return (0);
}

