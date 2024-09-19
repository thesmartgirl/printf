/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:14:33 by ataan             #+#    #+#             */
/*   Updated: 2024/09/08 17:26:15 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static void	ft_calc_content(const char *s, t_format_flags *flags,
		t_to_print *nbr_print)
{
	if(flags->precision_set == 1)
		nbr_print->s = ft_substr(nbr_print->s, 0, flags->precision);
	else
		nbr_print->s = ft_strdup(s);
	nbr_print->digits = ft_strlen(nbr_print->s);
	nbr_print->cpad = ' ';
	nbr_print->prefix = "a";
}

static void	ft_calc_len(t_format_flags *flags, t_to_print *nbr_print)
{
	nbr_print->tot_len = flags->field_width;
	if (nbr_print->tot_len < nbr_print->digits)
		nbr_print->tot_len = nbr_print->digits;
	nbr_print->zeros = 0;
	nbr_print->pads = nbr_print->tot_len - nbr_print->digits;
}

int	ft_handle_string(va_list *args, t_format_flags *flags)
{
	char	*s;
	t_to_print	nbr_print;

	s = va_arg(*args, char *);
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_calc_content(s, flags, &nbr_print);
	ft_calc_len(flags, &nbr_print);
	if (flags->flag_minus)
		return (ft_print_left_adj(&nbr_print));
	else
		return (ft_print_right_adj(&nbr_print));
}
