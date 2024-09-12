/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:14:33 by ataan             #+#    #+#             */
/*   Updated: 2024/09/08 17:26:15 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_handle_udecimal(va_list *args)
{
	unsigned int	u;
	char			*s;
	int				len;

	u = va_arg(*args, unsigned int);
	s = ft_uitoa(u);
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}
