#include "ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int main()
{
    // char c = 'c';

    printf("%d\n", ft_printf("%#x ", 1651651651651));
    printf("%d\n", printf("%#x ", 1651651651651));
}