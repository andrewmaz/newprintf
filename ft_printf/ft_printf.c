/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:31:30 by amazurok          #+#    #+#             */
/*   Updated: 2018/02/04 19:39:15 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_skip_key(t_key *key, const char *format)
{
	int i;

	i = 0;
	while (format[i] != key->sym)
		i++;
	i++;
	ft_del_key(key);
	return (i);
}

char		*ft_w2s(char *str, wchar_t *w)
{
	int i;

	i = 0;
	while (w && w[i])
	{
		if (w[i] == 12)
			str[i] = 0;
		else
			str[i] = (char)w[i];
		i++;
	}
	return (str);
}

int			wstrlen(wchar_t *wstr)
{
	int i;

	i = 0;
	while (wstr && wstr[i])
		i++;
	return (i);
}

int			ft_whi(const char *format, va_list args, wchar_t **qres, int size)
{
	t_key	*key;
	int		i;
	wchar_t	*wres;

	wres = NULL;
	while (*format)
		if (*format == '%')
		{
			key = ft_new_key();
			if (!ft_check_key(key, ++format, args))
				break ;
			size += ft_print_res(key, args);
			i = !wres ? wstrlen(key->nwres) : i + wstrlen(key->nwres);
			wres = ft_myrealloc(wres, i);
			wres = ft_wtrcat(wres, key->nwres);
			format += ft_skip_key(key, format);
		}
		else
		{
			wres = ft_myrealloc(wres, i + 1);
			wres[i++] = *format++;
			size++;
		}
	*qres = wres;
	return (size);
}

int			ft_printf(const char *format, ...)
{
	int		size;
	va_list	args;
	wchar_t *wres;
	char	*res;

	va_start(args, format);
	size = 0;
	size = ft_whi(format, args, &wres, size);
	if (MB_CUR_MAX <= 1)
	{
		size = wstrlen(wres);
		res = ft_strnew(size);
		res = ft_w2s(res, wres);
		write(1, res, size);
		ft_strdel(&res);
	}
	else
		ft_putustr(wres);
	ft_wstrdel(&wres);
	va_end(args);
	return (size);
}
