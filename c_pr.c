#include "includes/ft_printf.h"

int			ft_c_pr(t_cp z)
{
	char	*w;
	int 	final_width;

	final_width = z.width > 0 ? z.width : 1;
	w = (char*)malloc(sizeof(char) * final_width); // find a way to not use malloc



}
