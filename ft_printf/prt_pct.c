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
		prtlen += iter_write('0', tag.width - 1);
	else if (tag.aligned == RIGHT)
		prtlen += iter_write(' ', tag.width - 1);
	ft_putchar_fd('%', 1);
	++prtlen;
	if (tag.aligned == LEFT)
		prtlen += iter_write(' ', tag.width - prtlen);
	return (prtlen);
}
