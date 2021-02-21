/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim </var/mail/soekim>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:00:51 by soekim            #+#    #+#             */
/*   Updated: 2021/02/19 18:23:07 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//get length of integer consider tag
int get_total_hexalen(int sig_digitlen, t_tag tag)
{
	int	total_hexalen;

	total_hexalen = MAX(tag.precision, sig_digitlen);
	if (tag.zero_flag)
		total_hexalen = MAX(tag.width, total_hexalen);
	return (total_hexalen);
}

int		prt_hexa(va_list param, t_tag tag, int is_capital)
{
	unsigned long long	i;
	unsigned long long	temp;
	int					prtlen;
	int					total_hexalen;
	int					sig_digitlen;

	if (tag.memlen == 0)
		i = (unsigned long long)va_arg(param, unsigned int);
	if (tag.memlen == L)
		i = (unsigned long long)va_arg(param, unsigned long);
	if (tag.memlen == LL)
		i = (unsigned long long)va_arg(param, unsigned long long);
	if (tag.memlen == H)
		i = (unsigned long long)(va_arg(param, unsigned int) & (0xffff));
	if (tag.memlen == HH)
		i = (unsigned long long)(va_arg(param, unsigned int) & (0xff));
	temp = i;
	sig_digitlen = 0;
	while (temp > 0)
	{
		temp /= 16;
		++sig_digitlen;
	}
	if (tag.precision == UNSET && sig_digitlen == 0)
		++sig_digitlen;
	total_hexalen = get_total_hexalen(sig_digitlen, tag);
	prtlen = 0;
	//from here print starts
	//first condition states print before significant digit numbers 
	if (tag.zero_flag)
		prtlen += iter_write('0', tag.width - sig_digitlen);
	else if (tag.aligned == RIGHT)
		prtlen += iter_write(' ', tag.width - total_hexalen);
	//prints significant digit numbers
	prtlen += iter_write('0', tag.precision - sig_digitlen);
	if (is_capital && sig_digitlen)
		ft_putnbr_base(i, "0123456789ABCDEF", 16);
	else if (is_capital == FALSE && sig_digitlen)
		ft_putnbr_base(i, "0123456789abcdef", 16);
	prtlen += sig_digitlen;
	if (tag.aligned == LEFT)
		prtlen += iter_write(' ', tag.width - prtlen);
	return (prtlen);
}
