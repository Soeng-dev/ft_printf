/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim </var/mail/soekim>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:00:51 by soekim            #+#    #+#             */
/*   Updated: 2021/02/19 15:15:43 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prt_str(va_list param, t_tag tag)
{
	char	*str;
	int		str_is_null;
	int		prtlen;
	int		strlen;
	
	str_is_null = FALSE;
	str = va_arg(param, char *);
	if ((strlen = (int)ft_strlen(str)) == IS_NULL)
	{
		if ((str = (char *)malloc(7)) == NULL)
			return (0);
		ft_memcpy(str, "(null)", 6);
		strlen = 6;
		str_is_null = TRUE;
	}
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
	if (str_is_null)
		free(str);
	return (prtlen);
}
