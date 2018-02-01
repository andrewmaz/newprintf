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
		key->nwres = ft_myrealloc(key->nwres, size);
		//ft_putuchar(octet);
		key->nwres[0] = octet;
		res = ft_addchar(res, ' ', w, 1);
		key->nwres = ft_mystrcat(key->nwres, res);
		//write(1, res, size - key->nb);
	}
	else
	{
		res = key->flag->zero ? ft_addchar(res, '0', w, 0) : ft_addchar(res, ' ', w, 0);
		//write(1, res, size - key->nb);
		//ft_putuchar(octet);
		key->nwres = ft_myrealloc(key->nwres, size);
		key->nwres = ft_mystrcat(key->nwres, res);
		key->nwres[size - key->nb] = octet;

	}
	ft_strdel(&res);
	return (size);
}