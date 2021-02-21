/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:54:55 by soekim            #+#    #+#             */
/*   Updated: 2021/02/21 21:40:35 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_total_intlen(int digitlen, int sign, t_tag tag)
{
	int	total_intlen;

	total_intlen = ftmax(tag.precision, digitlen);
	if (sign < 0 || tag.sign_flag != 0)
		++total_intlen;
	if (tag.zero_flag)
		total_intlen = ftmax(tag.width, total_intlen);
	return (total_intlen);
}

int		prt_int(va_list param, t_tag tag)
{
	long long int	i;
	long long int	temp;
	int				prtlen;
	int				total_intlen;
	int				digitlen;

	i = 0;
	if (tag.memlen == 0)
		i = (long long int)va_arg(param, int);
	else if (tag.memlen == L)
		i = (long long int)va_arg(param, long int);
	else if (tag.memlen == LL)
		i = (long long int)va_arg(param, long long int);
	else if (tag.memlen == H)
		i = (long long int)((short)va_arg(param, int));
	else if (tag.memlen == HH)
		i = (long long int)((char)va_arg(param, int));
	temp = (i < 0) ? -i : i;
	digitlen = 0;
	while (temp > 0)
	{
		temp /= 10;
		++digitlen;
	}
	if (tag.precision != UNSET)
		tag.zero_flag = FALSE;
	if (tag.precision == UNSET && digitlen == 0)
		++digitlen;
	total_intlen = get_total_intlen(digitlen, (i >= 0) ? (1) : (-1), tag);
	prtlen = 0;
	if (tag.zero_flag)
	{
		if (i < 0)
			prtlen += iter_write('-', 1);
		prtlen += iter_write('0', tag.width - digitlen - prtlen);
	}
	else if (tag.aligned == RIGHT)
		prtlen += iter_write(' ', tag.width - total_intlen);
	if (i < 0 && tag.zero_flag == FALSE)
		prtlen += iter_write('-', 1);
	prtlen += iter_write('0', tag.precision - digitlen);
	temp = (i < 0) ? -i : i;
	if (digitlen)
		ft_putnbr_fd(temp, 1);
	prtlen += digitlen;
	if (tag.aligned == LEFT)
		prtlen += iter_write(' ', tag.width - prtlen);
	return (prtlen);
}

int		prt_uint(va_list param, t_tag tag)
{
	unsigned long long	i;
	unsigned long long	temp;
	int					prtlen;
	int					total_intlen;
	int					digitlen;

	i = 0;
	if (tag.memlen == 0)
		i = (unsigned long long)va_arg(param, unsigned int);
	else if (tag.memlen == L)
		i = (unsigned long long)va_arg(param, unsigned long);
	else if (tag.memlen == LL)
		i = (unsigned long long)va_arg(param, unsigned long long);
	else if (tag.memlen == H)
		i = (unsigned long long)(va_arg(param, unsigned int) & (0xffff));
	else if (tag.memlen == HH)
		i = (unsigned long long)(va_arg(param, unsigned int) & (0xff));
	temp = i;
	digitlen = 0;
	while (temp > 0)
	{
		temp /= 10;
		++digitlen;
	}
	if (tag.precision == UNSET && digitlen == 0)
		++digitlen;
	total_intlen = get_total_intlen(digitlen, 1, tag);
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
