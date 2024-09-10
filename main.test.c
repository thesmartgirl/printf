#include <stdio.h>
#include <unistd.h>

int	check_base(char *base)
{
	int	j;
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (!(base[i] >= 32 && base[i] <= 126))
			return (0);
		if ((base[i] == '+' || base[i] == '-'))
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	write_digits(int nb, char *base)
{
	int	len;

	len = 0;
	while (base[len] != '\0')
	{
		len++;
	}
	if (nb >= len)
		write_digits(nb / len, base);
	ft_putchar(base[(nb % len)]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (check_base(base))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = nbr * -1;
		}
		write_digits(nbr, base);
	}
}

int	main(void)
{
	int	num;
	int	*p;

	//  signed int n1 = 10;
	// signed int n2 = -65235894;
	// signed int n3 = -63215;
	// signed int n4 = 452101;
	num = 42;
	p = &num;
	ft_putnbr_base((int)p, "123456789abcdef");
	return (0);
}
