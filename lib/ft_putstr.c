#include "../includes/ft_printf.h"

void	ft_putstr(char const *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}
