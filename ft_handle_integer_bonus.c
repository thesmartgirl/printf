/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_integer_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:14:33 by ataan             #+#    #+#             */
/*   Updated: 2024/09/17 12:28:14 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static void	ft_calc_s(const int i, t_format_flags *flags,
		t_to_print *nbr_print)
{
	free(nbr_print->s);
	if (i == 0 && flags->precision_set == 1 && flags->precision == 0)
		nbr_print->s = ft_strdup("");
	else if (i > 0)
		nbr_print->s = ft_itoa(i);
	else if (i == -2147483648)
		nbr_print->s = ft_strdup("2147483648");
	else
		nbr_print->s = ft_itoa(-i);
}

static void	ft_calc_content(const int i, t_format_flags *flags,
		t_to_print *nbr_print)
{
	ft_calc_s(i, flags, nbr_print);
	nbr_print->digits = ft_strlen(nbr_print->s);
	if (flags->flag_zero && !(flags->flag_minus) && flags->precision_set == 0)
		nbr_print->cpad = '0';
	else
		nbr_print->cpad = ' ';
	if (i < 0)
	{
		free(nbr_print->prefix);
		nbr_print->prefix = ft_strdup("-");
	}
	else if (flags->flag_plus && i >= 0)
	{
		free(nbr_print->prefix);
		nbr_print->prefix = ft_strdup("+");
	}
	else if (flags->flag_space && i >= 0)
	{
		free(nbr_print->prefix);
		nbr_print->prefix = ft_strdup(" ");
	}
}

static void	ft_calc_len(t_format_flags *flags, t_to_print *nbr_print)
{
	nbr_print->tot_len = flags->field_width;
	if (flags->precision > nbr_print->digits)
	{
		if (nbr_print->tot_len < flags->precision
			+ (nbr_print->prefix[0] != 'a'))
			nbr_print->tot_len = flags->precision
				+ (nbr_print->prefix[0] != 'a');
	}
	else if (nbr_print->tot_len < nbr_print->digits
		+ (nbr_print->prefix[0] != 'a'))
		nbr_print->tot_len = nbr_print->digits + (nbr_print->prefix[0] != 'a');
	nbr_print->zeros = 0;
	if (flags->precision > nbr_print->digits)
		nbr_print->zeros = flags->precision - nbr_print->digits;
	nbr_print->pads = nbr_print->tot_len - (nbr_print->prefix[0] != 'a')
		- nbr_print->zeros - nbr_print->digits;
}

int	ft_handle_integer(va_list *args, t_format_flags *flags,
		t_to_print *nbr_print)
{
	int	i;

	i = va_arg(*args, int);
	ft_calc_content(i, flags, nbr_print);
	ft_calc_len(flags, nbr_print);
	if (flags->flag_minus)
		return (ft_print_left_adj(nbr_print));
	else
		return (ft_print_right_adj(nbr_print));
}
