#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char c;

	c = 'f';
	printf("%+-8.5d\n", 34);
	ft_printf("%+-8.5d", 34);
}
