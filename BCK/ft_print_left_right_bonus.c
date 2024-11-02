/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_left_right_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:10:21 by ataan             #+#    #+#             */
/*   Updated: 2024/10/28 15:10:35 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_left_adj(t_to_print *nbr_print)
{
	if (nbr_print->prefix[0] != 'a')
		ft_putstr_fd(nbr_print->prefix, 1);
	while (nbr_print->zeros-- > 0)
		ft_putchar_fd('0', 1);
	if (nbr_print->print_char != 0)
	{
		ft_putchar_fd(nbr_print->cprint, 1);
	}
	else
		ft_putstr_fd(nbr_print->s, 1);
	while (nbr_print->pads-- > 0)
		ft_putchar_fd(nbr_print->cpad, 1);
	if (nbr_print->s != NULL)
	{
		free(nbr_print->s);
	}
	if (nbr_print->prefix != NULL)
	{
		free(nbr_print->prefix);
	}
	return (nbr_print->tot_len);
}

int	ft_print_right_adj(t_to_print *nbr_print)
{
	if (nbr_print->cpad == ' ')
	{
		while (nbr_print->pads-- > 0)
			ft_putchar_fd(nbr_print->cpad, 1);
	}
	if (nbr_print->prefix[0] != 'a')
		ft_putstr_fd(nbr_print->prefix, 1);
	if (nbr_print->cpad == '0')
	{
		while (nbr_print->pads-- > 0)
			ft_putchar_fd(nbr_print->cpad, 1);
	}
	while (nbr_print->zeros-- > 0)
		ft_putchar_fd('0', 1);
	if (nbr_print->print_char != 0)
		ft_putchar_fd(nbr_print->cprint, 1);
	else
		ft_putstr_fd(nbr_print->s, 1);
	if (nbr_print->s != NULL)
		free(nbr_print->s);
	if (nbr_print->prefix != NULL)
		free(nbr_print->prefix);
	return (nbr_print->tot_len);
}
