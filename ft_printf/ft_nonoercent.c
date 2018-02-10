//
// Created by Andrii MAZUROK on 2/10/18.
//

#include "ft_printf.h"

int ft_color(wchar_t **wres, char *col, t_res *tres, wchar_t *color)
{
	if (!ft_strcmp(col, "black"))
		color = ft_wtrcat(color, L"\033[30m");
	else if (!ft_strcmp(col, "red"))
		color = ft_wtrcat(color, L"\033[31m");
	else if (!ft_strcmp(col, "green"))
		color = ft_wtrcat(color, L"\033[32m");
	else if (!ft_strcmp(col, "yellow"))
		color = ft_wtrcat(color, L"\033[33m");
	else if (!ft_strcmp(col, "blue"))
		color = ft_wtrcat(color, L"\033[34m");
	else if (!ft_strcmp(col, "purple"))
		color = ft_wtrcat(color, L"\033[35m");
	else if (!ft_strcmp(col, "cyan"))
		color = ft_wtrcat(color, L"\033[36m");
	else if (!ft_strcmp(col, "grey"))
		color = ft_wtrcat(color, L"\033[37m");
	else if (!ft_strcmp(col, "eoc"))
		color = ft_wtrcat(color, L"\033[0m");
	else
		return (0);
	tres->i += ft_wstrlen(color);
	*wres = ft_myrealloc(*wres, tres->i);
	*wres = ft_wtrcat(*wres, color);
	return (1);
}

int ft_setcolor(wchar_t **wres, char *col, t_res *tres)
{
	wchar_t *color;
	int ret;

	color = NULL;
	color = ft_myrealloc(color, 5);
	ret = ft_color(wres, col, tres, color);
	ft_wstrdel(&color);
	return (ret);
}

wchar_t *ft_nonpercent(const char **format, wchar_t *wres, const char *frm, t_res *tres)
{
	const char *tmp;
	char *col;
	int i;

	tmp = *format;
	i = 0;
	col = ft_strnew(6);
	if (*tmp == '{')
	{
		tmp++;
		while (*tmp && *tmp != '}' && i < 7)
			col[i++] = *tmp++;
		tmp++;
		if (ft_setcolor(&wres, col, tres))
		{
			*format = tmp;
			return (wres);
		}
	}
	wres = ft_myrealloc(wres, tres->i + 1);
	wres[tres->i++] = *frm;
	++*format;
	tres->size++;
	ft_strdel(&col);
	return (wres);
}