#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char c;

	c = 'f';
	printf("hello, %s.\n", NULL);
	ft_printf("hello, %s.\n", NULL);
}
