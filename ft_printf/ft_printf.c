/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim </var/mail/soekim>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:00:51 by soekim            #+#    #+#             */
/*   Updated: 2021/02/09 17:35:11 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

#define TRUE 1
#define FALSE 0
/*
int		is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'i' 
		|| c == 'u' || c == 'x' || c == 'X')
		return (CONVERSION);
	else if (c == '-' || c == '0' || c == '.' || c == '*')
		return (FLAG);
	else
		return (NON);
}*/
// make this functions extensible for bonus
int		print_data(const char **fmtspec, va_list param)
{
	int		prtlen;
	char	is_converted;

	prtlen = 0;
	is_converted = FALSE;
	while (!is_converted)
	{
		if (**fmtspec == c)
		{
			ft_putchar(
		}
	}
	if (!is_specified)
	return (prtlen);
}

int		ft_printf(const char *format, ...)
{
	int		prtlen;
	va_list	param;

	prtlen = 0;
	va_start(param, ft_strlen(format));
	while (*format)
	{
		while (*format && *format != '%')
		{
			write(1, format, 1);
			++format;
			++prtlen;
		}
		if (*format == '%')
			print_data(&format, param);

	}
}
