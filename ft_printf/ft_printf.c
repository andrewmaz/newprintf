//
// Created by andrewmazz on 28.01.18.
//

#include "ft_printf.h"

static int	ft_skip_key(t_key *key, const char *format)
{
	int i;

	i = 0;
	while (format[i] != key->sym)
		i++;
	i++;
	return (i);
}

int			ft_printf(const char *format, ...)
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
			if (!ft_check_key(key, ++format, args))
				return (size);
			size += ft_print_res(key, args);
			format += ft_skip_key(key, format);
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
