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

int	ft_handle_hex(va_list *args, t_format_flags *flags)
{
	unsigned int	u;

	u = va_arg(*args, unsigned int);
	if (flags->flag_hash == 1)
	{
		ft_putstr_fd("0x", 1);
		return (ft_putnbr_hex_fd((uintptr_t)u, 0, 1) + 2);
	}
	else
		return (ft_putnbr_hex_fd((uintptr_t)u, 0, 1));
}
