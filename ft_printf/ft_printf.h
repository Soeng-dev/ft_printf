/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 20:06:16 by soekim            #+#    #+#             */
/*   Updated: 2021/02/22 17:39:29 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define FALSE 0
# define TRUE 1
# define RIGHT 0
# define LEFT 1
# define UNSET -1
# define HH -2
# define H -1
# define L 1
# define LL 2

struct				s_tag
{
	int		aligned;
	int		zero_flag;
	int		precision;
	int		width;
	int		memlen;
	int		sign_flag;
	int		prefix;
};
typedef struct s_tag	t_tag;
int					ftmax(int a, int b);
int					ftmin(int a, int b);
int					prt_int(va_list param, t_tag tag);
int					prt_uint(va_list param, t_tag tag);
int					prt_str(va_list param, t_tag tag);
int					prt_char(va_list param, t_tag tag);
int					prt_hexa(va_list param, t_tag tag, int is_capital);
int					prt_ptr(va_list param, t_tag tag);
int					prt_pct(t_tag tag);
int					iter_write(char c, int iter);
void				ft_putuint_fd(unsigned long long n, int fd);
int					ft_putnbr_base(unsigned long long n, char *base,\
									unsigned long long base_size);
unsigned long long	get_uintarg(va_list param, int memlen);
long long int		get_intarg(va_list param, int memlen);
int					ft_printf(const char *format, ...);
int		get_width(const char **spec);
int		get_precision(const char **spec, va_list param);
void	get_widtharg(va_list param, t_tag *tag);
int		get_memlen(const char **spec, int memlen);
void	align_left(t_tag *tag);
#endif
