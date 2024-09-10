#include <stdio.h>

int	main(void)
{
	printf("%2$d %1$s\n", "hello", 42); // prints "42 hello"
	return (0);
}
