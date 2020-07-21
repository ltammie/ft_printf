#include "libft.h"

static int	get_size(unsigned int value, int base)
{
	int		size;

	size = 0;
	while (value /= base)
		size++;
	return (size + 1);
}

char		*ft_utoa_base(unsigned int value, int base)
{
	char			*str;
	int				size;
	char			*tab;
	unsigned int	tmp;

	size = 0;
	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	tmp = value;
	size = get_size(tmp, base);
	str = (char *)malloc(sizeof(char) * size  + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[ft_abs(value % base)];
		size--;
		value /=base;
	}
	return (str);
}
