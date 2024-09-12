#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
  printf("%d\n", printf("%-8i\n", 2345));
  printf("% i\n", 2345);
  printf("%+i\n", 2345);
  printf("%i\n", 2345);
  return 0;
}
