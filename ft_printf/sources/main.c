#include "ft_printf.h"
#include <stdio.h>

int main()
{
  	ft_printf("%.8Lf", 1.99999949l);
  	write(1, "\n", 1);
	printf("%.8Lf", 1.99999949l);
    return (0);
}
