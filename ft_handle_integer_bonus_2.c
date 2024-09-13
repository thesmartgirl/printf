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

static int	ft_find_tot_len(int len, int digits, t_format_flags flags)
{
	tot_len = digits;
	if (flags->precision > tot_len)
		tot_len = flags->precision;
	if (flags->field_width > tot_len)
		tot_len = flags->field_width;
	return (tot_len + len);
}

static int	ft_int_set_prefix(int num, t_format_flags flags)
{
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		return (1);
	}
	else if (flags->flag_plus && i > 0)
	{
		ft_putchar_fd('+', 1);
		return (1);
	}
	else if (flags->flag_space && i > 0)
	{
		ft_putchar_fd(' ', 1);
		return (1);
	}
	return (0);
}

static void	ft_print_left_adj(const char *s, const int tot_len, const char pad)
{
	int	j;

	j = 0;
	while (j < tot_len && s[j] != '\0')
	{
		ft_putchar_fd(s[j], 1);
		j++;
	}
	while (j < tot_len)
	{
		ft_putchar_fd(pad, 1);
		j++;
	}
}

static void	ft_print_right_adj(const char *s, const int tot_len, const int len,
		const char pad)
{
	int	j;

	j = 0;
	while (j < tot_len - len)
	{
		ft_putchar_fd(pad, 1);
		j++;
	}
	while (j < tot_len)
	{
		ft_putchar_fd(s[j - (tot_len - len)], 1);
		j++;
	}
}

static int	ft_write_int_flags(const int i, t_format_flags *flags)
{
	int		num;
	int		tot_len;
	int		digits;
	int		zeros;
	int		pads;
	char	cpad;
	char	*s;

	num = va_arg(*args, int);
	tot_len = 0;
	tot_len += ft_int_set_prefix(flags); //+ - ' '
	s = ft_itoa(num);
	digits = ft_strlen(s) - (num < 0);
	tot_len = ft_find_tot_len(tot_len, digits, flags);
	zeros = flags->precision - digits;
	pads = tot_len - flags->precision;
	if (flags->flag_zero)
		cpad = '0';
	if (flags->flag_minus)
		ft_print_left_adj(s, tot_len, pad);
	else
		ft_print_right_adj(s, tot_len, len, pad);
	free(s);
	return (tot_len);
}

int	ft_handle_integer(va_list *args, t_format_flags *flags)
{
	int	i;
	int	len;

	i = va_arg(*args, int);
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
	return (len + ft_write_int_flags(i, flags));
}
