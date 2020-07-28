#include "libft.h"

char		*ft_strjoin_clr(char *a, char *b, int d)
{
	char	*s;

	if (!(s = ft_strnew(ft_strlen(a) + ft_strlen(b))))
		return (NULL);
	if (a)
		ft_strcat(s, a);
	if (b)
		ft_strcat(s, b);
	if (d == 2 || d == 0)
		free(a);
	if (d == 2 || d == 1)
		free(b);
	return (s);
}
