/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:54:55 by soekim            #+#    #+#             */
/*   Updated: 2021/02/22 19:46:44 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_total_uintlen(int digitlen, t_tag tag)
{
	int	total_intlen;

	total_intlen = ftmax(tag.precision, digitlen);
	if (tag.sign_flag)
		++total_intlen;
	if (tag.zero_flag)
		total_intlen = ftmax(tag.width, total_intlen);
	return (total_intlen);
}

int		prt_convuint(unsigned long long i, t_tag tag,\
				int digitlen, int total_intlen)
{
	int prtlen;

	prtlen = 0;
	if (tag.zero_flag)
		prtlen += iter_write('0', tag.width - digitlen);
	else if (tag.aligned == RIGHT)
		prtlen += iter_write(' ', tag.width - total_intlen);
	prtlen += iter_write('0', tag.precision - digitlen);
	if (digitlen)
		ft_putuint_fd(i, 1);
	prtlen += digitlen;
	if (tag.aligned == LEFT)
		prtlen += iter_write(' ', tag.width - prtlen);
	return (prtlen);
}

int		prt_uint(va_list param, t_tag tag)
{
	unsigned long long	i;
	unsigned long long	temp;
	int					total_intlen;
	int					digitlen;

	i = get_uintarg(param, tag.memlen);
	temp = i;
	digitlen = 0;
	while (temp > 0)
	{
		temp /= 10;
		++digitlen;
	}
	if (tag.precision == UNSET && digitlen == 0)
		++digitlen;
	total_intlen = get_total_uintlen(digitlen, tag);
	return (prt_convuint(i, tag, digitlen, total_intlen));
}
