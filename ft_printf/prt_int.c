/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim </var/mail/soekim>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:00:51 by soekim            #+#    #+#             */
/*   Updated: 2021/02/19 09:47:45 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//get length of integer consider tag
int get_total_intlen(int digitlen, int sign, t_tag tag)
{
	int	total_intlen;

	total_intlen = MAX(tag.precision, digitlen);
	if (sign < 0)
		++total_intlen;
	if (tag.zero_flag)
		total_intlen = MAX(tag.width, total_intlen);
	return (total_intlen);
}

int		prt_int(va_list param, t_tag tag)
{
	long long int	i;
	long long int	temp;
	int		prtlen;
	int		total_intlen;
	int		digitlen;

	i = (long long int)va_arg(param, int);
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
	//from here print starts
	//first condition states print before significant digit numbers 
	if (tag.zero_flag)
	{
		if (i < 0)
  		{
 			write(1, "-", 1);
			++prtlen;
  		}
		while (prtlen < tag.width - digitlen)
  		{
  			write(1, "0", 1);
  			++prtlen;
  		}
  	}
	else if (tag.aligned == RIGHT)
	{
  		while (prtlen < tag.width - total_intlen)
  		{
  			write(1, " ", 1);
  			++prtlen;
  		}
	}
	if (i < 0 && tag.zero_flag == FALSE)
	{
		write(1, "-", 1);
		++prtlen;
	}
	//prints significant digit numbers
	temp = -1;
	while (++temp < tag.precision - digitlen)
	{
		write(1, "0", 1);
		++prtlen;
	}
	temp = (i < 0) ? -i : i;
	if (digitlen)
		ft_putnbr_fd(temp, 1);
	prtlen += digitlen;
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

int		prt_uint(va_list param, t_tag tag)
{
	unsigned long long	i;
	unsigned long long	temp;
	int			prtlen;
	int			total_intlen;
	int			digitlen;

	i = (unsigned long long)va_arg(param, unsigned int);
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
	//from here print starts
	//first condition states print before significant digit numbers 
	if (tag.zero_flag)
	{
		while (prtlen < tag.width - digitlen)
  		{
  			write(1, "0", 1);
  			++prtlen;
  		}
  	}
	else if (tag.aligned == RIGHT)
	{
  		while (prtlen < tag.width - total_intlen)
  		{
  			write(1, " ", 1);
  			++prtlen;
  		}
	}
	//prints significant digit numbers
	temp = -1;
	while ((signed int)(++temp) < tag.precision - digitlen)
	{
		write(1, "0", 1);
		++prtlen;
	}
	if (digitlen)
 		ft_putnbr_fd(i, 1);
	prtlen += digitlen;
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
