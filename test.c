#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#define print(fmt, ...)\
	do{\
		int a = printf("'"fmt"'\n", ##__VA_ARGS__);	\
		fflush(stdout);\
		int b = ft_printf("'"fmt"'\n", ##__VA_ARGS__);	\
		printf("%d =? %d\n", a, b);			\
	}while(0);

#define TEST(id, x)\
	printf("%d: %s\n", id, #x);\
	x;

int	main()
{
/*
     TEST(5, print(" %-1c %-2c %-3c ", '0', 0, '1'));
     TEST(8, print(" %-1c %-2c %-3c ", '2', '1', 0));
     TEST(9, print(" %-1c %-2c %-3c ", 0, '1', '2')); */

	TEST(1, print("%.s", ""));
	TEST(2, print(" %.1s", ""));
	TEST(3, print("%.1s ", ""));
	TEST(4, print(" %.s ", ""));
	TEST(5, print(" %.s ", "-"));
	TEST(6, print(" %.2s %.1s ", "", "-"));
	TEST(7, print(" %.3s %.2s ", " - ", ""));
	TEST(8, print(" %.1s %.2s %.3s %.4s ", " - ", "", "4", ""));
	TEST(9, print(" %.2s %.3s %.4s %.5s %.1s ", " - ", "", "4", "", "2 "));
	return (0);
}
