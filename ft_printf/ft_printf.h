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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define FALSE (0)
# define TRUE (1)
# define RIGHT (0)
# define LEFT (1)
# define UNSET (-1)

# define MAX(A, B) (((A) > (B)) ? (A) : (B))
# define MIN(A, B) (((A) < (B)) ? (A) : (B))

typedef struct s_tag
{
	int		aligned;
	int		zero_flag;
	int		precision;
	int		width;
} t_tag;

int		prt_int(va_list param, t_tag tag);
int		prt_uint(va_list param, t_tag tag);
int		prt_str(va_list param, t_tag tag);
int		prt_char(va_list param, t_tag tag);
int		prt_hexa(va_list param, t_tag tag, int is_capital);
int		prt_ptr(va_list param, t_tag tag);
int		ft_putnbr_base(unsigned long long n, char *base, int base_size);

#endif
