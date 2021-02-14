/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim </var/mail/soekim>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:00:51 by soekim            #+#    #+#             */
/*   Updated: 2021/02/09 17:40:46 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//
//int get_total_strlen(int sig_strlen, t_tag tag)
//{
//	int	total_strlen;
//
//	if (tag.zero_flag)
//		total_strlen = MAX(tag.width, sig_strlen);
//	return (total_strlen);
//}

int		prt_str(va_list param, t_tag tag)
{
	char	*str;
	char	*temp;
	int	prtlen;
	int	strlen;

	str = va_arg(param, char *);
	strlen = ft_strlen(str);
	if (tag.precision != UNSET)
		strlen = MIN(strlen, tag.precision);
	prtlen = 0;
	//from here print starts
	//first condition states print before significant digit numbers 
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
	//prints significant string characters
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
