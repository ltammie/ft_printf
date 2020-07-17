#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdarg.h>


//delete
#include <stdio.h>
//delete

/*
 ** struct to store flags, width, precision, arg_type, length
 */

typedef struct	s_cp
{
	int			hashtag_flag;
	int 		zero_flag;
	int 		minus_flag;
	int 		plus_flag;
	int 		space_flag;
	size_t		width;
	size_t 		precision;
	char		arg_type;
	size_t		length;
}				t_cp;

/*
 ** ------------main_funcs-------------
 */

int				ft_printf(const char * format, ...);

/*
 ** ------------parser_funcs-----------
 */

t_cp			ft_parse(const char *str, int index);
int				parse_flags(const char *str, int index, t_cp *z);
int				parse_width(const char *str, int index, t_cp *z);
int				parse_precision(const char *str, int index, t_cp *z);
void			parse_type(const char *str, int index, t_cp *z);

/*
 ** ------------pr_funcs----------------
 */

//int				ft_pr(t_cp parsed_str);

/*
 ** ------------utils----------------
 */

int				get_nbr_length(int nbr);
int				is_nonzero_digit(int c);

/*
 ** -------------tmp--------------
 */

void		print_struct(t_cp res);

#endif
