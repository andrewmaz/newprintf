//
// Created by andrewmazz on 28.01.18.
//

#include "ft_printf.h"

static void ft_del_key(t_key *key)
{
	free(key->flag);
	free(key->modtype);
	ft_memdel(&key->nwres);
	free(key);
}

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
	wchar_t *wres;

	va_start(args, format);
	size = 0;
	wres = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			key = ft_new_key();
			if (!ft_check_key(key, ++format, args))
				return (size);
			size += ft_print_res(key, args);
			wres = ft_myrealloc(wres, size);
			wres = ft_wtrcat(wres, key->nwres);
			format += ft_skip_key(key, format);
		}
		else
		{
			wres = ft_myrealloc(wres, size + 1);
			wres[size] = *format;
			//write(1, &*format, 1);
			size++;
			format++;
		}
	}
	ft_putnustr(wres, size);
	ft_memdel(&wres);
	va_end(args);
	return (size);
}
