/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:31:30 by amazurok          #+#    #+#             */
/*   Updated: 2018/02/02 17:33:04 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_del_key(t_key *key)
{
	free(key->flag);
	free(key->modtype);

	free(key->nwres);
	free(key);
}

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
		if (w[i] == -1)
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

int			ft_printf(const char *format, ...)
{
	int		size;
	va_list	args;
	t_key	*key;
	wchar_t *wres;
	int i;

	va_start(args, format);
	size = 0;
	i = 0;
	wres = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			key = ft_new_key();
			if (!ft_check_key(key, ++format, args))
				break ;
			size += ft_print_res(key, args);
			i += wstrlen(key->nwres);
			wres = ft_myrealloc(wres, i);
			wres = ft_wtrcat(wres, key->nwres);
			format += ft_skip_key(key, format);
		}
		else
		{
			wres = ft_myrealloc(wres, i + 1);
			wres[i++] = *format;
			size++;
			format++;
		}
	}
	if (MB_CUR_MAX <= 1)
	{
		char *sss = ft_strnew(size);
		sss = ft_w2s(sss, wres);
		write(1, sss, size);
		ft_strdel(&sss);
	}
	else
		ft_putustr(wres);
	ft_wstrdel(&wres);
	va_end(args);
	return (size);
}
