#include "includes/ft_printf.h"

//maybe pass a single char?? we dont need a full string. or do?

void		parse_type(const char *str, int index, t_cp *z)
{
	z->arg_type = str[index]; // do we even need this function after this??
	z->length++;
	printf("length = %d\n", z->length);
}
