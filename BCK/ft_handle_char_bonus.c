/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:14:33 by ataan             #+#    #+#             */
/*   Updated: 2024/09/08 17:26:15 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static void	ft_calc_content(const int c, t_to_print *nbr_print)
{
	nbr_print->print_char = 1;
	nbr_print->cprint = c;
}

static void	ft_calc_len(t_format_flags *flags, t_to_print *nbr_print)
{
	if (flags->field_width > 0)
		nbr_print->tot_len = flags->field_width;
	else
		nbr_print->tot_len = 1;
	nbr_print->pads = nbr_print->tot_len - 1;
	nbr_print->zeros = 0;
	nbr_print->digits = 0;
}

int	ft_handle_char(va_list *args, t_format_flags *flags, t_to_print *nbr_print)
{
	int	c;

	c = va_arg(*args, int);
	ft_calc_content(c, nbr_print);
	ft_calc_len(flags, nbr_print);
	if (flags->flag_minus)
		return (ft_print_left_adj(nbr_print));
	else
		return (ft_print_right_adj(nbr_print));
}
