/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:26:39 by amazurok          #+#    #+#             */
/*   Updated: 2018/01/23 12:26:42 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_struper(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		str[i] = (char)ft_toupper(str[i]);
	return (str);
}
