//
// Created by Andrii MAZUROK on 2/11/18.
//

#include "ft_printf.h"

void ft_revers(char **nstr)
{
	char	*res;
	char	*str;
	int		len;

	str = *nstr;
	len = ft_strlen(str);
	res = ft_strnew(len);
	while (len)
	{
		res[--len] = *str++;
	}
	ft_strdel(nstr);
	*nstr = res;
}

char *ft_rewritewisep(t_key *key, char sym)
{
	int i;
	int k;
	int s;
	char *res;

	res = NULL;
	k = 0;
	i = 0;
	s = 0;
	while (key->res[i])
	{
		res = ft_realloc(res, k + 1);
		if (!(s % 3) && s > 0 && sym)
		{
			res[k++] = sym;
			s = 0;
		}
		else
		{
			res[k++] = key->res[i++];
			s++;
		}
	}
	return (res);
}

void ft_addsep(t_key *key)
{
	char *res;
	struct lconv *lc;

	lc = localeconv();
	ft_revers(&key->res);
	res = ft_rewritewisep(key, *lc->thousands_sep);
	ft_revers(&res);
	ft_strdel(&key->res);
	key->res = res;
}