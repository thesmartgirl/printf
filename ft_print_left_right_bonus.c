#include "ft_printf_bonus.h"

int	ft_print_left_adj(t_to_print *nbr_print)
{
	if (nbr_print->prefix[0] != 'a')
		ft_putstr_fd(nbr_print->prefix, 1);
	while (nbr_print->zeros-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(nbr_print->s, 1);
	while (nbr_print->pads-- > 0)
		ft_putchar_fd(nbr_print->cpad, 1);
	free(nbr_print->s);
	return (nbr_print->tot_len);
}

int	ft_print_right_adj(t_to_print *nbr_print)
{
	if (nbr_print->cpad == ' ')
	{
		while (nbr_print->pads-- > 0)
			ft_putchar_fd(nbr_print->cpad, 1);
	}
	if (nbr_print->prefix[0] != 'a')
		ft_putstr_fd(nbr_print->prefix, 1);
	if (nbr_print->cpad == '0')
	{
		while (nbr_print->pads-- > 0)
			ft_putchar_fd(nbr_print->cpad, 1);
	}
	while (nbr_print->zeros-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(nbr_print->s, 1);
	free(nbr_print->s);
	return (nbr_print->tot_len);
}
