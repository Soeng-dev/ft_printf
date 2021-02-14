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

// make this functions extensible for bonus
int		prt_data(const char **spec, va_list param)
{
	int		prtlen;
	t_tag		tag;

	prtlen = 0;
	ft_memset((void*)&tag, 0, sizeof(tag));
	//-0.*
	//consider flag priority here
	while (*(++(*spec)))
	{
		if (**spec == '0')
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
				tag.zero_flag = FALSE; 
			}
		}
		else if (**spec == '*')
			tag.width = va_arg(param, int);
		else
			break;//break loop when meet char is not flag
	}
	//print data with pecified conversion
	//may need to divide into function prt_data
	if (**spec == 'c') ;
		//prtlen = prt_char(param, tag);
	else if (**spec == 's') ;
	//	prtlen = prt_str(param, tag);
	else if (**spec == 'p') 
	{
		//use print_memory
	//	va_arg
	}
	else if (**spec == 'd' || **spec == 'i')
		prtlen = prt_int(param, tag);
	else if (**spec == 'u') ;
		//prtlen = prt_uint(param, tag);
	else if (**spec == 'x' || **spec == 'X') ;
		//prtlen = prt_uhexa(param, tag);
	else
	{
		prtlen = 0;
		//while (*(--(*spec)) != '%');
		//return (0);
	}
	return (prtlen);
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
			prtlen += (prt_data(&format, param));
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


int main()
{
	ft_printf("%013d\n", 7);
}
