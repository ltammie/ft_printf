#include "../includes/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}
