#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int a,b;

  	a = ft_printf("%.19f",        1.025978548534310421934);
	printf("ft_printf:%d\n", a);
	b = printf("%.20f",        1.025978548534310421934);
	printf("printf:%d\n", b);
	return (0);
}
