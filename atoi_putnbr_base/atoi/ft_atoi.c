/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <soekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 03:04:43 by soekim            #+#    #+#             */
/*   Updated: 2020/08/12 23:23:31 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int ret;
	int sign;

	sign = 1;
	ret = 0;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		sign = (*str == '+') ? (sign) : (-sign);
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		ret = 10 * ret + (*str - '0');
		str++;
	}
	return (sign * ret);
}
