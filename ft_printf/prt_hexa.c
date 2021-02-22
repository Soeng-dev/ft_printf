/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:53:39 by soekim            #+#    #+#             */
/*   Updated: 2021/02/21 21:40:26 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_total_hexalen(int sig_digitlen, t_tag tag)
{
	int	total_hexalen;

	total_hexalen = ftmax(tag.precision, sig_digitlen);
	if (tag.zero_flag)
		total_hexalen = ftmax(tag.width, total_hexalen);
	return (total_hexalen);
}

int		prt_alignchar(t_tag tag, int total_hexalen, int sig_digitlen)
{
	int prtlen;

	prtlen = 0;
	if (tag.zero_flag)
		prtlen += iter_write('0', tag.width - sig_digitlen);
	else if (tag.aligned == RIGHT)
		prtlen += iter_write(' ', tag.width - total_hexalen);
	if (tag.aligned == LEFT)
		prtlen += iter_write(' ', tag.width - prtlen);
	return (prtlen);
}

int		prt_hexa(va_list param, t_tag tag, int is_capital)
{
	unsigned long long	i;
	unsigned long long	temp;
	int			prtlen;
	int					total_hexalen;
	int					sig_digitlen;

	sig_digitlen = (prtlen = 0);
	temp = (i = get_uintarg(param, tag.memlen));
	while (temp > 0)
	{
		temp /= 16;
		++sig_digitlen;
	}
	if (tag.precision == UNSET && sig_digitlen == 0)
		++sig_digitlen;
	total_hexalen = get_total_hexalen(sig_digitlen, tag);
	prtlen += prt_alignchar(tag, total_hexalen, sig_digitlen);
	prtlen += iter_write('0', tag.precision - sig_digitlen);
	if (is_capital && sig_digitlen)
		ft_putnbr_base(i, "0123456789ABCDEF", 16);
	else if (is_capital == FALSE && sig_digitlen)
		ft_putnbr_base(i, "0123456789abcdef", 16);
	prtlen += sig_digitlen;
	prtlen += prt_alignchar(tag, total_hexalen, sig_digitlen);
	return (prtlen);
}
