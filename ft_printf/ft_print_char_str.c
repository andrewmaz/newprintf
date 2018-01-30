//
// Created by andrewmazz on 29.01.18.
//

#include "ft_printf.h"

int ft_print_char(t_key *key)
{
	int size;
	int w;
	char *res;

	w = key->width - 1;
	size = w > 0 ? key->width : 1;
	res = ft_strnew(size);
	if (key->flag->minus)
	{
		write(1, &key->r, 1);
		res = ft_addchar(res, ' ', w);
		write(1, res, size - 1);

	}
	else
	{
		res = key->flag->zero ? ft_addchar(res, '0', w) : ft_addchar(res, ' ', w);
		res[size - 1] = key->r;
		write(1, res, size);
	}
	ft_strdel(&res);
	return (size);
}

int ft_print_str(t_key *key)
{
	int size;
	int w;
	int p;
	char *res;

	p = key->precision;
	key->lenr = p < key->lenr && p >= 0 ? p : key->lenr;
	w = key->width - key->lenr;
	size = key->lenr + (w > 0 ? w : 0);
	res = ft_strnew(size);
	if (key->flag->minus)
	{
		res = key->res ? ft_strncat(res, key->res, key->lenr) : res;
		res = ft_addchar(res, ' ', w);
	}
	else
	{
		res = key->flag->zero ? ft_addchar(res, '0', w) : \
			ft_addchar(res, ' ', w);
		res = key->res ? ft_strncat(res, key->res, key->lenr) : res;
	}
	write(1, res, size);
	ft_strdel(&res);
	return (size);
}