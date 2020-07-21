#include "includes/ft_printf.h"

int		get_nbr_length(int nbr)
{
	int len;

	len = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int		is_flag(int c)
{
	if (c == '0' || c == '-' || c == '+' || c == ' ' || c == '#')
		return (1);
	return (0);
}

void	print_width(int width)
{
	int i;

	i = 0;
	while (++i < width)
		ft_putchar(' ');

}
