/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:50:22 by soekim            #+#    #+#             */
/*   Updated: 2021/02/21 19:50:24 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prt_char(va_list param, t_tag tag)
{
	int	c;
	int	prtlen;

	c = va_arg(param, int);
	prtlen = 0;
	if (tag.zero_flag)
		prtlen += iter_write('0', tag.width - 1);
	else if (tag.aligned == RIGHT)
		prtlen += iter_write(' ', tag.width - 1);
	ft_putchar_fd(c, 1);
	++prtlen;
	if (tag.aligned == LEFT)
		prtlen += iter_write(' ', tag.width - prtlen);
	return (prtlen);
}
