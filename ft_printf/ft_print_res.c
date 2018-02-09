/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:06:40 by amazurok          #+#    #+#             */
/*   Updated: 2018/02/02 17:16:21 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_mod_key(t_key *key)
{
	key->precision = !ft_srchinstr("idDuUoOxXpfsSb", key->sym) ? -1 : \
		key->precision;
	if (key->res)
	{
		key->flag->hash = ft_srchinstr("xXb", key->sym) && key->res[0] == \
			'0' ? 0 : key->flag->hash;
		key->flag->hash = ft_srchinstr("oO", key->sym) && key->res[0] == \
			'0' && key->precision ? 0 : key->flag->hash;
		key->flag->space = (key->flag->plus || key->res[0] == '-' || \
			ft_srchinstr("poOuUxXb", key->sym) ? 0 : key->flag->space);
	}
	key->res = (!key->res && key->precision) ? "(null)" : key->res;
	key->flag->zero = key->precision >= 0 && !ft_srchinstr("sS", key->sym) ? 0 \
		: key->flag->zero;
	key->flag->plus = (ft_srchinstr("poOuUxXb", key->sym)) ? 0 : key->flag->plus;
	key->flag->hash = key->sym == 'p' ? 1 : key->flag->hash;
	key->flag->hash = ft_srchinstr("poOuUxXb", key->sym) ? key->flag->hash : 0;
	key->res = key->sym == 'X' ? ft_struper(key->res) : key->res;
	key->lenr = key->res ? (int)ft_strlen(key->res) : 0;
}

int			ft_print_res(t_key *key, va_list args)
{
	int size;

	if (ft_srchinstr("UDO", key->sym))
		key->modtype->l = 1;
	ft_process_args(key, args);
	ft_mod_key(key);
	if (ft_srchinstr("idDuUoOxXpb", key->sym))
	{
		size = (ft_print_dig(key));
		ft_strdel(&key->res);
	}
	else if ((key->sym == 's' && !key->modtype->l))
		size = (ft_print_str(key));
	else if ((ft_srchinstr("CS", key->sym) || (ft_srchinstr("cs", key->sym)\
		&& key->modtype->l)))
		size = ft_print_unic(key);
	else if (key->sym == 'f' || key->sym == 'F')
	{
		size = ft_print_float(key);
		ft_strdel(&key->res);
	}
	else if (key->sym == 'k')
		size = ft_print_date(key);
	else
		size = (ft_print_char(key));
	return (size);
}
