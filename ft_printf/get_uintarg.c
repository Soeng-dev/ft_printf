/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uintarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <soekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:37:54 by soekim            #+#    #+#             */
/*   Updated: 2021/02/22 15:40:33 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	get_uintarg(va_list param, int memlen)
{
	unsigned long long		i;

	i = 0;
	if (memlen == 0)
		i = (unsigned long long)va_arg(param, unsigned int);
	else if (memlen == L)
		i = (unsigned long long)va_arg(param, unsigned long);
	else if (memlen == LL)
		i = (unsigned long long)va_arg(param, unsigned long long);
	else if (memlen == H)
		i = (unsigned long long)(va_arg(param, unsigned int) & (0xffff));
	else if (memlen == HH)
		i = (unsigned long long)(va_arg(param, unsigned int) & (0xff));
	return (i);
}
