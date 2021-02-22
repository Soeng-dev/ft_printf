/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:52:26 by soekim            #+#    #+#             */
/*   Updated: 2021/02/21 21:40:44 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_total_addrlen(int sig_addrlen, t_tag tag)
{
	int	total_addrlen;

	total_addrlen = ftmax(tag.precision, 2 + sig_addrlen);
	if (tag.zero_flag)
		total_addrlen = ftmax(tag.width, total_addrlen);
	return (total_addrlen);
}
int	prt_addr(unsigned long long addr, int total_addrlen, int sig_addrlen, t_tag tag)
{
	int prtlen;

	prtlen = 0;
	if (tag.zero_flag)
	{
		write(1, "0x", 2);
		prtlen += 2;
		prtlen += iter_write('0', tag.width - sig_addrlen);
	}
	else if (tag.aligned == RIGHT)
		prtlen += iter_write(' ', tag.width - total_addrlen);
	if (tag.zero_flag == FALSE)
	{
		write(1, "0x", 2);
		prtlen += 2;
	}
	prtlen += iter_write('0', tag.precision - sig_addrlen);
	if (sig_addrlen)
		ft_putnbr_base(addr, "0123456789abcdef", 16);
	prtlen += sig_addrlen;
	if (tag.aligned == LEFT)
		prtlen += iter_write(' ', tag.width - prtlen);
	return (prtlen);
}

int		prt_ptr(va_list param, t_tag tag)
{
	unsigned long long	addr;
	unsigned long long	temp;
	int					total_addrlen;
	int					sig_addrlen;

	addr = (unsigned long long)va_arg(param, void *);
	temp = addr;
	sig_addrlen = 0;
	while (temp > 0)
	{
		temp /= 16;
		++sig_addrlen;
	}
	if (tag.precision == UNSET && sig_addrlen == 0)
		++sig_addrlen;
	total_addrlen = get_total_addrlen(sig_addrlen, tag);
	return (prt_addr(addr, total_addrlen, sig_addrlen, tag));
}
