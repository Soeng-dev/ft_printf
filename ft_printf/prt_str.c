/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim </var/mail/soekim>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:00:51 by soekim            #+#    #+#             */
/*   Updated: 2021/02/19 14:29:06 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int test;
int		prt_str(va_list param, t_tag tag)
{
	char	*str;
	int		prtlen;
	int		strlen;
++test;
	str = va_arg(param, char *);
	if (test == 4481) write(1,"bfolen",6);
	strlen = (int)ft_strlen(str);
	if (test == 4481) write(1,"aftlen",6);
	if (tag.precision != UNSET)
		strlen = MIN(strlen, tag.precision);
	prtlen = 0;
	if (tag.zero_flag)
	{
		while (prtlen < tag.width - strlen)
  		{
  			write(1, "0", 1);
  			++prtlen;
  		}
  	}
	else if (tag.aligned == RIGHT)
	{
  		while (prtlen < tag.width - strlen)
  		{
  			write(1, " ", 1);
  			++prtlen;
  		}
	}
	write(1, str, strlen);
	prtlen += strlen;
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
