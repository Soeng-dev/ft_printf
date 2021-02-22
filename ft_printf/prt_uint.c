/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:54:55 by soekim            #+#    #+#             */
/*   Updated: 2021/02/22 19:44:39 by soekim           ###   ########.fr       */
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

int		prt_convint(long long int i, t_tag tag, int digitlen, int total_intlen)
{
	int	prtlen;

	prtlen = 0;
	if (tag.zero_flag)
	{
		if (i < 0)
			prtlen += iter_write('-', 1);
		else if (tag.sign_flag)
			prtlen += iter_write(tag.sign_flag, 1);
		prtlen += iter_write('0', tag.width - digitlen - prtlen);
	}
	else if (tag.aligned == RIGHT)
		prtlen += iter_write(' ', tag.width - total_intlen);
	if (tag.zero_flag == FALSE)
	{
		if (i < 0)
			prtlen += iter_write('-', 1);
		else if (tag.sign_flag)
			prtlen += iter_write(tag.sign_flag, 1);
	}
	prtlen += iter_write('0', tag.precision - digitlen);
	if (digitlen)
		ft_putnbr_fd((i < 0) ? (-i) : (i), 1);
	prtlen += digitlen;
	if (tag.aligned == LEFT)
		prtlen += iter_write(' ', tag.width - prtlen);
	return (prtlen);
}

int		prt_int(va_list param, t_tag tag)
{
	long long int	i;
	long long int	temp;
	int				total_intlen;
	int				digitlen;

	i = get_intarg(param, tag.memlen);
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
	return (prt_convint(i, tag, digitlen, total_intlen));
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
	total_intlen = get_total_intlen(digitlen, 1, tag);
	return (prt_convuint(i, tag, digitlen, total_intlen));
}
