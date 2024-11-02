/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:14:33 by ataan             #+#    #+#             */
/*   Updated: 2024/10/28 15:12:21 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static void	ft_calc_content_ptr(const uintptr_t ptr, t_format_flags *flags,
		t_to_print *printTxt)
{
	if (ptr != 0)
	{
		free(printTxt->prefix);
		printTxt->prefix = ft_strdup("0x");
	}
	if (ptr == 0)
	{
		free(printTxt->s);
		printTxt->s = ft_strdup("(nil)");
	}
	else
	{
		free(printTxt->s);
		printTxt->s = ft_ptrtoa(ptr);
	}
	printTxt->digits = ft_strlen(printTxt->s);
	if (flags->flag_zero && !(flags->flag_minus) && flags->precision_set == 0)
		printTxt->cpad = '0';
}

static void	ft_calc_len_ptr(t_format_flags *flags, t_to_print *printTxt)
{
	printTxt->tot_len = flags->field_width;
	if (flags->precision > printTxt->digits && printTxt->s[0] != '(')
	{
		if (printTxt->tot_len < flags->precision + 2)
			printTxt->tot_len = flags->precision + 2;
	}
	else if (printTxt->tot_len < printTxt->digits + 2
		&& printTxt->s[0] != '(')
		printTxt->tot_len = printTxt->digits + 2;
	else if (printTxt->tot_len < printTxt->digits)
		printTxt->tot_len = printTxt->digits;
	printTxt->zeros = 0;
	if (flags->precision > printTxt->digits && printTxt->s[0] != '(')
		printTxt->zeros = flags->precision - printTxt->digits;
	printTxt->pads = printTxt->tot_len - 2 * (printTxt->s[0] != '(')
		- printTxt->zeros - printTxt->digits;
}

int	ft_handle_pointer(va_list *args, t_format_flags *flags,
		t_to_print *printTxt)
{
	uintptr_t	ptr;

	ptr = (uintptr_t)va_arg(*args, void *);
	ft_calc_content_ptr(ptr, flags, printTxt);
	ft_calc_len_ptr(flags, printTxt);
	if (flags->flag_minus)
		return (ft_print_left_adj(printTxt));
	else
		return (ft_print_right_adj(printTxt));
}
