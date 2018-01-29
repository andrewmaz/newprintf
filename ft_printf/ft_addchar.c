//
// Created by andrewmazz on 29.01.18.
//

char *ft_addchar(char *str, char c, int k)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	k = k + i;
	while (i < k)
		str[i++] = c;
	return (str);
}