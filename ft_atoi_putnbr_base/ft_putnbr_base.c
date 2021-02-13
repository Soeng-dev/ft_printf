/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <soekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 03:38:51 by soekim            #+#    #+#             */
/*   Updated: 2020/08/11 22:38:56 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		print_digit(long int n, char *base, int base_size)
{
	int len;

	if (n < base_size)
	{
		write(1, &base[n], 1);
		return (1);
	}
	else
	{
		len = print_digit(n / (long int)base_size, base, base_size);
		n %= (long int)base_size;
		write(1, &base[n], 1);
		return (len + 1);
	}
}

int		ft_putnbr_base(int nbr, char *base, int base_size)
{
	int			base_size;
	long int		n;

	n = (long int)nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	return (print_digit(n, base, base_size));
}
