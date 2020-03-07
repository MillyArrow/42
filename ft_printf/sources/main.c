#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int a,b;

  	a = ft_printf("this %.0f float", 1.6);
	printf("ft_printf:%d\n", a);
	b = printf("this %.0f float", 1.6);
	printf("printf:%d\n", b);
	return (0);
}
