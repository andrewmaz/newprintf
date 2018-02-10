/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:38:38 by amazurok          #+#    #+#             */
/*   Updated: 2018/02/04 19:41:12 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_signed(t_key *key, va_list args, int base)
{
	if (key->modtype->z)
		key->res = ft_ssize2a_base((ssize_t)va_arg(args, ssize_t), base);
	else if (key->modtype->j)
		key->res = ft_ssize2a_base((intmax_t)va_arg(args, intmax_t), base);
	else if (key->modtype->ll)
		key->res = ft_ssize2a_base((t_lli)va_arg(args, t_lli), base);
	else if (key->modtype->l)
		key->res = ft_ssize2a_base(va_arg(args, long int), base);
	else if (key->modtype->h)
		key->res = ft_ssize2a_base((short int)va_arg(args, int), base);
	else if (key->modtype->hh)
		key->res = ft_ssize2a_base((char)va_arg(args, int), base);
	else
		key->res = ft_ssize2a_base(va_arg(args, int), base);
}

static void	ft_unsigned(t_key *key, va_list args, int base)
{
	if (key->modtype->z)
		key->res = ft_size2a_base((size_t)va_arg(args, size_t), base);
	else if (key->modtype->j)
		key->res = ft_size2a_base((t_uinmax)va_arg(args, t_uinmax), base);
	else if (key->modtype->ll)
		key->res = ft_size2a_base((t_ulli)va_arg(args, t_ulli), base);
	else if (key->modtype->l)
		key->res = ft_size2a_base((t_uli)va_arg(args, t_uli), base);
	else if (key->modtype->h)
		key->res = ft_size2a_base((t_usi)va_arg(args, int), base);
	else if (key->modtype->hh)
		key->res = ft_size2a_base((unsigned char)va_arg(args, int), base);
	else
		key->res = ft_size2a_base((unsigned int)va_arg(args, int), base);
}

void		ft_float2str(t_key *key, va_list args)
{
	char		*aft_point;
	char		*bef_point;
	long double	tmp;
	int			i;

	i = 1;
	tmp = va_arg(args, double);
	bef_point = ft_ssize2a_base((ssize_t)tmp, 10);
	aft_point = ft_strdup(".");
	tmp = tmp < 0 ? -tmp : tmp;
	tmp = tmp - (int)tmp;
	if (key->precision == -1)
		key->precision = 6;
	while (i < key->precision + 1)
	{
		tmp = tmp * 10;
		aft_point = ft_realloc(aft_point, i + 1);
		aft_point[i++] = (int)tmp + '0';
		tmp = tmp - (int)tmp;
	}
	key->res = ft_strjoin(bef_point, aft_point);
	ft_strdel(&bef_point);
	ft_strdel(&aft_point);
}

void		ft_process_dig(t_key *key, va_list args)
{
	if (key->sym == 'd' || key->sym == 'i' || key->sym == 'D')
		ft_signed(key, args, 10);
	else if (key->sym == 'u' || key->sym == 'U')
		ft_unsigned(key, args, 10);
	else if (key->sym == 'o' || key->sym == 'O')
		ft_unsigned(key, args, 8);
	else if (key->sym == 'x' || key->sym == 'X')
		ft_unsigned(key, args, 16);
	else if (key->sym == 'p')
		key->res = ft_size2a_base((size_t)va_arg(args, void*), 16);
	else if (key->sym == 'f' || key->sym == 'F')
		ft_float2str(key, args);
	else if (key->sym == 'b')
		ft_unsigned(key, args, 2);
}

void		ft_setn(int *p, t_res *tres)
{
	int *size;

	size = p;
	*size = tres->size;
}

void		ft_process_args(t_key *key, va_list args, t_res *tres)
{
	if (ft_srchinstr("idDuUoOxXpfFb", key->sym))
		ft_process_dig(key, args);
	else if (key->sym == 's')
		if (key->modtype->l)
			key->wres = va_arg(args, wchar_t*);
		else
			key->res = va_arg(args, char*);
	else if (key->sym == 'c')
		if (key->modtype->l)
			key->wr = va_arg(args, wchar_t);
		else
			key->r = (char)va_arg(args, int);
	else if (key->sym == 'C')
		key->wr = va_arg(args, wchar_t);
	else if (key->sym == 'S')
		key->wres = va_arg(args, wchar_t*);
	else if (key->sym == 'n')
		ft_setn(va_arg(args, int*), tres);
	else
		key->r = key->sym;
}
