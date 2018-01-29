//
// Created by andrewmazz on 28.01.18.
//

#include "ft_printf.h"



static void	ft_mod_key(t_key *key)
{
	if (ft_searcINline("UDO", key->sym))
		key->modtype->l = 1;
	key->flag->hash = ft_searcINline("oOxX", key->sym) && key->res[0] == '0' &&\
		!key->precision ? 0 : key->flag->hash;
	key->flag->zero = key->precision >= 0 ? 0 : key->flag->zero;
	key->flag->space = (key->flag->plus || key->res[0] == '-' || \
	ft_searcINline("oOuUxX", key->sym) ? 0 : key->flag->space);
	key->flag->plus = (ft_searcINline("oOuUxX", key->sym)) ? 0 : key->flag->plus;
	key->flag->hash = ft_searcINline("poOuUxX", key->sym) ? key->flag->hash : 0;
	key->res = key->sym == 'X' ? ft_struper(key->res) : key->res;
}

int ft_max(int a, int b, int c)
{
	if (a >= b && a >= c)
		return (a);
	else if (b >= a && b >= c)
		return (b);
	else
		return (c);
}

char *ft_addchar(char *str, char c, int k)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	k = k + i;
	while (i < k)
		str[i++] = c;
	return (str);
}

char *ft_hash(t_key *key, char *res)
{
	if (key->sym == 'o' || key->sym == 'O')
		return (ft_strcat(res, "0"));
	else if (key->sym == 'x' && !(!key->precision && key->res[0] == '0'))
		return (ft_strcat(res, "0x"));
	else if (key->sym == 'X' && !(!key->precision && key->res[0] == '0'))
		return (ft_strcat(res, "0X"));
	else if (key->sym == 'p')
		return (ft_strcat(res, "0x"));
	return res;
}

int ft_size(t_key *key, int p, int w)
{
	int size;

	size = (p > 0 ? p : 0) + key->lenr + (w > 0 ? w : 0);
	size += key->flag->hash && ft_searcINline("oO", key->sym) ? 1 : 0;
	size += key->flag->hash && ft_searcINline("xX", key->sym) ? 2 : 0;
	size += key->sym == 'p' ? 2 : 0;
	size += key->flag->space;
	size -= (key->res[0] == '0' && !key->precision);
	return (size);

}

int ft_width(t_key *key, int p)
{
	int w;

	w = key->width - (p > 0 ? p : 0) - (key->res[0] == '0' && \
		!key->precision ? 0 : key->lenr);
	w -= key->flag->hash && ft_searcINline("oO", key->sym) ? 1 : 0;
	w -= key->flag->hash && ft_searcINline("xX", key->sym) ? 2 : 0;
	w -= key->sym == 'p' ? 2 : 0;
	w -= key->flag->space;
	return (w);
}

int ft_precision(t_key *key)
{
	int p;

	p = key->precision - key->lenr + (key->res[0] == '-');
	p -= key->flag->hash && (key->sym == 'o' || key->sym == 'O') ? 1 : 0;
	return (p);
}

int ft_flg_min(t_key *key)
{
	int size;
	int w;
	int p;
	char *res;

	p = ft_precision(key);
	w = ft_width(key, p);
	size = ft_size(key, p, w);
	res = ft_strnew(size);
	res[0] = key->res[0] == '-' ? '-' : res[0];
	res[0] = key->flag->plus && key->res[0] != '-' ? '+' : res[0];
	res[0] = key->flag->space ? ' ' : res[0];
	res = key->flag->hash ? ft_hash(key, res) : res;
	res = ft_addchar(res, '0', p);
	if (!(key->res[0] == '0' && !key->precision))
		res = ft_strcat(res, key->res + (res[0] == '-'));
	res = ft_addchar(res, ' ', w);
	write(1, res, size);
	return (size);
}

int ft_flg_nmin_zero(t_key *key)
{
	int size;
	int w;
	int p;
	char *res;

	p = ft_precision(key);
	w = ft_width(key, p);
	size = ft_size(key, p, w);
	res = ft_strnew(size);
	res[0] = key->res[0] == '-' ? '-' : res[0];
	res[0] = key->flag->plus && key->res[0] != '-' ? '+' : res[0];
	res[0] = key->flag->space ? ' ' : res[0];
	res = key->flag->hash ? ft_hash(key, res) : res;
	res = ft_addchar(res, '0', w);
	res = ft_addchar(res, '0', p);
	if (!(key->res[0] == '0' && !key->precision))
		res = ft_strcat(res, key->res + (res[0] == '-'));
	write(1, res, size);
	return (size);
}

int ft_flg_nmin_nzero(t_key *key)
{
	int size;
	int w;
	int p;
	char *res;

	p = ft_precision(key);
	w = ft_width(key, p);
	size = ft_size(key, p, w);
	res = ft_strnew(size);
	res[0] = key->res[0] == '-' ? '-' : res[0];
	res[0] = key->flag->plus && key->res[0] != '-' ? '+' : res[0];
	res[0] = key->flag->space ? ' ' : res[0];
	res = ft_addchar(res, ' ', w);
	res = key->flag->hash ? ft_hash(key, res) : res;
	res = ft_addchar(res, '0', p);
	if (!(key->res[0] == '0' && !key->precision))
		res = ft_strcat(res, key->res + (res[0] == '-'));
	write(1, res, size);
	return (size);
}

int			ft_print_dig(t_key *key)
{
	if (key->flag->minus)
		return (ft_flg_min(key));
	else if (key->flag->zero)
		return (ft_flg_nmin_zero(key));
	else
		return (ft_flg_nmin_nzero(key));
}

int ft_print_char(t_key *key)
{
	int size;
	int w;
	char *res;

	w = key->width - 1;
	size = w > 1 ? key->width : 1;
	res = ft_strnew(size);
	if (key->flag->minus)
	{
		res[0] = key->r;
		res = ft_addchar(res, ' ', w);
	}
	else
	{
		res = key->flag->zero ? ft_addchar(res, '0', w) : ft_addchar(res, ' ', w);
		res[size - 1] = key->r;
	}
	write(1, res, size);
	return (size);
}

int ft_print_str(t_key *key)
{
	int size;
	int w;
	int p;
	char *res;

	p =  key->precision;
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
	return (size);
}

int ft_print_res(t_key *key, va_list args)
{
	ft_process_args(key, args);
	if (!key->res && key->precision == -1)
		key->res = "(null)";
	key->lenr = key->res ? (int)ft_strlen(key->res) : 0;
	if (ft_searcINline("idDuUoOxXp", key->sym))
	{
		ft_mod_key(key);
		return (ft_print_dig(key));
	}
	else if (key->sym == 's')
	{
		return (ft_print_str(key));
	}
	else if (key->sym == 'S')
		return (0);
	else if (key->sym == 'C')
		return (0);
	else
		return (ft_print_char(key));
}