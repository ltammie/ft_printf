#include "includes/ft_printf.h"

t_lf 	*new_long_number(int exp)
{
	t_lf	*new_number;
	int 	i;

	new_number = (t_lf*)malloc(sizeof(t_lf));
	i = -1;
	while (++i < MAX_SIZE)
		new_number->n[i] = 0;
	new_number->exp = exp;
	return (new_number);
}

void	long_mul_short(int s, t_lf *l)
{
	int 	i;

	i = -1;
	while (++i < MAX_SIZE)
		l->n[i] = l->n[i] * s;
	i = -1;
	while (++i < MAX_SIZE)
	{
		l->n[i + 1] = l->n[i + 1] + l->n[i] / 10;
		l->n[i] = l->n[i] % 10;
	}
}

t_lf 	*pow_long(int p, int c)
{
	t_lf	*res;

	res = new_long_number(p);
	res->n[0] = 1;
	while (p > 0)
	{
		long_mul_short(c, res);
		p--;
	}
	return (res);
}

void	long_sum_long(t_lf *a, t_lf *b)
{
	int i;
	int remainder;

	i = 0;
	remainder = 0;
	if (a->exp < b->exp)
		long_add_zeroes(a, b->exp);
	while(i < MAX_SIZE)
	{
		remainder = remainder + a->n[i] + b->n[i];
		a->n[i] = remainder % 10;
		remainder /= 10;
		i++;
	}
}

void	long_add_zeroes(t_lf *a, int new_exp)
{
	int	i;
	int	shift;

	i = a->exp - 1;
	shift = new_exp - a->exp;
	while (i >= 0)
	{
		a->n[i + shift] = a->n[i];
		a->n[i] = 0;
		i--;
	}
	a->exp = new_exp;
}

//delete
void	print_number(t_lf *n)
{
	int i;

	i = MAX_SIZE - 1;
	while(n->n[i] == 0 && i > 1)
		i--;
	while(i >= 0)
	{
		printf("%d", n->n[i]);
		i--;
	}
	printf("\n");
}
