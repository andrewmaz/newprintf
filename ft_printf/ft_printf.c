//
// Created by andrewmazz on 28.01.18.
//

#include "ft_printf.h"



int		ft_printf(const char *format, ...)
{
	int		size;
	va_list	args;
	t_key	*key;

	va_start(args, format);
	size = 0;
	while (*format)
	{
		if (*format == '%')
		{
			key = ft_new_key();
			if (!ft_check_key(key, ++format))
				return (size);
			size += ft_print_res(key, args);
			while (*format != key->sym)
				format++;
			format++;
		}
		else
		{
			write(1, &*format, 1);
			size++;
			format++;
		}
	}
	va_end(args);
	return (size);
}
