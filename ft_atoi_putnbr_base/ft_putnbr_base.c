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

#include <unistd.h>

void	print_digit(long int n, char *base, int base_size)
{
	if (n < base_size)
		write(1, &base[n], 1);
	else
	{
		print_digit(n / (long int)base_size, base, base_size);
		n %= (long int)base_size;
		write(1, &base[n], 1);
	}
}

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return ((int)0);
		else
		{
			j = i + 1;
			while (base[j] != '\0')
			{
				if (base[j] == base[i])
					return ((int)0);
				j++;
			}
			i++;
		}
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_size;
	long int	n;

	base_size = check_base(base);
	if (base_size <= (int)1)
		return ;
	else
	{
		n = (long int)nbr;
		while (base[base_size] != '\0')
			base_size++;
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		print_digit(n, base, base_size);
	}
}
