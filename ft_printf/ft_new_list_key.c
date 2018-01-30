/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_list_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:22:06 by amazurok          #+#    #+#             */
/*   Updated: 2018/01/23 12:22:08 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_key	*ft_new_key(void)
{
	t_key *key;

	key = (t_key *)malloc(sizeof(t_key));
	key->flag = (t_flag *)malloc(sizeof(t_flag));
	key->flag->space = 0;
	key->flag->plus = 0;
	key->flag->minus = 0;
	key->flag->zero = 0;
	key->flag->hash = 0;
	key->width = 0;
	key->precision = -1;
	key->modtype = (t_modtype *)malloc(sizeof(t_modtype));
	key->modtype->h = 0;
	key->modtype->hh = 0;
	key->modtype->l = 0;
	key->modtype->ll = 0;
	key->modtype->j = 0;
	key->modtype->z = 0;
	key->sym = 0;
	key->r = 0;
	key->lenr = 0;
	key->res = NULL;
	key->wres = NULL;
	return (key);
}
