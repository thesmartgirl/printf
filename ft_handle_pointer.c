/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:14:33 by ataan             #+#    #+#             */
/*   Updated: 2024/09/11 16:49:03 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_handle_pointer(va_list *args)
{
	unsigned long	ptr;

	ptr = (unsigned long)va_arg(*args, void *);
	if (ptr != 0)
	{
		ft_putstr_fd("0x", 1);
		return (ft_putnbr_hex_fd(ptr, 0, 1) + 2);
	}
	else
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
}
