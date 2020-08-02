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
	print_number(l);
	while (++i < MAX_SIZE)
	{
		l->n[i + 1] = l->n[i + 1] + l->n[i] / BASE;
		l->n[i] = l->n[i] % BASE;
	}
	print_number(l);
}

void	fraction_mul_short(int s, t_lf *l)
{
	int 	i;
	int 	carry;

	i = MAX_SIZE - 2;
	while (i >= 0)
	{
		carry = l->n[i] * s;
		l->n[i + 1] = l->n[i + 1] + carry % BASE;
		l->n[i] = carry / BASE;
		i--;
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

t_lf 	*pow_fraction(int p, int c)
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

void	long_sum_long(t_lf *a, t_lf *b)
{
	int i;
	int remainder;

	i = 0;
	remainder = 0;
	while(i < MAX_SIZE)
	{
		remainder = remainder + a->n[i] + b->n[i];
		a->n[i] = remainder % BASE;
		remainder /= BASE;
		i++;
	}
}

void	fraction_sum_fraction(t_lf *a, t_lf *b)
{
	int i;
	int remainder;

	i = 0;
	remainder = 0;
	while(i < MAX_SIZE)
	{
		remainder = a->n[i] + b->n[i];
		a->n[i - 1] += remainder / BASE;
		a->n[i] = remainder % BASE;
		i++;
	}
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

void	print_fraction(t_lf *n)
{
	int i;
	int j;

	j = MAX_SIZE - 1;
	while(n->n[j] == 0 && j > 1)
		j--;
	i = 0;
	while(i <= j)
	{
		printf("%d", n->n[i]);
		i++;
	}
	printf("\n");
}
