#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdarg.h>

/*
 ** struct to store flags, width, precision, arg_type, length
 */

typedef struct	s_cp
{
	u_int		flag;
	size_t		width;
	size_t 		precision;
	char		arg_type;
	size_t		length;
}				t_cp;

/*
 ** ------------main_func-------------
 */

int				ft_printf(const char * format, ...);

/*
 ** ------------parser_func-----------
 */

t_cp			parse(char *str);

#endif
