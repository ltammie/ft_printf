/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltammie <ltammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:22:05 by ltammie           #+#    #+#             */
/*   Updated: 2020/07/17 01:40:17 by sauron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		ft_printf(const char *format, ...)
{
	int 	n_chars;
	int 	i;
	va_list pr;

	n_chars = 0;
	i = 0;
	va_start(pr, format);
	while (format[i] != '%' && format [i] != '\0')
	{
		write(1, format, 1);
		i++;
	}
	va_end(pr);
	return (n_chars);
}

