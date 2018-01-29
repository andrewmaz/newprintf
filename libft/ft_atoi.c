/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:35:40 by amazurok          #+#    #+#             */
/*   Updated: 2017/11/03 18:11:47 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	blanks(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
			|| str[i] == '\r' || str[i] == '\f')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	unsigned long int	res;
	int					i;
	int					m;

	m = 1;
	res = 0;
	i = blanks(str);
	if (str[i] == '-')
		m = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		if (res >= 9223372036854775807 && m == 1)
			return (-1);
		else if (res > 9223372036854775807 && m == -1)
			return (0);
		i++;
	}
	return (res * m);
}
