#include "libft.h"

static int	get_size(int value, int base, int flag)
{
	int		size;

	size = 0;
	while (value /= base)
		size++;
	return (size + flag + 1);
}


char		*ft_itoa_base(int value, int base)
{
	char	*str;
	int		size;
	char	*tab;
	int		flag;
	int		tmp;

	flag = 0;
	size = 0;
	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
		flag = 1;
	tmp = value;
	size = get_size(tmp, base, flag);
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
