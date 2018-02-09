//
// Created by andrewmazz on 09.02.18.
//

#include "ft_printf.h"

char ft_separate(t_key *key)
{
	if (key->flag->dpoint)
		return (':');
	else if (key->flag->slash)
		return ('/');
	else
		return ('-');
}

int ft_print_date(t_key *key)
{
	struct tm	*u;
	time_t		timer;
	char *res;
	char *tmp;
	char sep;

	timer = time(NULL);
	u = localtime(&timer);
	res = ft_strnew(10);
	sep = ft_separate(key);
	tmp = ft_itoa(u->tm_year + 1900);
	res = ft_strcat(res, tmp);
	res = ft_addchar(res, sep, 1, 0);
	ft_strdel(&tmp);
	tmp = ft_itoa(u->tm_mon + 1);
	res = (!tmp[1] ? ft_addchar(res, '0', 1, 0) : res);
	res = ft_strcat(res, tmp);
	res = ft_addchar(res, sep, 1, 0);
	ft_strdel(&tmp);
	tmp = ft_itoa(u->tm_mday);
	res = (!tmp[1] ? ft_addchar(res, '0', 1, 0) : res);
	res = ft_strcat(res, tmp);
	ft_strdel(&tmp);
	key->nwres = ft_myrealloc(key->nwres, 10);
	key->nwres = ft_mystrcat(key->nwres, res);
	ft_strdel(&res);
	return (10);
}
