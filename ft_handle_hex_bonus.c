/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:14:33 by ataan             #+#    #+#             */
/*   Updated: 2024/09/08 17:26:15 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_calc_content_hex(const unsigned long u, t_format_flags *flags,
		int caps, t_to_print *nbr_print)
{
	nbr_print->prefix = ft_strdup("a");
	if (flags->flag_hash == 1)
	{
		if (caps)
			nbr_print->prefix = ft_strdup("0X");
		else
			nbr_print->prefix = ft_strdup("0x");
	}
	if (u == 0 && flags->precision_set == 1 && flags->precision == 0)
	{
		nbr_print->s = ft_strdup("");
		nbr_print->prefix = ft_strdup("a");
	}
	else
		nbr_print->s = ft_hextoa(u, caps);
	nbr_print->digits = ft_strlen(nbr_print->s);
	if (flags->flag_zero && !(flags->flag_minus) && flags->precision_set == 0)
		nbr_print->cpad = '0';
	else
		nbr_print->cpad = ' ';
}

void	ft_calc_len_hex(t_format_flags *flags, t_to_print *nbr_print)
{
	int	prefix_len;

	prefix_len = 2 * (nbr_print->prefix[0] != 'a');
	nbr_print->tot_len = flags->field_width;
	if (flags->precision > nbr_print->digits)
	{
		if (nbr_print->tot_len < flags->precision + prefix_len)
			nbr_print->tot_len = flags->precision + prefix_len;
	}
	else if (nbr_print->tot_len < nbr_print->digits
		+ (nbr_print->prefix[0] != 'a'))
		nbr_print->tot_len = nbr_print->digits + prefix_len;
	nbr_print->zeros = 0;
	if (flags->precision > nbr_print->digits)
		nbr_print->zeros = flags->precision - nbr_print->digits;
	nbr_print->pads = nbr_print->tot_len - prefix_len - nbr_print->zeros
		- nbr_print->digits;
}

int	ft_handle_hex(va_list *args, t_format_flags *flags)
{
	unsigned long	u;
	t_to_print		nbr_print;

	u = va_arg(*args, unsigned long);
	ft_bzero(&nbr_print, sizeof(t_to_print));
	ft_calc_content_hex(u, flags, 0, &nbr_print);
	ft_calc_len_hex(flags, &nbr_print);
	if (flags->flag_minus)
		return (ft_print_left_adj(&nbr_print));
	else
		return (ft_print_right_adj(&nbr_print));
}
