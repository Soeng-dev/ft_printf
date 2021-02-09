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

#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

#define TRUE 1
#define FALSE 0

// make this functions extensible for bonus
int		cvt_spec(const char **spec, va_list param)
{
	int		prtlen;

	prtlen = 0;
	while (**(++spec))
	{
		if (**spec == )
		{//record the spec in var
		}
		else if (**spec == )
		{//record the spec in var
		}
		else if (**spec == )
		{//record the spec in var
		}
		else if (**spec == )
		{//record the spec in var
		}
		else
			break;//break loop when meet char is not flag)
	}
	//print data with pecified conversion
	//may need to divide into function prt_data
	if (**spec == )
	{
		va_arg
		put*(); //need to get prt len also
	}
	else if (**spec == )
	{
		va_arg
		put*(); //need to get prt len also
	}
	else if (**spec == )
	{
		va_arg
		put*(); //need to get prt len also
	}
	else
		while(**(--spec) != '%')
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
			prtlen += (print_data(&format, param));
		write(1, format, 1);
		++format;
		++prtlen;
	}
	return (prtlen);
}
