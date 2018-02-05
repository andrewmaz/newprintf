/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myputwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 19:33:59 by amazurok          #+#    #+#             */
/*   Updated: 2018/02/04 19:34:07 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putustr(wchar_t *wstr)
{
	int i;

	i = 0;
	while (wstr && wstr[i])
	{
		//if (wstr[i] == 127)
		//{
		//	write(1, "\0", 1);
		//	i++;
		//}
		if (wstr[i] < 128)
			write(1, &wstr[i++], 1);
		else
			ft_putuchar(wstr[i++]);
	}
}
