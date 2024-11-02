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

static void	ft_calc_content(const int c, t_to_print *printTxt)
{
	printTxt->print_char = 1;
	printTxt->cprint = c;
}

static void	ft_calc_len(t_format_flags *flags, t_to_print *printTxt)
{
	if (flags->field_width > 0)
		printTxt->tot_len = flags->field_width;
	else
		printTxt->tot_len = 1;
	printTxt->pads = printTxt->tot_len - 1;
	printTxt->zeros = 0;
	printTxt->digits = 0;
}

int	ft_handle_char(va_list *args, t_format_flags *flags, t_to_print *printTxt)
{
	int	c;

	c = va_arg(*args, int);
	ft_calc_content(c, printTxt);
	ft_calc_len(flags, printTxt);
	if (flags->flag_minus)
		return (ft_print_left_adj(printTxt));
	else
		return (ft_print_right_adj(printTxt));
}
