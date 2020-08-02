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
	int f;
	char *str;
	char *tmp;

	i = MAX_SIZE - 1;
	while (a->n[i] == 0 && i > 0)
		i--;
	if (i == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
		return (str);
	}
	str = ft_strnew(1);
	f = i;
	while(i >= 0)
	{
		tmp = ft_itoa(a->n[i]);
		if ((int)ft_strlen(tmp) < 4 && i != f)
			tmp = ft_strjoin(ft_fill_str('0', 4 - (int)ft_strlen(tmp)), tmp);
		str = ft_strjoin(str, tmp);
		i--;
	}
	return (str);
}
