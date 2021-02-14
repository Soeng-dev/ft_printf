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

int		ft_atoi_base(char *str, char *base, int base_size)
{
	int ret;
	int sign;
	int converted_digit;

	ret = 0;
	sign = 1;
	if (base_size <= 1)
		return (-1);
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
