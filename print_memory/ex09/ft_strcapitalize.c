/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 23:54:18 by soekim            #+#    #+#             */
/*   Updated: 2020/08/10 18:08:26 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_up(char c)
{
	if ('A' <= c && c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		check_low(char c)
{
	if ('a' <= c && c <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		check_num(char c)
{
	if ('0' <= c && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strcapitalize(char *str)
{
	char *tab;

	tab = str;
	while (*tab != '\0')
	{
		while (!(check_up(*tab) || check_low(*tab) || check_num(*tab))
				&& *tab != '\0')
		{
			tab++;
		}
		if (check_low(*tab))
		{
			*tab += 'A' - 'a';
		}
		tab++;
		while (check_up(*tab) || check_low(*tab) || check_num(*tab))
		{
			if (check_up(*tab))
			{
				*tab += 'a' - 'A';
			}
			tab++;
		}
	}
	return (str);
}
