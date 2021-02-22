/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:53:39 by soekim            #+#    #+#             */
/*   Updated: 2021/02/22 19:17:27 by soekim           ###   ########.fr       */
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

int		prt_sighexa(unsigned long long i, int is_capital)
{
	if (is_capital)
		return (ft_putnbr_base(i, "0123456789ABCDEF", 16));
	else
		return (ft_putnbr_base(i, "0123456789abcdef", 16));
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
		prtlen += (ft_putstr_fd((is_capital) ? "0X" : "0x", 1) \
				+ iter_write('0', tag.width - sig_digitlen));
	else if (tag.aligned == RIGHT)
		prtlen += iter_write(' ', tag.width - total_hexalen);
	if (tag.zero_flag == FALSE && tag.prefix == '#')
		prtlen += ft_putstr_fd((is_capital) ? "0X" : "0x", 1);
	prtlen += iter_write('0', tag.precision - sig_digitlen);
	if (sig_digitlen)
		prtlen += prt_sighexa(i, is_capital);
	if (tag.aligned == LEFT)
		prtlen += iter_write(' ', tag.width - prtlen);
	return (prtlen);
}
