/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:58:33 by soekim            #+#    #+#             */
/*   Updated: 2021/02/19 19:19:14 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuint_fd(unsigned long long n, int fd)
{
	char	num;

	if (n < 10)
	{
		n += '0';
		num = (char)n;
		write(fd, &num, 1);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	num = (char)((n % 10) + '0');
	write(fd, &num, 1);
	return ;
}
