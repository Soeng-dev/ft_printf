/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim </var/mail/soekim>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:00:51 by soekim            #+#    #+#             */
/*   Updated: 2021/02/09 17:40:46 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//get length of integer consider tag
int get_total_addrlen(int sig_addrlen, t_tag tag)
{
	int	total_addrlen;

	total_addrlen = 2 + MAX(tag.precision, sig_addrlen);
	if (tag.zero_flag)
		total_addrlen = MAX(tag.width, total_addrlen);
	return (total_addrlen);
}

int		prt_ptr(va_list param, t_tag tag)
{
	unsigned long long	addr;
	unsigned long long	temp;
	int			prtlen;
	int			total_addrlen;
	int			sig_addrlen;

	addr = (unsigned long long)va_arg(param, void *);
	temp = addr;
	sig_addrlen = 1;
	while ((temp /= 16) > 0)
		++sig_addrlen;
	total_addrlen = get_total_addrlen(sig_addrlen, tag);
	prtlen = 0;
	//from here print starts
	//first condition states print before significant addr numbers 
	if (tag.zero_flag)
	{
		write(1, "0x", 2);
		prtlen += 2;
		while (prtlen < tag.width - sig_addrlen)
  		{
  			write(1, "0", 1);
  			++prtlen;
  		}
  	}
	else if (tag.aligned == RIGHT)
	{
  		while (prtlen < tag.width - total_addrlen)
  		{
  			write(1, " ", 1);
  			++prtlen;
  		}
	}
	//prints significant addr numbers
	temp = -1;
	if (tag.zero_flag == FALSE)
	{
		write(1, "0x", 2);
		prtlen += 2;
	}
	while ((signed int)(++temp) < tag.precision - sig_addrlen)
	{
		write(1, "0", 1);
		++prtlen;
	}
	ft_putnbr_base(addr, "0123456789abcdef", 16);
	prtlen += sig_addrlen;
	if (tag.aligned == LEFT)
	{
		while (prtlen < tag.width)
		{
			write(1, " ", 1);
			++prtlen;
		}
	}
	return (prtlen);
}
