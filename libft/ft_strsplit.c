/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:50:47 by amazurok          #+#    #+#             */
/*   Updated: 2017/11/06 13:14:51 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numword(const char *s, char c)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (ft_isprint(s[i]) && s[i] != c && (s[i + 1] == c || !s[i + 1]))
			res++;
		i++;
	}
	return (res);
}

static int	ft_wl(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	*ft_free(char **s)
{
	int i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	s = NULL;
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (!(res = (char**)malloc(sizeof(char*) * (ft_numword(s, c) + 1))))
		return (NULL);
	while (i < ft_numword(s, c))
	{
		while (s[j] == c)
			j++;
		if (!(res[i] = ft_strsub(s, j, ft_wl(s + j, c))))
			return (ft_free(res));
		j += ft_wl(s + j, c);
		i++;
	}
	res[i] = NULL;
	return (res);
}
