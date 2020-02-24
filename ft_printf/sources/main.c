#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char c;

	c = 'f';
	printf("%10.3d\n", 101);
	ft_printf("%10.3s", "abcdefg");
}
