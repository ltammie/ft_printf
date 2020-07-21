#include "libft.h"

static int	get_size(unsigned int value, int base)
{
	int		size;

	while (tmp /= base)
		size++;
	return (size + 1;)
}

char		*ft_utoa_base(unsigned int value, int base)
{
	char			*str;
	int				size;
	char			*tab;
	unsigned int	tmp;

	flag = 0;
	size = 0;
	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	tmp = value;
	size = get_size(tmp, base)
	str = (char *)malloc(sizeof(char) * size  + 1);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(value % base)];
		size--;
		value /=base;
	}
	return (str);
}
