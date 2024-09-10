/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:14:33 by ataan             #+#    #+#             */
/*   Updated: 2024/09/08 17:26:15 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int	ft_handle_pointer(va_list *args)
{
	uintptr_t	ptr;

	ptr = va_arg(*args, uintptr_t);
/*	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (0);
	}*/
	ft_putstr_fd("0x", 1);
	return (ft_putnbr_hex_fd(ptr, 1, 1));
}
