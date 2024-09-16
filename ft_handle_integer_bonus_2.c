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

static int	ft_find_tot_len(int digits, char prefix, t_format_flags *flags)
{
	int	tot_len;

	tot_len = flags->field_width;
	if (flags->precision > digits)
	{
		if (tot_len < flags->precision + (prefix != 'a'))
			tot_len = flags->precision + (prefix != 'a');
	}
	else if (tot_len < digits + (prefix != 'a'))
		tot_len = digits + (prefix != 'a');
	return (tot_len);
}

static char	ft_int_set_prefix(int num, t_format_flags *flags)
{
	if (num < 0)
		return ('-');
	else if (flags->flag_plus && num > 0)
		return ('+');
	else if (flags->flag_space && num > 0)
		return (' ');
	return ('a');
}

static void	ft_print_left_adj(char *s, char prefix, int zeros, int pads,
		const char cpad)
{
	if (prefix != 'a')
		ft_putchar_fd(prefix, 1);
	while (zeros-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(s, 1);
	while (pads-- > 0)
		ft_putchar_fd(cpad, 1);
}

static void	ft_print_right_adj(char *s, char prefix, int zeros, int pads,
		const char cpad)
{
	if (cpad == ' ')
	{
		while (pads-- > 0)
			ft_putchar_fd(cpad, 1);
	}
	if (prefix != 'a')
		ft_putchar_fd(prefix, 1);
	if (cpad == '0')
	{
		while (pads-- > 0)
			ft_putchar_fd(cpad, 1);
	}
	while (zeros-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(s, 1);
}

static int	ft_write_int_flags(char *s, int digits, char prefix,
		t_format_flags *flags)
{
	int		tot_len;
	int		zeros;
	int		pads;
	char	cpad;

	tot_len = 0;
	tot_len = ft_find_tot_len(digits, prefix, flags);
	zeros = 0;
	if (flags->precision > digits)
	{
		zeros = flags->precision - digits;
	}
	pads = tot_len - (prefix != 'a') - zeros - digits;
	printf("tot_len %d\n", tot_len);
	printf("digits %d\n", digits);
	printf("zeros %d\n", zeros);
	printf("pads %d\n", pads);
	if (flags->flag_zero && !(flags->flag_minus))
		cpad = '0';
	else
		cpad = ' ';
	if (flags->flag_minus)
		ft_print_left_adj(s, prefix, zeros, pads, cpad);
	else
		ft_print_right_adj(s, prefix, zeros, pads, cpad);
	free(s);
	return (tot_len);
}

int	ft_handle_integer(va_list *args, t_format_flags *flags)
{
	int		i;
	char	prefix;
	int		digits;
	char	*s;

	i = va_arg(*args, int);
	prefix = ft_int_set_prefix(i, flags);
	if (i > 0)
	{
		s = ft_itoa(i);
	}
	else
		s = ft_itoa(-i);
	digits = ft_strlen(s);
	return (ft_write_int_flags(s, digits, prefix, flags));
}
