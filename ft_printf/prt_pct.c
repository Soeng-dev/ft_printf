/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_pct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim </var/mail/soekim>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:00:51 by soekim            #+#    #+#             */
/*   Updated: 2021/02/19 16:40:00 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prt_pct(t_tag tag)
{
	int	prtlen;

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
	ft_putchar_fd('%', 1);
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
