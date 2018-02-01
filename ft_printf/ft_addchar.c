//
// Created by andrewmazz on 29.01.18.
//

char *ft_addchar(char *str, char c, int k, int s)
{
	while (str[s])
		s++;
	k = k + s;
	while (s < k)
		str[s++] = c;
	return (str);
}