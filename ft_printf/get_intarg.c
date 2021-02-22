/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <soekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:43:41 by soekim            #+#    #+#             */
/*   Updated: 2021/02/22 15:49:48 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	get_intarg(va_list param, int memlen)
{
	long long int	i;

	i = 0;
	if (memlen == 0)
		i = (long long int)va_arg(param, int);
	else if (memlen == L)
		i = (long long int)va_arg(param, long int);
	else if (memlen == LL)
		i = (long long int)va_arg(param, long long int);
	else if (memlen == H)
		i = (long long int)((short int)va_arg(param, int));
	else if (memlen == HH)
		i = (long long int)((char)va_arg(param, unsigned int));
	return (i);
}
