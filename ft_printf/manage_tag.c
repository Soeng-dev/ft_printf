/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_tag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <soekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:33:42 by soekim            #+#    #+#             */
/*   Updated: 2021/02/22 17:34:54 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_width(const char **spec)
{
	int		width;

	width = ft_atoi(*spec);
	while (ft_isdigit(*(*spec + 1)))
		++(*spec);
	return (width);
}

int		get_precision(const char **spec, va_list param)
{
	int		precision;

	if (ft_isdigit(*(*spec + 1)))
	{
		precision = ft_atoi(++(*spec));
		while (ft_isdigit(*(*spec + 1)))
			++(*spec);
	}
	else if (*(*spec + 1) == '*')
	{
		if ((precision = va_arg(param, int)) < 0)
			precision = UNSET;
		++(*spec);
	}
	else
		precision = 0;
	return (precision);
}

void	get_widtharg(va_list param, t_tag *tag)
{
	tag->width = va_arg(param, int);
	if (tag->width < 0)
	{
		tag->width = -tag->width;
		tag->aligned = LEFT;
		tag->zero_flag = FALSE;
	}
}

int		get_memlen(const char **spec, int memlen)
{
	if (**spec == 'l')
	{
		if (memlen == 0)
			memlen = L;
		else if (memlen == L)
			memlen = LL;
	}
	else if (**spec == 'h')
	{
		if (memlen == 0)
			memlen = H;
		else if (memlen == H)
			memlen = HH;
	}
	return (memlen);
}

void	align_left(t_tag *tag)
{
	tag->aligned = LEFT;
	tag->zero_flag = FALSE;
	return ;
}
