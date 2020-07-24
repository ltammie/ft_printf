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

int	print_width(int width, char pad)
{
	int i;

	i = -1;
	while (++i < width)
		ft_putchar(pad);
	return (i);

}

char	*ft_fill_str(char c, int len)
{
	char *str;
	int i;

	if (len < 0)
		return ("\0");
	str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	str[len] = '\0';
	return (str);
}
