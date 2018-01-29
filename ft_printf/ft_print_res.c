//
// Created by andrewmazz on 28.01.18.
//

#include "ft_printf.h"

static void	ft_mod_key(t_key *key)
{
	if (ft_searcINline("UDO", key->sym))
		key->modtype->l = 1;
	if (key->res)
	{
		key->flag->hash = ft_searcINline("oOxX", key->sym) && key->res[0] == \
			'0' ? 0 : key->flag->hash;
		key->flag->space = (key->flag->plus || key->res[0] == '-' || \
			ft_searcINline("oOuUxX", key->sym) ? 0 : key->flag->space);
	}
	key->flag->zero = key->precision >= 0 ? 0 : key->flag->zero;
	key->flag->plus = (ft_searcINline("oOuUxX", key->sym)) ? 0 : key->flag->plus;
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

}

int ft_print_res(t_key *key, va_list args)
{
	int size;

	ft_process_args(key, args);
	if (!key->res && key->precision == -1)
		key->res = "(null)";
	ft_mod_key(key);
	if (ft_searcINline("idDuUoOxXp", key->sym))
	{
		size = (ft_print_dig(key));
		ft_strdel(&key->res);
	}
	else if (key->sym == 's')
	{
		size = (ft_print_str(key));
	}
	else if (key->sym == 'S')
		size = (0);
	else if (key->sym == 'C')
		size = (0);
	else if (key->sym == 'f')
		size = ft_print_float(key);
	else
		size = (ft_print_char(key));
	ft_del_key(key);
	return (size);
}