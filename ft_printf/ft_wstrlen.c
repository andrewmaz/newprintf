//
// Created by Andrii MAZUROK on 2/10/18.
//

#include "ft_printf.h"

int			ft_wstrlen(wchar_t *wstr)
{
	int i;

	i = 0;
	while (wstr && wstr[i])
		i++;
	return (i);
}
