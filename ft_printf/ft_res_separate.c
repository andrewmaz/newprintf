/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_res_separate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:25:55 by amazurok          #+#    #+#             */
/*   Updated: 2018/02/13 17:27:39 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_revers(char **nstr)
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

static char	*ft_rewritewisep(char *res, char sym)
{
	int		i;
	int		k;
	int		s;
	char	*nres;

	nres = NULL;
	k = 0;
	i = 0;
	s = 0;
	while (res[i])
	{
		nres = ft_realloc(nres, k + 1);
		if (!(s % 3) && s > 0 && sym && res[i] != '-')
		{
			nres[k++] = sym;
			s = 0;
		}
		else
		{
			nres[k++] = res[i++];
			s++;
		}
	}
	return (nres);
}

void		ft_addsep(char **res)
{
	struct lconv *lc;

	lc = localeconv();
	ft_revers(res);
	*res = ft_rewritewisep(*res, *lc->thousands_sep);
	ft_revers(res);
}
