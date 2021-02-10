/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:03:15 by soekim            #+#    #+#             */
/*   Updated: 2020/08/10 21:50:22 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define LINE_SIZE 16

void	print_str_hex(unsigned char *str, unsigned int size);

void	print_addr_hex(void *addr);

void	print_printable_str(void *str, unsigned int size);

void	*ft_print_memory(void *addr, unsigned int size)
{
	if (size <= 0)
		return (NULL);
	else if (0 < size && size < LINE_SIZE)
	{
		print_addr_hex(addr);
		print_str_hex(addr, size);
		print_printable_str(addr, size);
		write(1, "\n", 1);
		return (NULL);
	}
	else
	{
		print_addr_hex(addr);
		print_str_hex(addr, LINE_SIZE);
		print_printable_str(addr, LINE_SIZE);
		write(1, "\n", 1);
		ft_print_memory(addr + 16, size - 16);
	}
	return (addr);
}

void	print_str_hex(unsigned char *str, unsigned int size)
{
	unsigned char	a[3];
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		a[0] = str[i] / 16;
		a[1] = str[i] % 16;
		a[0] = (a[0] < 10) ? (a[0] + '0') : (a[0] - 10 + 'a');
		a[1] = (a[1] < 10) ? (a[1] + '0') : (a[1] - 10 + 'a');
		write(1, a, 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	if (size < LINE_SIZE)
	{
		if ((size % 2) == 1)
			write(1, "  ", 2);
		else
			write(1, "    ", 4);
	}
}

void	print_addr_hex(void *addr)
{
	long long int	addr_int;
	unsigned char	address_list[17];
	unsigned char	digit;
	int				idx;

	idx = 15;
	addr_int = (long long int)addr;
	while (addr_int > 0)
	{
		digit = (unsigned char)(addr_int % 16);
		digit = (0 <= digit && digit <= 9) ? digit + '0' : digit - 10 + 'a';
		address_list[idx] = digit;
		addr_int /= 16;
		idx--;
	}
	while (idx >= 0)
	{
		address_list[idx] = '0';
		idx--;
	}
	write(1, address_list, 16);
	write(1, ": ", 2);
}

void	print_printable_str(void *str, unsigned int size)
{
	unsigned int	i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)str;
	while (i < size)
	{
		if (32 <= temp[i] && temp[i] <= 126)
			write(1, &temp[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}
