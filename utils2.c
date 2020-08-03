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
	char *tmp;

	j = MAX_SIZE - 1;
	while(a->n[j] == 0 && j > 1)
		j--;
	if (j == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
		return (str);
	}
	str = ft_strnew(1);
	i = 1;
	while(i <= j)
	{
//		printf("i = %d | val = %d\n",i, a->n[i]);
		tmp = ft_itoa(a->n[i]);
		if ((int)ft_strlen(tmp) < 4)
			tmp = ft_strjoin(ft_fill_str('0', 4 -(int)ft_strlen(tmp)), tmp);
		str = ft_strjoin(str, tmp);
		i++;
	}
	return (str);
}
