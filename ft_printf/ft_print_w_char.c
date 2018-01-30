//
// Created by Andrii MAZUROK on 1/30/18.
//

#include "ft_printf.h"

int ft_print_uchar(t_key *key, unsigned int octet)
{
	int size;
	int w;
	char *res;

	w = key->width - key->nb;
	size = w > 0 ? key->width : key->nb;
	res = ft_strnew(size);
	if (key->flag->minus)
	{
		ft_putuchar(key->nb, octet);
		res = ft_addchar(res, ' ', w);
		write(1, res, size - key->nb);
	}
	else
	{
		res = key->flag->zero ? ft_addchar(res, '0', w) : ft_addchar(res, ' ', w);
		write(1, res, size - key->nb);
		ft_putuchar(key->nb, octet);
	}
	ft_strdel(&res);
	return (size);
}