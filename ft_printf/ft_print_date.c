/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_date.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:57:06 by amazurok          #+#    #+#             */
/*   Updated: 2018/02/13 16:57:15 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_newsize(t_key *key)
{
	int size;

	size = 0;
	if (key->date->y)
		size += 10;
	if (key->date->t)
		size += 9;
	if (!key->date->y && !key->date->t)
		size += 19;
	return (size);
}

static char	*ft_date(char *res, struct tm *u)
{
	char *tmp;

	tmp = ft_itoa(u->tm_year + 1900);
	res = ft_strcat(res, tmp);
	res = ft_addchar(res, '-', 1, 0);
	ft_strdel(&tmp);
	tmp = ft_itoa(u->tm_mon + 1);
	res = (!tmp[1] ? ft_addchar(res, '0', 1, 0) : res);
	res = ft_strcat(res, tmp);
	res = ft_addchar(res, '-', 1, 0);
	ft_strdel(&tmp);
	tmp = ft_itoa(u->tm_mday);
	res = (!tmp[1] ? ft_addchar(res, '0', 1, 0) : res);
	res = ft_strcat(res, tmp);
	ft_strdel(&tmp);
	return (res);
}

static char	*ft_hour(char *res, struct tm *u)
{
	char *tmp;

	res = res[0] ? ft_addchar(res, 'T', 1, 0) : res;
	tmp = ft_itoa(u->tm_hour);
	res = ft_strcat(res, tmp);
	res = ft_addchar(res, ':', 1, 0);
	ft_strdel(&tmp);
	tmp = ft_itoa(u->tm_min + 1);
	res = (!tmp[1] ? ft_addchar(res, '0', 1, 0) : res);
	res = ft_strcat(res, tmp);
	res = ft_addchar(res, ':', 1, 0);
	ft_strdel(&tmp);
	tmp = ft_itoa(u->tm_sec);
	res = (!tmp[1] ? ft_addchar(res, '0', 1, 0) : res);
	res = ft_strcat(res, tmp);
	ft_strdel(&tmp);
	return (res);
}

int			ft_print_date(t_key *key)
{
	struct tm	*u;
	time_t		timer;
	char		*res;
	int			size;

	timer = time(NULL);
	u = localtime(&timer);
	size = ft_newsize(key);
	res = ft_strnew(size);
	if (size == 10 || size == 19)
		res = ft_date(res, u);
	if (size == 9 || size == 19)
		res = ft_hour(res, u);
	key->nwres = ft_myrealloc(key->nwres, size);
	key->nwres = ft_mystrcat(key->nwres, res);
	ft_strdel(&res);
	return (size);
}
