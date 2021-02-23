/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:41:50 by soekim            #+#    #+#             */
/*   Updated: 2021/02/22 21:28:57 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h> //test
#include "ft_printf.h"

/*
** For extensibility of flag managing,
** get_tag function considered only
** defined flag priority (indicated by compiler considered)
** others at cvt_and_prt functions
*/

void	init_tag(t_tag *tag)
{
	ft_memset((void*)tag, 0, sizeof(t_tag));
	tag->precision = UNSET;
}

t_tag	get_tag(const char **spec, va_list param)
{
	t_tag		tag;

	init_tag(&tag);
	while (*(++(*spec)))
	{
		if (**spec == '0' && tag.aligned == RIGHT)
			tag.zero_flag = TRUE;
		else if (ft_isdigit(**spec))
			tag.width = get_width(spec);
		else if (**spec == '-')
			align_left(&tag);
		else if (**spec == '.')
			tag.precision = get_precision(spec, param);
		else if (**spec == '*')
			get_widtharg(param, &tag);
		else if (**spec == 'l' || **spec == 'h')
			tag.memlen = get_memlen(spec, tag.memlen);
		else if (**spec == ' ' || **spec == '+')
			tag.sign_flag = (tag.sign_flag == ' ') ? (' ') : (**spec);
		else if (**spec == '#')
			tag.prefix = TRUE;
		else
			break ;
	}
	return (tag);
}

int		cvt_and_prt(const char **spec, va_list param, t_tag tag)
{
	if (**spec == 'c')
		return (prt_char(param, tag));
	else if (**spec == 's')
		return (prt_str(param, tag));
	else if (**spec == '%')
		return (prt_pct(tag));
	if (tag.precision != UNSET)
		tag.zero_flag = FALSE;
	if (**spec == 'd' || **spec == 'i')
		return (prt_int(param, tag));
	else if (**spec == 'u')
		return (prt_uint(param, tag));
	else if (**spec == 'p')
		return (prt_ptr(param, tag));
	else if (**spec == 'X')
		return (prt_hexa(param, tag, TRUE));
	else if (**spec == 'x')
		return (prt_hexa(param, tag, FALSE));
	--(*spec);
	return (0);
}

int		cvt_fmtspec(const char **spec, va_list param, int prtlen)
{
	const char	*start;
	t_tag		tag;

	start = *spec;
	tag = get_tag(spec, param);
	if (**spec == 'n')
	{
		*(va_arg(param, int *)) = prtlen + ((*spec - start) / sizeof(char *));
		return (0);
	}
	else
		return (cvt_and_prt(spec, param, tag));
}

int		ft_printf(const char *format, ...)
{
	int			prtlen;
	va_list		param;

	prtlen = 0;
	va_start(param, format);
	while (*format)
	{
		if (*format == '%')
			prtlen += (cvt_fmtspec(&format, param, prtlen));
		else
		{
			write(1, format, 1);
			++prtlen;
		}
		++format;
	}
	va_end(param);
	return (prtlen);
}
//
//int main()
//{
//	printf(IP);
//}
