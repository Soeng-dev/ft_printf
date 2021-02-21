/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 20:12:16 by soekim            #+#    #+#             */
/*   Updated: 2021/02/21 20:12:18 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	iter_write(char c, int iter)
{
	int prtlen;

	prtlen = -1;
	while (++prtlen < iter)
		write(1, &c, 1);
	if (prtlen >= 0)
		return (prtlen);
	else
		return (0);
}
