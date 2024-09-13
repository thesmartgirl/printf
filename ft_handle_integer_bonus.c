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
#include "ft_printf_bonus.h"
static int ft_write_int_flags (const int i, t_format_flags *flags)
{
	char	*s;
	char	*pad;
	int		len;

	len = 0;
	s = ft_itoa(i);
	len += ft_strlen(s);
	if (len >= flags->precision)
		flags->precision_set = 0;
	else if (flags->precision_set)
	{
		if(flags->precision > flags->field_width)
		{
			len = flags->precision;
			pad = '0';
		}
		else if (flags->flag_zero)
		{
			len = flags->field_width;
			pad = ' ';
		}
	}
	else
	{
			if (len >= flags->field_width )
			{
				ft_putstr_fd(s, 1);
				return (len);
			}
			else
				pad = ' ';
	}

}

	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}

/* backup
int	ft_handle_integer(va_list *args, t_format_flags *flags)
{
	int		i;
	int		len;
	char	*s;

	i = va_arg(*args, int);
	s = ft_itoa(i);
	len = 0;
	if (flags->flag_plus && i > 0)
	{
		ft_putchar_fd('+', 1);
		len = 1;
	}
	else if (flags->flag_space && i > 0)
	{
		ft_putchar_fd(' ', 1);
		len = 1;
	}
	len += ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}
*/

int	ft_handle_integer(va_list *args, t_format_flags *flags)
{
	int		i;

	i = va_arg(*args, int);
	if (flags->flag_plus && i > 0)
	{
		ft_putchar_fd('+', 1);
		len = 1;
	}
	else if (flags->flag_space && i > 0)
	{
		ft_putchar_fd(' ', 1);
		len = 1;
	}
	return (ft_write_int_flags(i, flags));
}
