#include "includes/ft_printf.h"

int		get_nbr_length(int nbr)
{
	int len;

	len = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
