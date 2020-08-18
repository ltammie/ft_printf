#include "../includes/ft_printf.h"

char	*int_part_util(int i, t_lf *a)
{
	int		f;
	char	*res;
	char	*tmp;
	char	*tmp2;

	res = ft_strnew(1);
	f = i;
	while (i >= 0)
	{
		tmp = ft_itoa(a->n[i]);
		if ((int)ft_strlen(tmp) < 4 && i != f)
		{
			tmp2 = ft_fill_str('0', 4 - (int)ft_strlen(tmp));
			tmp = ft_strjoin_free(&tmp2, &tmp);
		}
		res = ft_strjoin_free(&res, &tmp);
		i--;
	}
	return (res);
}

char	*fr_part_util(int j, t_lf *a)
{
	int		i;
	char	*res;
	char	*tmp;
	char	*tmp2;

	res = ft_strnew(1);
	i = 1;
	while (i <= j)
	{
		tmp = ft_itoa(a->n[i]);
		if ((int)ft_strlen(tmp) < 4)
		{
			tmp2 = ft_fill_str('0', 4 - (int)ft_strlen(tmp));
			tmp = ft_strjoin_free(&tmp2, &tmp);
		}
		res = ft_strjoin_free(&res, &tmp);
		i++;
	}
	return (res);
}
