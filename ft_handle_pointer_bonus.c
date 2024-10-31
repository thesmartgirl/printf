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
		t_to_print *nbr_print)
{
	if (ptr != 0)
	{
		free(nbr_print->prefix);
		nbr_print->prefix = ft_strdup("0x");
	}
	if (ptr == 0)
	{
		free(nbr_print->s);
		nbr_print->s = ft_strdup("(nil)");
	}
	else
	{
		free(nbr_print->s);
		nbr_print->s = ft_ptrtoa(ptr);
	}
	nbr_print->digits = ft_strlen(nbr_print->s);
	if (flags->flag_zero && !(flags->flag_minus) && flags->precision_set == 0)
		nbr_print->cpad = '0';
}

static void	ft_calc_len_ptr(t_format_flags *flags, t_to_print *nbr_print)
{
	nbr_print->tot_len = flags->field_width;
	if (flags->precision > nbr_print->digits && nbr_print->s[0] != '(')
	{
		if (nbr_print->tot_len < flags->precision + 2)
			nbr_print->tot_len = flags->precision + 2;
	}
	else if (nbr_print->tot_len < nbr_print->digits + 2
		&& nbr_print->s[0] != '(')
		nbr_print->tot_len = nbr_print->digits + 2;
	else if (nbr_print->tot_len < nbr_print->digits)
		nbr_print->tot_len = nbr_print->digits;
	nbr_print->zeros = 0;
	if (flags->precision > nbr_print->digits && nbr_print->s[0] != '(')
		nbr_print->zeros = flags->precision - nbr_print->digits;
	nbr_print->pads = nbr_print->tot_len - 2 * (nbr_print->s[0] != '(')
		- nbr_print->zeros - nbr_print->digits;
}

int	ft_handle_pointer(va_list *args, t_format_flags *flags,
		t_to_print *nbr_print)
{
	uintptr_t	ptr;

	ptr = (uintptr_t)va_arg(*args, void *);
	ft_calc_content_ptr(ptr, flags, nbr_print);
	ft_calc_len_ptr(flags, nbr_print);
	if (flags->flag_minus)
		return (ft_print_left_adj(nbr_print));
	else
		return (ft_print_right_adj(nbr_print));
}
