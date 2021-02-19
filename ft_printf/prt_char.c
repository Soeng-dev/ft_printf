/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim </var/mail/soekim>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:00:51 by soekim            #+#    #+#             */
/*   Updated: 2021/02/19 17:32:01 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prt_char(va_list param, t_tag tag)
{
	int	c;
	int	prtlen;

	c = va_arg(param, int);
	prtlen = 0;
	if (tag.zero_flag)
	{
		while (prtlen < tag.width - 1)
  		{
  			write(1, "0", 1);
  			++prtlen;
  		}
  	}
	else if (tag.aligned == RIGHT)
	{
  		while (prtlen < tag.width - 1)
  		{
  			write(1, " ", 1);
  			++prtlen;
  		}
	}
	ft_putchar_fd(c, 1);
	++prtlen;
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
