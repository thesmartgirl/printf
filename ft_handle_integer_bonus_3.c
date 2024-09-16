/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:14:33 by ataan             #+#    #+#             */
/*   Updated: 2024/09/11 16:50:46 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static void	ft_print_left_adj(t_to_print *nbr_print)
{
	if (nbr_print->prefix != 'a')
		ft_putchar_fd(nbr_print->prefix, 1);
	while (nbr_print->zeros-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(nbr_print->s, 1);
	while (nbr_print->pads-- > 0)
		ft_putchar_fd(nbr_print->cpad, 1);
}

static void	ft_print_right_adj(t_to_print *nbr_print)
{
	if (nbr_print->cpad == ' ')
	{
		while (nbr_print->pads-- > 0)
			ft_putchar_fd(nbr_print->cpad, 1);
	}
	if (nbr_print->prefix != 'a')
		ft_putchar_fd(nbr_print->prefix, 1);
	if (nbr_print->cpad == '0')
	{
		while (nbr_print->pads-- > 0)
			ft_putchar_fd(nbr_print->cpad, 1);
	}
	while (nbr_print->zeros-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(nbr_print->s, 1);
}

static int	ft_write_nbr_print(t_to_print *nbr_print, t_format_flags *flags)
{
	if (flags->flag_minus)
		ft_print_left_adj(nbr_print);
	else
		ft_print_right_adj(nbr_print);
	free(nbr_print->s);
	return (nbr_print->tot_len);
}

static void	ft_digits(const int i, t_to_print *nbr_print)
{
	if (i > 0)
	{
		nbr_print->s = ft_itoa(i);
	}
	else
		nbr_print->s = ft_itoa(-i);
	nbr_print->digits = ft_strlen(nbr_print->s);
}

static void	ft_cpad_prefix(int i, t_format_flags *flags, t_to_print *nbr_print)
{
	if (flags->flag_zero && !(flags->flag_minus) && flags->precision_set == 0)
		nbr_print->cpad = '0';
	else
		nbr_print->cpad = ' ';
	nbr_print->prefix = 'a';
	if (i < 0)
		nbr_print->prefix = '-';
	else if (flags->flag_plus && i > 0)
		nbr_print->prefix = '+';
	else if (flags->flag_space && i > 0)
		nbr_print->prefix = ' ';
}

static void	ft_calc_len(t_format_flags *flags, t_to_print *nbr_print)
{
	nbr_print->tot_len = flags->field_width;
	if (flags->precision > nbr_print->digits)
	{
		if (nbr_print->tot_len < flags->precision + (nbr_print->prefix != 'a'))
			nbr_print->tot_len = flags->precision + (nbr_print->prefix != 'a');
	}
	else if (nbr_print->tot_len < nbr_print->digits
		+ (nbr_print->prefix != 'a'))
		nbr_print->tot_len = nbr_print->digits + (nbr_print->prefix != 'a');
	nbr_print->zeros = 0;
	if (flags->precision > nbr_print->digits)
		nbr_print->zeros = flags->precision - nbr_print->digits;
	nbr_print->pads = nbr_print->tot_len - (nbr_print->prefix != 'a')
		- nbr_print->zeros - nbr_print->digits;
	printf("tot_len %d\n", nbr_print->tot_len);
	printf("digits %d\n", nbr_print->digits);
	printf("zeros %d\n", nbr_print->zeros);
	printf("pads %d\n", nbr_print->pads);
	printf("prefix %c\n", nbr_print->prefix);
}

static void	ft_prep_nbr_print(int i, t_format_flags *flags,
		t_to_print *nbr_print)
{
	ft_digits(i, nbr_print);
	ft_cpad_prefix(i, flags, nbr_print);
	ft_calc_len(flags, nbr_print);
}

int	ft_handle_integer(va_list *args, t_format_flags *flags)
{
	int			i;
	t_to_print	nbr_print;

	i = va_arg(*args, int);
	ft_prep_nbr_print(i, flags, &nbr_print);
	return (ft_write_nbr_print(&nbr_print, flags));
}
