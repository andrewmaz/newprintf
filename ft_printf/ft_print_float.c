/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 19:34:34 by amazurok          #+#    #+#             */
/*   Updated: 2018/02/04 19:35:48 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_float(t_key *key)
{
	int		w;
	char	*res;
	int		size;

	w = key->width - key->lenr;
	size = key->lenr + (w > 0 ? w : 0);
	res = ft_strnew(size);
	if (key->flag->minus)
	{
		res = ft_strcat(res, key->res);
		res = ft_addchar(res, ' ', w, 0);
	}
	else
	{
		res = key->flag->zero ? ft_addchar(res, '0', w, 0) : \
			ft_addchar(res, ' ', w, 0);
		res = ft_strcat(res, key->res);
	}
	key->nwres = ft_myrealloc(key->nwres, size);
	key->nwres = ft_mystrcat(key->nwres, res);
	ft_strdel(&res);
	return (size);
}
