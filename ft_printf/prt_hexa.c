/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim </var/mail/soekim>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:00:51 by soekim            #+#    #+#             */
/*   Updated: 2021/02/09 17:40:46 by soekim           ###   ########.fr       */
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
	int			prtlen;
	int			total_hexalen;
	int			sig_digitlen;

	i = (unsigned long long)va_arg(param, unsigned int);
	temp = i;
	sig_digitlen = 1;
	while ((temp /= 16) > 0)
		++sig_digitlen;
	total_hexalen = get_total_hexalen(sig_digitlen, tag);
	prtlen = 0;
	//from here print starts
	//first condition states print before significant digit numbers 
	if (tag.zero_flag)
	{
		while (prtlen < tag.width - sig_digitlen)
  		{
  			write(1, "0", 1);
  			++prtlen;
  		}
  	}
	else if (tag.aligned == RIGHT)
	{
  		while (prtlen < tag.width - total_hexalen)
  		{
  			write(1, " ", 1);
  			++prtlen;
  		}
	}
	//prints significant digit numbers
	temp = -1;
	while ((signed int)(++temp) < tag.precision - sig_digitlen)
	{
		write(1, "0", 1);
		++prtlen;
	}
	if (is_capital)
		ft_putnbr_base(i, "0123456789ABCDEF", 16);
	else 
		ft_putnbr_base(i, "0123456789abcdef", 16);
	prtlen += sig_digitlen;
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
