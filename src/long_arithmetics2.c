#include "../includes/ft_printf.h"

void	long_div_two(t_lf *l)
{
	int		i;

	i = 0;
	l->n[0] /= 2;
	while (++i < MAX_SIZE)
	{
		if (l->n[i] % 2 == 0)
			l->n[i] /= 2;
		else
		{
			l->n[i] = l->n[i] * BASE / 2;
			l->n[i - 1] += l->n[i] % BASE;
			l->n[i] /= BASE;
		}
	}
}

void	fraction_mul_short(int s, t_lf *l)
{
	int		i;
	int		carry;

	i = MAX_SIZE - 2;
	while (i >= 0)
	{
		carry = l->n[i] * s;
		l->n[i + 1] = l->n[i + 1] + carry % BASE;
		l->n[i] = carry / BASE;
		i--;
	}
}

t_lf	*pow_fraction(int p, int c)
{
	t_lf	*res;

	res = new_long_number(p);
	res->n[0] = 1;
	while (p > 0)
	{
		fraction_mul_short(c, res);
		p--;
	}
	return (res);
}
