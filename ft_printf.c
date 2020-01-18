/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltammie <ltammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:22:05 by ltammie           #+#    #+#             */
/*   Updated: 2020/01/18 17:56:00 by ltammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char * format, ...)
{
	int 	nchars;
	va_list pr;

	nchars = 0;
	va_start(pr, format);

	//...//

	va_end(pr);
	return (nchars);
}

int 	main(void)
{
	
}
