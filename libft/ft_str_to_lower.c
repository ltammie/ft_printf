#include "libft.h"

char	*ft_str_to_lower(const char *str)
{
	char	*res;
	int		i;

	res = ft_strdup(str);
	i = 0;
	while (res[i] != '\0')
	{
		res[i] = ft_tolower(res[i]);
		i++;
	}
	return (res);
}
