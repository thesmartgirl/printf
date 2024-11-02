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

int	ft_print_left_adj(t_to_print *printTxt)
{
	if (printTxt->prefix[0] != 'a')
		ft_putstr_fd(printTxt->prefix, 1);
	while (printTxt->zeros-- > 0)
		ft_putchar_fd('0', 1);
	if (printTxt->print_char != 0)
	{
		ft_putchar_fd(printTxt->cprint, 1);
	}
	else
		ft_putstr_fd(printTxt->s, 1);
	while (printTxt->pads-- > 0)
		ft_putchar_fd(printTxt->cpad, 1);
	if (printTxt->s != NULL)
	{
		free(printTxt->s);
	}
	if (printTxt->prefix != NULL)
	{
		free(printTxt->prefix);
	}
	return (printTxt->tot_len);
}

int	ft_print_right_adj(t_to_print *printTxt)
{
	if (printTxt->cpad == ' ')
	{
		while (printTxt->pads-- > 0)
			ft_putchar_fd(printTxt->cpad, 1);
	}
	if (printTxt->prefix[0] != 'a')
		ft_putstr_fd(printTxt->prefix, 1);
	if (printTxt->cpad == '0')
	{
		while (printTxt->pads-- > 0)
			ft_putchar_fd(printTxt->cpad, 1);
	}
	while (printTxt->zeros-- > 0)
		ft_putchar_fd('0', 1);
	if (printTxt->print_char != 0)
		ft_putchar_fd(printTxt->cprint, 1);
	else
		ft_putstr_fd(printTxt->s, 1);
	if (printTxt->s != NULL)
		free(printTxt->s);
	if (printTxt->prefix != NULL)
		free(printTxt->prefix);
	return (printTxt->tot_len);
}
