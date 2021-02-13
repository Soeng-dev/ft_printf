/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:58:33 by soekim            #+#    #+#             */
/*   Updated: 2020/11/19 15:45:05 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(long long int n, int fd)
{
	char	num;

	if (n >= 0 && n < 10)
	{
		n += '0';
		num = (char)n;
		write(fd, &num, 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == LLONG_MIN)
		{
			write(1, "-9223372036854775808", 21);
			return ;
		}
		ft_putnbr_fd(-n, fd);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	num = (char)((n % 10) + '0');
	write(fd, &num, 1);
	return ;
}
