//
// Created by andrewmazz on 28.01.18.
//

#include "ft_printf.h"

static void	ft_mod_key(t_key *key)
{
	if ((key->sym == 'S' || (key->sym == 's' && key->modtype->l)) && MB_CUR_MAX <= 1)
		key->res = (char*)key->wres;
	if ((key->sym == 'C' || (key->sym == 'c' && key->modtype->l)) && MB_CUR_MAX <= 1)
		key->r = (char)key->wr;
	key->precision = !ft_searcINline("idDuUoOxXpfsS", key->sym) ? -1 : key->precision;
	if (key->res)
	{
		key->flag->hash = ft_searcINline("xX", key->sym) && key->res[0] == \
        	'0' ? 0 : key->flag->hash;
		key->flag->hash = ft_searcINline("oO", key->sym) && key->res[0] == \
        	'0' && key->precision ? 0 : key->flag->hash;
		key->flag->space = (key->flag->plus || key->res[0] == '-' || \
        ft_searcINline("poOuUxX", key->sym) ? 0 : key->flag->space);
	}
	if (!key->res && key->precision)
		key->res = "(null)";
	key->flag->zero = key->precision >= 0 && !ft_searcINline("sS", key->sym) ? 0 : key->flag->zero;
	key->flag->plus = (ft_searcINline("poOuUxX", key->sym)) ? 0 : key->flag->plus;
	key->flag->hash = key->sym == 'p' ? 1 : key->flag->hash;
	key->flag->hash = ft_searcINline("poOuUxX", key->sym) ? key->flag->hash : 0;
	key->res = key->sym == 'X' ? ft_struper(key->res) : key->res;
	key->lenr = key->res ? (int)ft_strlen(key->res) : 0;
}

static void ft_del_key(t_key *key)
{
	free(key->flag);
	free(key->modtype);
	free(key);
}

int ft_print_float(t_key *key)
{
	///do
	write(1, key->res, key->lenr);
	return (key->lenr);
}

int ft_print_res(t_key *key, va_list args)
{
	int size;

	if (ft_searcINline("UDO", key->sym))
		key->modtype->l = 1;
	ft_process_args(key, args);
	ft_mod_key(key);
	if (ft_searcINline("idDuUoOxXp", key->sym))
	{
		size = (ft_print_dig(key));
		ft_strdel(&key->res);
	}
	else if ((key->sym == 's' && !key->modtype->l) || (key->sym == 'S' && MB_CUR_MAX <= 1))
	{
		size = (ft_print_str(key));
	}
	else if ((ft_searcINline("CS", key->sym) || (ft_searcINline("cs", key->sym) && key->modtype->l)) && MB_CUR_MAX > 1)
		size = ft_print_unic(key);
	else if (key->sym == 'f' || key->sym == 'F')
		size = ft_print_float(key);
	else
		size = (ft_print_char(key));
	ft_del_key(key);
	return (size);
}