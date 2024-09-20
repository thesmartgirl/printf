/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_caps_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:14:33 by ataan             #+#    #+#             */
/*   Updated: 2024/09/08 17:26:15 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

int	ft_handle_hex_caps(va_list *args, t_format_flags *flags)
{
	unsigned long	u;
	t_to_print		nbr_print;

	u = va_arg(*args, unsigned long);
	ft_bzero(&nbr_print, sizeof(t_to_print));
	ft_calc_content_hex(u, flags, 1, &nbr_print);
	ft_calc_len_hex(flags, &nbr_print);
	if (flags->flag_minus)
		return (ft_print_left_adj(&nbr_print));
	else
		return (ft_print_right_adj(&nbr_print));
}
