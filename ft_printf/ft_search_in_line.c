//
// Created by andrewmazz on 28.01.18.
//

#include "ft_printf.h"

int ft_searcINline(char *line, char c)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			return (1);
		i++;
	}
	return (0);
}