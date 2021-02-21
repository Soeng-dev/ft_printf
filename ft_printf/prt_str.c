/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:51:05 by soekim            #+#    #+#             */
/*   Updated: 2021/02/21 21:40:53 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prt_str(va_list param, t_tag tag)
{
	char	*str;
	int		prtlen;
	int		strlen;

	str = va_arg(param, char *);
	if ((strlen = (int)ft_strlen(str)) == IS_NULL)
	{
		str = "(null)";
		strlen = 6;
	}
	if (tag.precision != UNSET)
		strlen = ftmin(strlen, tag.precision);
	prtlen = 0;
	if (tag.zero_flag)
		prtlen += iter_write('0', tag.width - strlen);
	else if (tag.aligned == RIGHT)
		prtlen += iter_write(' ', tag.width - strlen);
	write(1, str, strlen);
	prtlen += strlen;
	if (tag.aligned == LEFT)
		prtlen += iter_write(' ', tag.width - prtlen);
	return (prtlen);
}
