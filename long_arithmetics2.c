#include "includes/ft_printf.h"

void	long_div_two(t_lf *l)
{
	int 	i;

	i = -1;
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
