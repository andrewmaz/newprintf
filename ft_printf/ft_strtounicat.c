/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtounicat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:36:14 by amazurok          #+#    #+#             */
/*   Updated: 2018/02/02 17:38:20 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnustr(wchar_t *wstr, int n)
{
	int i;

	i = 0;
	while (wstr && i < n)
	{
		if (wstr[i] == -1)
		{
			write(1, "\0", 1);
			i++;
		}
		else
			ft_putuchar(wstr[i++]);
	}
}

void	ft_wstrdel(wchar_t **wstr)
{
	free(*wstr);
	*wstr = NULL;
}

void	ft_putustr(wchar_t *wstr)
{
	int i;

	i = 0;
	while (wstr && wstr[i])
	{
		if (wstr[i] == -1)
		{
			write(1, "\0", 1);
			i++;
		}
		else if (wstr[i] < 128)
			write(1, &wstr[i++], 1);
		else
			ft_putuchar(wstr[i++]);
	}
}

wchar_t	*ft_wtrzero(wchar_t *w1, int n)
{
	int i;

	i = 0;
	while (i < n)
		w1[i++] = 0;
	return (w1);
}

wchar_t	*ft_wtrcpy(wchar_t *w1, wchar_t *w2)
{
	size_t i;

	i = 0;
	while (w2 && w2[i])
	{
		w1[i] = w2[i];
		i++;
	}
	w1[i] = w2[i];
	return (w1);
}

wchar_t	*ft_myrealloc(wchar_t *wtr, size_t size)
{
	wchar_t *nwres;

	nwres = (wchar_t*)malloc(sizeof(wchar_t) * (size + 1));
	nwres = ft_wtrzero(nwres, size + 1);
	if (wtr)
	{
		nwres = ft_wtrcpy(nwres, wtr);
		ft_wstrdel(&wtr);
	}
	return (nwres);
}

wchar_t	*ft_wtrcat(wchar_t *wtr, wchar_t *wtr2)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (wtr[i])
		i++;
	while (wtr2 && wtr2[k])
		wtr[i++] = wtr2[k++];
	return (wtr);
}

wchar_t	*ft_wtrncat(wchar_t *wtr, wchar_t *wtr2, int n)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (wtr[i])
		i++;
	while (k < n)
		wtr[i++] = wtr2[k++];
	return (wtr);
}

wchar_t	*ft_mystrncat(wchar_t *wtr, char *str, int n)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (wtr[i])
		i++;
	while (k < n)
		wtr[i++] = str[k++];
	return (wtr);
}

wchar_t	*ft_mystrcat(wchar_t *wtr, char *str)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (wtr[i])
		i++;
	while (str[k])
		wtr[i++] = str[k++];
	return (wtr);
}
