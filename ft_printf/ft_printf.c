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
		if (w[i] == 127)
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

wchar_t *ft_setcolor(const char **format, wchar_t *wres, const char *frm, t_res *tres)
{
	const char *tmp;
	char *res;
	wchar_t *qres;
	int i;

	i = 0;
	tmp = frm;
	res = ft_strnew(10);
	tmp++;
	while (*tmp != '}')
		res[i++] = *tmp++;
	tmp++;
	if (!ft_strcmp(res, "red"))
	{
		tres->i += 5;
		tres->col += 5;
		qres = ft_myrealloc(wres, tres->i);
		qres = ft_mystrcat(qres, "\033[31m");
	}
	else if (!ft_strcmp(res, "blue"))
	{
		tres->i += 5;
		tres->col += 5;
		qres = ft_myrealloc(wres, tres->i);
		qres = ft_mystrcat(qres, "\033[34m");
	}
	else if (!ft_strcmp(res, "eoc"))
	{
		tres->i += 4;
		tres->col += 4;
		qres = ft_myrealloc(wres, tres->i);
		qres = ft_mystrcat(qres, "\033[0m");
	}
	*format = tmp;
	ft_strdel(&res);
	return (qres);

}

wchar_t *ft_qwe(const char *format, va_list args, t_res *tres)
{
	t_key	*key;
	wchar_t *wres;

	wres = NULL;
	while (*format)
		if (*format == '%')
		{
			key = ft_new_key();
			if (!ft_check_key(key, ++format, args))
				break ;
			tres->size += ft_print_res(key, args);
			tres->i += wstrlen(key->nwres);
			wres = ft_myrealloc(wres, tres->i);
			wres = ft_wtrcat(wres, key->nwres);
			format += ft_skip_key(key, format);
		}
		else if (*format == '{')
			wres = ft_setcolor(&format, wres, format, tres);
		else
		{
			wres = ft_myrealloc(wres, tres->i + 1);
			wres[tres->i++] = *format++;
			tres->size++;
		}
	return wres;
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	wchar_t *wres;
	char	*res;
	t_res	*tres;

	tres = (t_res*)malloc(sizeof(t_res));
	tres->i = 0;
	tres->size = 0;
	tres->col = 0;
	va_start(args, format);
	wres = ft_qwe(format, args, tres);
	if (MB_CUR_MAX <= 1)
	{
		tres->size = tres->i;
		res = ft_strnew(tres->i);
		res = ft_w2s(res, wres);
		write(1, res, tres->i);
		ft_strdel(&res);
	}
	else
		ft_putustr(wres);
	ft_wstrdel(&wres);
	va_end(args);
	return (tres->size);
}
