
#include "ft_printf.h"

unsigned long long	get_uintarg(va_list param, int memlen)
{
	int i;

	i = 0;
	if (memlen == 0)
		i = (unsigned long long)va_arg(param, unsigned int);
	else if (memlen == L)
		i = (unsigned long long)va_arg(param, unsigned long);
	else if (memlen == LL)
		i = (unsigned long long)va_arg(param, unsigned long long);
	else if (memlen == H)
		i = (unsigned long long)(va_arg(param, unsigned int) & (0xffff));
	else if (memlen == HH)
		i = (unsigned long long)(va_arg(param, unsigned int) & (0xff));
	return (i);
}
