/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <soekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 20:58:43 by soekim            #+#    #+#             */
/*   Updated: 2020/08/13 02:25:30 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (9 <= base[i] && base[i] <= 13))
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
		}
		i++;
	}
	return (i);
}

int		convert_digit(char digit, char *base)
{
	int ret;

	ret = 0;
	while (base[ret] != '\0')
	{
		if (base[ret] == digit)
			return (ret);
		ret++;
	}
	return (ret);
}

int		ft_atoi_base(char *str, char *base)
{
	int base_size;
	int ret;
	int sign;
	int converted_digit;

	ret = 0;
	sign = 1;
	base_size = check_base(base);
	if (base_size <= 1)
		return (0);
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		sign = (*str == '+') ? (sign) : (-sign);
		str++;
	}
	converted_digit = convert_digit(*str, base);
	while (converted_digit < base_size && *str != '\0')
	{
		ret = ret * base_size + converted_digit;
		str++;
		converted_digit = convert_digit(*str, base);
	}
	return (sign * ret);
}
