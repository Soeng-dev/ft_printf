/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim </var/mail/soekim>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:00:51 by soekim            #+#    #+#             */
/*   Updated: 2021/02/19 19:00:58 by soekim           ###   ########.fr       */
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
# define HH (-2)
# define H (-1)
# define L (1)
# define LL (2)

# define MAX(A, B) (((A) > (B)) ? (A) : (B))
# define MIN(A, B) (((A) < (B)) ? (A) : (B))

typedef struct s_tag
{
	int		aligned;
	int		zero_flag;
	int		precision;
	int		width;
	//bonus
	int		memlen;
} t_tag;

int		prt_int(va_list param, t_tag tag);
int		prt_uint(va_list param, t_tag tag);
int		prt_str(va_list param, t_tag tag);
int		prt_char(va_list param, t_tag tag);
int		prt_hexa(va_list param, t_tag tag, int is_capital);
int		prt_ptr(va_list param, t_tag tag);
int		prt_pct(t_tag tag);
void	ft_putuint_fd(unsigned long long n, int fd);
int		ft_putnbr_base(unsigned long long n, char *base, int base_size);
int		ft_printf(const char *format, ...);
#endif
