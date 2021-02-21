/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <soekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 03:38:51 by soekim            #+#    #+#             */
/*   Updated: 2021/02/21 20:11:24 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_base(unsigned long long n, char *base,\
						unsigned long long base_size)
{
	int len;

	if (n < base_size)
	{
		write(1, base + n, 1);
		return (1);
	}
	else
	{
		len = ft_putnbr_base(n / base_size, base, base_size);
		n %= base_size;
		write(1, base + n, 1);
		return (len + 1);
	}
}
