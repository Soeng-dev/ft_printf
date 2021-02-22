/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:53:39 by soekim            #+#    #+#             */
/*   Updated: 2021/02/22 17:24:28 by soekim           ###   ########.fr       */
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

int		get_sig_digitlen(unsigned long long i, int precision)
{
	int	sig_digitlen;

	sig_digitlen = 0;
	while (i > 0)
	{
		i /= 16;
		++sig_digitlen;
	}
	if (precision == UNSET && sig_digitlen == 0)
		++sig_digitlen;
	return (sig_digitlen);
}

int		prt_hexa(va_list param, t_tag tag, int is_capital)
{
	unsigned long long	i;
	int					prtlen;
	int					total_hexalen;
	int					sig_digitlen;

	prtlen = 0;
	i = get_uintarg(param, tag.memlen);
	sig_digitlen = get_sig_digitlen(i, tag.precision);
	total_hexalen = get_total_hexalen(sig_digitlen, tag);
	if (tag.zero_flag)
		prtlen += iter_write('0', tag.width - sig_digitlen);
	else if (tag.aligned == RIGHT)
		prtlen += iter_write(' ', tag.width - total_hexalen);
	prtlen += iter_write('0', tag.precision - sig_digitlen);
	if (is_capital && sig_digitlen)
		prtlen += ft_putnbr_base(i, "0123456789ABCDEF", 16);
	else if (is_capital == FALSE && sig_digitlen)
		prtlen += ft_putnbr_base(i, "0123456789abcdef", 16);
	if (tag.aligned == LEFT)
		prtlen += iter_write(' ', tag.width - prtlen);
	return (prtlen);
}
