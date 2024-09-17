/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:14:33 by ataan             #+#    #+#             */
/*   Updated: 2024/09/08 17:26:15 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static void	ft_calc_content(const unsigned int u, t_format_flags *flags,
	t_to_print *nbr_print)
{
	nbr_print->s = ft_itoa(u);
	if (u == 0 && flags->precision_set == 1 && flags->precision == 0)
		nbr_print->s = ft_strdup("");
	nbr_print->digits = ft_strlen(nbr_print->s);
	if (flags->flag_zero && !(flags->flag_minus) && flags->precision_set == 0)
		nbr_print->cpad = '0';
	else
		nbr_print->cpad = ' ';
	nbr_print->prefix = "a";
}

static void	ft_calc_len(t_format_flags *flags, t_to_print *nbr_print)
{
	nbr_print->tot_len = flags->field_width;
	if (flags->precision > nbr_print->digits)
	{
		if (nbr_print->tot_len < flags->precision + (nbr_print->prefix[0] != 'a'))
			nbr_print->tot_len = flags->precision + (nbr_print->prefix[0] != 'a');
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

int	ft_handle_udecimal(va_list *args, t_format_flags *flags)
{
	unsigned int	u;
	t_to_print	nbr_print;

	u = va_arg(*args, unsigned int);
	ft_calc_content(u, flags, &nbr_print);
	ft_calc_len(flags, &nbr_print);
	if (flags->flag_minus)
		return (ft_print_left_adj(&nbr_print));
	else
		return (ft_print_right_adj(&nbr_print));
}
