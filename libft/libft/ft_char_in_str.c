#include "libft.h"

int 	ft_char_int_str(const char *s, int c)
{
	unsigned char	sym;
	char			*str;
	size_t			i;

	sym = (unsigned char)c;
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == sym)
			return (1);
		i++;
	}
	return (0);
}
