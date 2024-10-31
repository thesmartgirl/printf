#include "ft_printf.h"
#include "./libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	printf("%.09s", NULL);
	printf("%3.6s", NULL);
	printf("%20.6s", NULL);
	printf("%-3.8s", NULL);
	printf("%-10.8s", NULL);
	printf("%117p%-44c%-156c%-88.109s%0%" ,(void*)8225290685743754462lu,-123,65,NULL);
	printf("%0168.128u%0054.92x%30.171s" ,2620195206u,1771128939u,NULL);
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
