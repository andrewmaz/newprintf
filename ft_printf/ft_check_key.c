//
// Created by andrewmazz on 28.01.18.
//

#include "ft_printf.h"

static int ft_check_flag(t_key *key, char c)
{
	if (c == '+')
		key->flag->plus = 1;
	else if (c == '-')
		key->flag->minus = 1;
	else if (c == '#')
		key->flag->hash = 1;
	else if (c == '0')
		key->flag->zero = 1;
	else if (c == ' ')
		key->flag->space = 1;
	return (1);
}

static int		ft_check_modtype(t_key *key, const char *format)
{
	int i;
	int res;

	i = 0;
	if ((res = (format[i] == 'h')))
	{
		if ((res += (format[i + 1] == 'h')) == 2)
			key->modtype->hh = 1;
		else
			key->modtype->h = 1;
	}
	else if ((res = (format[i] == 'l')))
	{
		if ((res += (format[i + 1] == 'l')) == 2)
			key->modtype->ll = 1;
		else
			key->modtype->l = 1;
	}
	else if ((res = (format[i] == 'j')))
		key->modtype->j = 1;
	else if ((res = (format[i] == 'z')))
		key->modtype->z = 1;
	return (res);
}

static int		ft_prescision_and_width(t_key *key, const char *format, int pr)
{
	int i;

	i = 0;
	if (pr)
	{
		i++;
		key->precision = ft_atoi(format + 1);
	}
	else
		key->width = ft_atoi(format);
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}



int ft_check_key(t_key *key, const char *format)
{
	while (*format && !key->sym)
	{
		if(ft_searcINline("0+-# ", *format))
			format += ft_check_flag(key, *format);
		else if (ft_searcINline("hljz", *format))
			format += ft_check_modtype(key, format);
		else if (*format == '.')
			format += ft_prescision_and_width(key, format, 1);
		else if (ft_isdigit(*format))
			format += ft_prescision_and_width(key, format, 0);
		else
			key->sym = *format;
	}
	return (key->sym);
}