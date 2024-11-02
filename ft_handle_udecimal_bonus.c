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
		t_to_print *printTxt)
{
	free(printTxt->s);
	printTxt->s = ft_uitoa(u);
	if (u == 0 && flags->precision_set == 1 && flags->precision == 0)
		printTxt->s = ft_strdup("");
	printTxt->digits = ft_strlen(printTxt->s);
	if (flags->flag_zero && !(flags->flag_minus) && flags->precision_set == 0)
		printTxt->cpad = '0';
}

static void	ft_calc_len(t_format_flags *flags, t_to_print *printTxt)
{
	printTxt->tot_len = flags->field_width;
	if (flags->precision > printTxt->digits)
	{
		if (printTxt->tot_len < flags->precision
			+ (printTxt->prefix[0] != 'a'))
			printTxt->tot_len = flags->precision
				+ (printTxt->prefix[0] != 'a');
	}
	else if (printTxt->tot_len < printTxt->digits
		+ (printTxt->prefix[0] != 'a'))
		printTxt->tot_len = printTxt->digits + (printTxt->prefix[0] != 'a');
	printTxt->zeros = 0;
	if (flags->precision > printTxt->digits)
		printTxt->zeros = flags->precision - printTxt->digits;
	printTxt->pads = printTxt->tot_len - (printTxt->prefix[0] != 'a')
		- printTxt->zeros - printTxt->digits;
}

int	ft_handle_udecimal(va_list *args, t_format_flags *flags,
		t_to_print *printTxt)
{
	unsigned int	u;

	u = (unsigned int)va_arg(*args, unsigned int);
	ft_calc_content(u, flags, printTxt);
	ft_calc_len(flags, printTxt);
	if (flags->flag_minus)
		return (ft_print_left_adj(printTxt));
	else
		return (ft_print_right_adj(printTxt));
}
