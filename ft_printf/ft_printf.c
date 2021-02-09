/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim </var/mail/soekim>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:00:51 by soekim            #+#    #+#             */
/*   Updated: 2021/02/09 16:19:23 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

// make this functions extensible for bonus
int print_data(const char **fmtspec)
{
	int 




int ft_printf(const char *format, ...)
{
	int		outputlen;
	va_list	param;

	outputlen = 0;
	va_start(param, ft_strlen(format));
	while (*format)
	{
		while (*format && *format != '%')
		{
			write(1, format, 1);
			++format;
			++outputlen;
		}
		if (*format == '%')
			print_data(&format);

	}
}
