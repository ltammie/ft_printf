#include "includes/ft_printf.h"

char 	*long_to_str(t_lf *a)
{
	int i;
	int j;
	char *str;

	i = MAX_SIZE - 1;
	j = 0;
	while(a->n[i] == 0 && i > 1)
		i--;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while(j <= i)
	{
		str[j] = a->n[i - j] + '0';
		j++;
	}
	str[j] = '\0';
	return (str);
}
