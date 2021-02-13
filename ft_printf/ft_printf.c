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
#include <limits.h>
#include "../libft/libft.h"

#define TRUE (1)
#define FALSE (0)
#define LL (2)
#define L (1)
#define H (-1)
#define HH (-2)
#define RIGHT (0)
#define LEFT (1)

#define MAX((A), (B)) (((A) > (B)) ? (A) : (B))

typedef struct s_tag
{
	int		aligned;
	int		zero_flag;
	long int	precision;
	long int	width;
} t_tag;
// make this functions extensible for bonus
int		cvt_spec(const char **spec, va_list param)
{
	int		prtlen;
	t_tag		tag;

	prtlen = 0;
	ft_memset(tag, 0, sizeof(tag));
	//-0.*
	//consider flag priority here
	while (**(++spec))
	{
		if (ft_isdigit(**spec))
		{
			tag.width = ft_atoi(*spec);
			while (ft_isdigit(++(*spec)));
			--(*spec);
		}
		else if (**spec == '-')
		{
			tag.aligned = LEFT;
			tag.zero_flag = FALSE;
		}
		else if (**spec == '0')
			tag.zero_flag = TRUE;
		else if (**spec == '.')
		{
			if (ft_isdigit(*(*spec + 1)))
			{
				//fix atoi to get number right away (delete space and sign manage
				tag.precision = ft_atoi(++(*spec));
				while (ft_isdigit(++(*spec)));
				--(*spec);
				tag.zero_flag = FALSE; 
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
		prtlen = prt_char(param, tag);
	else if (**spec == 's')
		prtlen = prt_str(param, tag);
	else if (**spec == 'p')
	{
		//use print_memory
		va_arg
	}
	else if (**spec == 'd' || **spec == 'i')
		prtlen = prt_int(param, tag);
	else if (**spec == 'u')
		prtlen = prt_uint(param, tag);
	else if (**spec == 'x' || **spec == 'X')
		prtlen = prt_uhexa(param, tag);
	else
	{
		while (*(--(*spec)) != '%');
		return (0);
	}
	return (prtlen);
}
//get length of integer consider tag
int get_numlen(int digitlen, int sign, t_tag tag)
{
	int	numlen;

	numlen = digitlen;
	numlen = MAX(tag.width, numlen);
	numlen = MAX(tag.precision, numlen);
	if (sign < 0)
		++numlen;
	return (numlen);
}

int		prt_int(va_list param, t_tag tag)
{
	long long int	i;
	long long int	temp;
	int		prtlen;
	int		numlen;
	int		digitlen;

	i = (long long int)va_arg(param, int);
	temp = (long long int)((i < 0) ? -i : i);
	digitlen = 1;
	while ((temp /= 10) > 0)
		++digitlen;
	numlen = get_numlen(digitlen, (i >= 0) ? (1) : (-1), tag);
	prtlen = 0;
	//from here print starts
	//first condition states print before significant digit numbers 
	if (tag.aligned == RIGHT)
	{
		if (tag.zero_flag == TRUE)
		{
			if (i < 0)
 	 		{
  				write(1, "-", 1);
				++prtlen;
	  		}
  			while (prtlen < tag.width - digitlen)
  			{
  				write(1, "0", 1);
  				++prtlen;
  			}
  		}
  		else
  		{
  			while (prtlen < tag.width - numlen)
  			{
  				write(1, " ", 1);
  				++prtlen;
  			}
  		}
	}
	if (i < 0 && tag.zero_flag == FALSE)
	{
		write(1, "-", 1);
		++prtlen;
	}
	//prints significant digit numbers
	temp = -1;
	while (++temp < tag.precision - digitlen)
	{
		write(1, "0", 1);
		++prtlen;
	}
	temp = (long long int)((i < 0) ? -i : i);
	ft_putnbr_fd(temp, 1);
	prtlen += digitlen;
	if (tag.aligned == LEFT)
	{
		while (prtlen < tag.width)
		{
			write(1, " ", 1);
			++prtlen;
		}
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
	va_end(param);
	return (prtlen);
}
