/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim </var/mail/soekim>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:00:51 by soekim            #+#    #+#             */
/*   Updated: 2021/02/09 17:40:46 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*only defined flag priority (indicated by gcc compiler) considered in tag managing part
**others at conversion part (for extensibility of flag condition)*/

// make this functions extensible for bonus
int		prt_param(const char **spec, va_list param)
{
	t_tag		tag;

	ft_memset((void*)&tag, 0, sizeof(tag));
	tag.precision = UNSET;
	//-0.*
	while (*(++(*spec)))
	{
		if (**spec == '0' && tag.aligned == RIGHT)
			tag.zero_flag = TRUE;
		else if (ft_isdigit(**spec))
		{
			tag.width = ft_atoi(*spec);
			while (ft_isdigit(*(*spec + 1)))
				++(*spec);
		}
		else if (**spec == '-')
		{
			tag.aligned = LEFT;
			tag.zero_flag = FALSE;
		}
		else if (**spec == '.')
		{
			if (ft_isdigit(*(*spec + 1)))
			{
				tag.precision = ft_atoi(++(*spec));
				while (ft_isdigit(*(*spec + 1)))
					++(*spec);
			}
			else
				tag.precision = 0;
		}
		else if (**spec == '*')
			tag.width = va_arg(param, int);
		else
			break;//break loop when meet char is not flag
	}
	//print data with specified conversion
	//may need to divide into function prt_data
	if (**spec == 'c')
		return (prt_char(param, tag));
	else if (**spec == 's')
		return (prt_str(param, tag));
	if (tag.precision != UNSET)
		tag.zero_flag = FALSE;
	if (**spec == 'd' || **spec == 'i')
		return (prt_int(param, tag));
	else if (**spec == 'u') 
		return (prt_uint(param, tag));
	else if (**spec == 'p') 
		return (prt_ptr(param, tag));
	else if (**spec == 'x' || **spec == 'X')
	{
		if (**spec == 'X')
			return (prt_hexa(param, tag, TRUE));
		else
			return (prt_hexa(param, tag, FALSE));
	}
	else
		return (0);
}

int		ft_printf(const char *format, ...)
{
	int		prtlen;
	va_list		param;

	prtlen = 0;
	va_start(param, ft_strlen(format));
	while (*format)
	{	
		if (*format == '%')
			prtlen += (prt_param(&format, param));
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
