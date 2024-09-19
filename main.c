#include "ft_printf.h"
#include "./libft/libft.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
//	printf("%d\n", ft_printf("%u\n", 4294967295u));
//	printf("%d\n", printf("%u\n", 4294967295u));

	printf("%d\n", ft_printf("01 |%3.s|\n", NULL));
	fflush(stdout);
	printf("%d\n", printf("02 |%3.s|\n", NULL));
	fflush(stdout);

	printf("%d\n",ft_printf("%-5c", '\0'));
	fflush(stdout);
	printf("%d\n", printf("%-5c", '\0'));
	fflush(stdout);

//	printf("%lld\n", ft_strlen(ft_itoa(INT_MIN)) - (INT_MIN < 0) );
//	printf("%d\n", printf("|%10.3s|\n", "Hello"));
		//int	*p;
	//ft_printf(" NULL %s NULL ", NULL);
	//printf("%d", printf(" NULL %s NULL ", NULL));

	/*printf("%d\n", ft_printf("Hello! I have % u apples and %s oranges.\n",6789, "five"));
	fflush(stdout);
	printf("%d\n", printf("Hello! I have %#u apples and %s oranges.\n",	6789, "five"));
	fflush(stdout);
	printf("ft_printf hex return value %d\n", ft_printf("%#X\n", 109878724));
	fflush(stdout);
	printf("printf hex return value %d\n", printf("%#X\n", 109878724));
	fflush(stdout);*/
	//int num = 42;
	//p = &num;
	//printf("%d\n", ft_printf(" %p %p ", 0, 0));
	//printf("%d\n", printf(" %p %p ", 0, 0));

	//printf("%d\n", printf(" %p ", -1));
	//printf("%d\n", printf("printf The address of num: %p\n", (void *)p));
	//fflush(stdout);
	//printf("%d\n", ft_printf("ft_printf udecimal: %u\n", 76589));
	//fflush(stdout);
	//printf("%d\n", printf("___printf udecimal: %u\n", 76589));
	//fflush(stdout);
	// printf("ft_printf udecimal return (value %d\n", ft_printf("%u\n",
	//		-76589)));
	// printf("printf udecimal return (value %d\n", printf("%u\n", -76589)));
	/*	ft_printf("ft_printf hex: %x\n", 0x01ABCDEF);
		printf("printf hex: %x\n", 0x01ABCDEF);

		ft_printf("ft_printf HEX: %X\n", 0x01ABCDEF);
		printf("printf HEX: %X\n", 0x01ABCDEF);
		printf("ft_printf HEX return (value %d\n", ft_printf("%X\n",
				0x01ABCDEF)));
		printf("printf HEX return (value %d\n", printf("%X\n", 0x01ABCDEF)));
		ft_printf("%%\n");
		printf("%%\n");
		printf("ft_printf %% return (value %d\n", ft_printf("%%\n")));
		printf("printf %% return (value %d\n", printf("%%\n")));
		*/
	return (0);
}

/*
int	main(void)
{
	int	num;
	int	*p;

	num = 42;
	p = &num;
	ft_printf("The address of num: %p\n", (void *)p);
	return (0);
}
*/
