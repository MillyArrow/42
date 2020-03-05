#include "ft_printf.h"
#include <stdio.h>

int main()
{
  	ft_printf("%.20f", 1.025978548534310421934);
  	write(1, "\n", 1);
    printf("%.20f", 1.025978548534310421934);
    return (0);
}
