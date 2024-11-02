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

void	ft_calc_content_hex(const unsigned int u, t_format_flags *flags,
		int caps, t_to_print *printTxt)
{
	if (flags->flag_hash == 1 && u != 0)
	{
		free(printTxt->prefix);
		if (caps)
		{
			printTxt->prefix = ft_strdup("0X");
		}
		else
		{
			printTxt->prefix = ft_strdup("0x");
		}
	}
	if (u == 0 && flags->precision_set == 1 && flags->precision == 0)
	{
		free(printTxt->s);
		printTxt->s = ft_strdup("");
	}
	else
	{
		free(printTxt->s);
		printTxt->s = ft_hextoa(u, caps);
	}
	printTxt->digits = ft_strlen(printTxt->s);
	if (flags->flag_zero && !(flags->flag_minus) && flags->precision_set == 0)
		printTxt->cpad = '0';
}

void	ft_calc_len_hex(t_format_flags *flags, t_to_print *printTxt)
{
	int	prefix_len;

	prefix_len = 2 * (printTxt->prefix[0] != 'a');
	printTxt->tot_len = flags->field_width;
	if (flags->precision > printTxt->digits)
	{
		if (printTxt->tot_len < flags->precision + prefix_len)
			printTxt->tot_len = flags->precision + prefix_len;
	}
	else if (printTxt->tot_len < printTxt->digits
		+ (printTxt->prefix[0] != 'a'))
		printTxt->tot_len = printTxt->digits + prefix_len;
	printTxt->zeros = 0;
	if (flags->precision > printTxt->digits)
		printTxt->zeros = flags->precision - printTxt->digits;
	printTxt->pads = printTxt->tot_len - prefix_len - printTxt->zeros
		- printTxt->digits;
}

int	ft_handle_hex(va_list *args, t_format_flags *flags, t_to_print *printTxt)
{
	unsigned int	u;

	u = va_arg(*args, unsigned int);
	ft_calc_content_hex(u, flags, 0, printTxt);
	ft_calc_len_hex(flags, printTxt);
	if (flags->flag_minus)
		return (ft_print_left_adj(printTxt));
	else
		return (ft_print_right_adj(printTxt));
}
