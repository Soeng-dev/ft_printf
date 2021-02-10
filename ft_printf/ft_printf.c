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

#define TRUE (1)
#define FALSE (0)
#define LL (2)
#define L (1)
#define H (-1)
#define HH (-2)
#define RIGHT (0)
#define LEFT (1)

typedef struct s_tag
{
	int		aligned;
	int		zero_flag;
	long int	precision;
	long int	width;

	aligned = RIGHT;
	precision = 0;
	width = 0;
	zero_flag = FALSE; 
} t_tag;

void	print_digit(long int n, char *base, int base_size)
{
	if (n < base_size)
		write(1, &base[n], 1);
	else
	{
		print_digit(n / (long int)base_size, base, base_size);
		n %= (long int)base_size;
		write(1, &base[n], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_size;
	long int	n;

	n = (long int)nbr;
	while (base[base_size] != '\0')
		base_size++;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	print_digit(n, base, base_size);
}
// make this functions extensible for bonus
int		cvt_spec(const char **spec, va_list param)
{
	int		prtlen;
	t_tag		tag;

	prtlen = 0;
	//-0.*
	while (**(++spec))
	{
		if (ft_isdigit(**spec))
		{
			tag.width = ft_atoi(*spec);
			while (ft_isdigit(++(*spec)));
			--(*spec);
		}
		else if (**spec == '-')
			tag.aligned = LEFT;
		else if (**spec == '0')
			tag.zero_flag = TRUE;
		else if (**spec == '.')
		{
			if (ft_isdigit(*(*spec + 1)))
			{
				tag.precision = ft_atoi(++(*spec));
				while (ft_isdigit(++(*spec)));
				--(*spec);
			}
		}
		else if (**spec == '*')
			tag.width = va_arg(param, int);
		else
			break;//break loop when meet char is not flag)
	}
	//print data with pecified conversion
	//may need to divide into function prt_data
	if (**spec == 'c')
		prtlen = prt_char((char)va_arg(param, int), tag);
	else if (**spec == 's')
		prtlen = prt_str(va_arg(param, char *), tag);
	else if (**spec == 'p')
	{
		//use print_memory
		va_arg
	}
	else if (**spec == 'd' || **spec == 'i')
		prtlen = prt_int(va_arg(param, int), tag);
	else if (**spec == 'u')
		prtlen = prt_uint(va_arg(param, unsigned int), tag);
	else if (**spec == 'x' || **spec == 'X')
		prtlen = prt_uhexa(va_arg(param, unsigned int), tag);
	else
	{
		while (*(--(*spec)) != '%');
		return (0);
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
			prtlen += (print_data(&format, param));
		write(1, format, 1);
		++format;
		++prtlen;
	}
	return (prtlen);
}
