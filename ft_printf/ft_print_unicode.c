/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unicode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:21:27 by amazurok          #+#    #+#             */
/*   Updated: 2018/02/02 17:24:03 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_mod_u(t_key *key, wchar_t c)
{
	char *tmp;

	tmp = ft_size2a_base(c, 2);
	key->lenr = ft_strlen(tmp);
	if (key->lenr <= 7)
		key->nb = 1;
	else if (key->lenr <= 11)
		key->nb = 2;
	else if (key->lenr <= 16)
		key->nb = 3;
	else
		key->nb = 4;
	ft_strdel(&tmp);
}

int			ft_myputustr(t_key *key, int s)
{
	int i;
	int size;

	size = 0;
	i = 0;
	while (key->wres[i])
	{
		ft_mod_u(key, key->wres[i]);
		if (key->precision > 0 && (size + key->nb) <= key->precision)
			key->nwres[s++] = key->wres[i++];
		else if (key->precision < 0)
			key->nwres[s++] = key->wres[i++];
		else
			return (i);
		size += key->nb;
	}
	return (i);
}

size_t		ft_ustrlen(t_key *key)
{
	size_t i;
	size_t size;

	i = 0;
	size = 0;
	while (key->wres[i] && ((key->precision > 0 && (int)(size + key->nb) <= \
		key->precision) || key->precision < 0))
	{
		ft_mod_u(key, key->wres[i]);
		size += key->nb;
		i++;
	}
	return (size);
}

int			ft_print_ustr(t_key *key)
{
	int		size;
	int		w;
	char	*res;

	key->lenr = key->wres ? ft_ustrlen(key) : 0;
	w = key->width - key->lenr;
	size = key->lenr + (w > 0 ? w : 0);
	res = ft_strnew(size);
	key->nwres = ft_myrealloc(key->nwres, size);
	if (key->flag->minus)
	{
		key->lenr = ft_myputustr(key, 0);
		ft_addchar(res, ' ', w, 0);
		key->nwres = ft_mystrcat(key->nwres, res);
	}
	else
	{
		res = key->flag->zero ? ft_addchar(res, '0', w, 0) : \
			ft_addchar(res, ' ', w, 0);
		key->nwres = ft_mystrcat(key->nwres, res);
		key->lenr = ft_myputustr(key, (w > 0 ? w : 0));
	}
	ft_strdel(&res);
	return (size);
}

int			ft_print_unic(t_key *key)
{
	unsigned int octet;

	if (key->sym == 'C' || (key->sym == 'c' && key->modtype->l))
	{
		ft_mod_u(key, key->wr);
		octet = key->wr;
		return (ft_print_uchar(key, octet));
	}
	if (key->sym == 'S' || (key->sym == 's' && key->modtype->l))
	{
		if (!key->wres)
			return (ft_print_str(key));
		return (ft_print_ustr(key));
	}
	return (0);
}
