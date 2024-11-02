/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:14:33 by ataan             #+#    #+#             */
/*   Updated: 2024/10/28 15:11:51 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static void	ft_calc_content(const char *s, t_format_flags *flags,
		t_to_print *printTxt)
{
	free(printTxt->s);
	if (s == NULL)
		printTxt->s = ft_strdup("(null)");
	else
		printTxt->s = ft_strdup(s);
	//this is new
	if (s == NULL && flags->precision_set == 1 && flags->precision < 6 )
		printTxt->s = ft_strdup("");
	//this is new
	if (flags->precision_set && s != NULL)
	{
		if (flags->precision == 0)
		{
			free(printTxt->s);
			printTxt->s = ft_strdup("");
		}
		else
		{
			free(printTxt->s);
			printTxt->s = ft_substr(s, 0, flags->precision);
		}
	}
	printTxt->digits = ft_strlen(printTxt->s);
}

static void	ft_calc_len(t_format_flags *flags, t_to_print *printTxt)
{
	printTxt->tot_len = flags->field_width;
	if (printTxt->tot_len < printTxt->digits)
		printTxt->tot_len = printTxt->digits;
	printTxt->zeros = 0;
	printTxt->pads = printTxt->tot_len - printTxt->digits;
}

int	ft_handle_string(va_list *args, t_format_flags *flags,
		t_to_print *printTxt)
{
	char	*s;

	s = va_arg(*args, char *);
	ft_calc_content(s, flags, printTxt);
	ft_calc_len(flags, printTxt);
	if (flags->flag_minus)
		return (ft_print_left_adj(printTxt));
	else
		return (ft_print_right_adj(printTxt));
}
