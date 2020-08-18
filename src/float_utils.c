#include "../includes/ft_printf.h"

char		*get_int_part(int *e, int *i, const char *str)
{
	t_lf		*number;
	t_lf		*tmp;
	char		*res;

	number = new_long_number(0);
	if (*e >= 0)
	{
		tmp = pow_long(*e, 2);
		while (*e >= 0)
		{
			if (str[*i] == '1')
				long_sum_long(number, tmp);
			long_div_two(tmp);
			(*e)--;
			(*i)++;
		}
		free(tmp);
	}
	(*e) *= -1;
	res = long_to_str(number);
	free(number);
	return (res);
}

char		*get_fraction_part(int *e, int *i, const char *str)
{
	int			len;
	t_lf		*fraction;
	t_lf		*tmp;
	char		*res;

	fraction = new_long_number(0);
	len = (int)ft_strlen(str);
	tmp = pow_fraction((*e), 5000);
	while ((*i) < len)
	{
		if (str[(*i)] == '1')
			fraction_sum_fraction(fraction, tmp);
		fraction_mul_short(5000, tmp);
		tmp->exp++;
		(*e)++;
		(*i)++;
	}
	res = lfraction_to_str(fraction);
	free(fraction);
	free(tmp);
	return (res);
}

char		*long_to_str(t_lf *a)
{
	int		i;
	char	*str;

	i = MAX_SIZE - 1;
	while (a->n[i] == 0 && i > 0)
		i--;
	if (i == 0 && a->n[i] == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
		return (str);
	}
	str = int_part_util(i, a);
	return (str);
}

char		*lfraction_to_str(t_lf *a)
{
	int		j;
	char	*str;

	j = MAX_SIZE - 1;
	while (a->n[j] == 0 && j > 0)
		j--;
	if (j == 0 && a->n[j] == 0)
	{
		str = ft_strnew(1);
		str[0] = 'z';
		return (str);
	}
	str = fr_part_util(j, a);
	return (str);
}
