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

int		get_base(char type)
{
	if (type == 'u')
		return (10);
	if (type == 'o')
		return (8);
	return (16);
}

void	print_width(int width, char pad)
{
	int i;

	i = -1;
	while (++i < width)
		ft_putchar(pad);

}
