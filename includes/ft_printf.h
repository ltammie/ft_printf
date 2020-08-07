#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#define MAX_SIZE 1000000
#define BASE 10000
#include "../libft/libft.h"
#include <stdarg.h>


//delete
#include <stdio.h>
//delete

/*
 ** struct to store flags, width, precision, arg_type, length
 */

typedef	union		u_f
{
	float			f;
	struct			s_fs
	{
		unsigned int m : 23;
		unsigned int e : 8;
		unsigned int s : 1;
	}				t_fs;
}					t_f;

typedef	union		u_d
{
	long double		d;
	struct			s_ds
	{
		unsigned long m : 64;
		unsigned int e : 15;
		unsigned int s : 1;
	}				t_ds;
}					t_d;

typedef struct 		s_lf
{
	int 			n[MAX_SIZE];
	int 			exp;
}					t_lf;

typedef struct		s_cp
{
	int				hash_flag;
	int 			zero_flag;
	int 			minus_flag;
	int 			plus_flag;
	int 			space_flag;
	int				width;
	int 			precision;
	int 			precision_flag;
	char			arg_type;
	int				length;
	int 			ast_w;
	int 			ast_p;
	int 			h_flag;
	int 			hh_flag;
	int 			l_flag;
	int 			ll_flag;
	int 			L_flag;
	int				n_chars;
}					t_cp;

/*
 ** ------------main_funcs-------------
 */

int					ft_printf(const char * format, ...);

/*
 ** ------------parser_funcs-----------
 */

t_cp				*ft_parse(const char *str, int index);
int					parse_flags(const char *str, int index, t_cp *z);
int					parse_width(const char *str, int index, t_cp *z);
int					parse_precision(const char *str, int index, t_cp *z);
int					parse_length(const char *str, int index, t_cp *z);
void				parse_type(const char *str, int index, t_cp *z);

/*
 ** ------------pr_funcs----------------
 */

int					pr(t_cp *parsed_str, va_list ap);
void				c_pr(t_cp *z, va_list ap);
void				s_pr(t_cp *z, va_list ap);
void				percent_pr(t_cp *z);
void				uoxX_pr(t_cp *z, va_list ap);
void				di_pr(t_cp *z, va_list ap);
void				pointer_pr(t_cp *z, va_list ap);
void				f_pr(t_cp *z, va_list ap);

/*
 ** ------------utils----------------
 */

int					get_nbr_length(int nbr);
int					is_flag(int c);
int					print_width(int width, char pad);
unsigned long long	u_cast(t_cp *z, va_list ap);
long long			cast_di(t_cp *z, va_list ap);
long double			cast_f(t_cp *z, va_list ap);
int					get_base(char type);
char				*ft_fill_str(char c, int len);

/*
 ** -------------arbitrary precision arithmetic--------------
 */

t_lf				*new_long_number();
void				long_mul_short(int s, t_lf *l);
t_lf				*pow_long(int p, int c);
void				long_sum_long(t_lf *a, t_lf *b);
char				*long_to_str(t_lf *a);
char				*lfraction_to_str(t_lf *a);
void				long_div_two(t_lf *l);
void				fraction_mul_short(int s, t_lf *l);
t_lf				*pow_fraction(int p, int c);
void				fraction_sum_fraction(t_lf *a, t_lf *b);


/*
 ** -------------tmp--------------
 */

void				print_struct(t_cp *res);
void				print_number(t_lf *n);
void				print_fraction(t_lf *n);

#endif
