/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:14:33 by ataan             #+#    #+#             */
/*   Updated: 2024/09/11 16:50:46 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_handle_integer_flags(va_list *args, format_flags *flags)
{
	int		i;
	int		len;
	char	*s;

	i = va_arg(*args, int);
	s = ft_itoa(i);
	len = 0;
	if(flags->flag_plus && i > 0)
	{
		ft_putchar_fd('+', 1);
		len = 1;
	}
	if(flags->flag_space && i > 0)
	{
		ft_putchar_fd(' ', 1);
		len = 1;
	}
	ft_putstr_fd(s, 1);
	len += ft_strlen(s);
	free(s);
	return (len);
}
