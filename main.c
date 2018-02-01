#include "./ft_printf/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

# include <wchar.h>
# include "../libft/libft.h"
# include <stdint.h>
# include <stdarg.h>
# include <locale.h>

int main()
{
	setlocale(LC_ALL, "");
	int a = 1;
	int p = 0;
	int fp = 0;

	//wchar_t *res = (wchar_t*);


	//ft_putustr(res);
	printf(" my ret %d\n", ft_printf("12 %d %s %c qwr", 1234, "qwe", '\0'));
	printf("!my ret %d\n",    printf("12 %d %s %c qwr", 1234, "qwe", '\0'));

	//printf("asd\n");


//	p = printf("string_8(s) - %s\n", "strrrasdasdasd");
//	fp = ft_printf("ft_string_8(s) - %s\n", "strrrasdasdasd");
//	p = printf("string_16(S) - %S\n", L"str");
//
//	p = printf("address(p) - %p\n", &a);
//
//
//	p = printf("decimal(d) - %d\n", 1234);
//	fp = ft_printf("ft_decimal(d) - %d\n", 1234);
//	p = printf("(ld) - %D\n", 123);
//
//	p = printf("int(i) - %i\n", 123);
//	fp = ft_printf("ft_int(i) - %i\n", 123);
//	p = printf("octal(o) - %o\n", 2);
//
//	p = printf("(lo) - %O\n", 2);
//
//	p = printf("unsint(u) - %u\n", 23);
//
//	p = printf("(lu) - %U\n", 123);
//
//	p = printf("hex(x) - %x\n", 123);
//
//	p = printf("HEX(X) - %X\n", 123);
//	p = printf("char(c) - %c\n", 'a');
//	fp = ft_printf("ft_char(c) - %c\n", 'a');
//	p = printf("?wchar(C) - %C\n", 'a');

	//printf("test - %0*s\n", "2");

	//printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "filename", "str");


}
