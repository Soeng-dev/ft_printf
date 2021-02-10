/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 02:22:33 by soekim            #+#    #+#             */
/*   Updated: 2020/08/10 21:47:02 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_hex(unsigned char c)
{
	unsigned char first_digit;

	first_digit = c / 16;
	c = c % 16;
	if (first_digit < 10)
	{
		first_digit += '0';
	}
	else
	{
		first_digit = first_digit - 10 + 'a';
	}
	if (c < 10)
	{
		c += '0';
	}
	else
	{
		c = c - 10 + 'a';
	}
	write(1, &first_digit, 1);
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char *tab;

	tab = (unsigned char *)str;
	while (*tab != '\0')
	{
		if (32 <= *tab && *tab <= 126)
		{
			write(1, tab, 1);
		}
		else
		{
			write(1, "\\", 1);
			put_hex(*tab);
		}
		tab++;
	}
}
