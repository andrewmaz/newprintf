/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:52:04 by amazurok          #+#    #+#             */
/*   Updated: 2017/11/07 13:13:29 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_char_replace(char *str, char s, char f)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
		{
			if (str[i] == s)
				str[i] = f;
			i++;
		}
}
