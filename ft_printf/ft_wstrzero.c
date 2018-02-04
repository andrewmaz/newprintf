/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrzero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 19:41:22 by amazurok          #+#    #+#             */
/*   Updated: 2018/02/04 19:41:26 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_wtrzero(wchar_t *w1, int n)
{
	int i;

	i = 0;
	while (i < n)
		w1[i++] = 0;
	return (w1);
}
