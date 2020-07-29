#include "includes/ft_printf.h"

char 	*long_to_str(t_lf *a)
{
	int i;
	char *str;

	i = MAX_SIZE - 1;
	while(a->n[i] == 0 && i > 0)
		i--;
	if (i == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
		return (str);
	}
	str = ft_strnew(1);
	while(i >= 0)
		str = ft_strjoin(str, ft_itoa(a->n[i--]));
	return (str);
}

char 	*lfraction_to_str(t_lf *a)
{
	int i;
	int j;
	char *str;


	i = a->exp - 1;
	j = 0;
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
