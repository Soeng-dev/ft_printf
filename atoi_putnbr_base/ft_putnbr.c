/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <soekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:53:49 by soekim            #+#    #+#             */
/*   Updated: 2020/08/13 00:10:33 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char c;

	if (nb > 9 || nb < -9)
	{
		c = nb % 10;
		if (c < 0)
			c = -c + '0';
		else
			c = c + '0';
	}
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			c = -nb + '0';
		}
		else
			c = nb + '0';
		write(1, &c, 1);
		return ;
	}
	ft_putnbr(nb / 10);
	write(1, &c, 1);
}
