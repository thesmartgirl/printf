/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:14:33 by ataan             #+#    #+#             */
/*   Updated: 2024/09/08 17:26:15 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static void	ft_initialize_flags(t_format_flags *flags)
{
	flags->flag_hash = 0;
	flags->flag_zero = 0;
	flags->flag_minus = 0;
	flags->flag_plus = 0;
	flags->flag_space = 0;
	flags->field_width = 0;
	flags->precision = 0;
	flags->precision_set = 0;
}

static void	ft_field_width(const char **format, t_format_flags *flags)
{
	const char	*p = *format;

	while (ft_isdigit(*p))
		p++;
	if (ft_substr(*format, 0, p - *format))
		flags->field_width = ft_atoi(ft_substr(*format, 0, p - *format));
	*format = p;
}

static void	ft_set_precision(const char **format, t_format_flags *flags)
{
	const char	*p = *format;

	if (*p == '.')
	{
		p++;
		if (ft_isdigit(*p))
			flags->precision_set = 1;
		while (ft_isdigit(*p))
			p++;
		if (ft_substr(*format, 1, p - *format - 1))
			flags->precision = ft_atoi(ft_substr(*format, 1, p - *format - 1));
	}
	*format = p;
}

static void	ft_set_flags(const char **format, t_format_flags *flags)
{
	const char	*p = *format;
	while (*p == '#' || *p == '0' || *p == '-' || *p == '+' || *p == ' ')
	{
		if (*p == '#')
			flags->flag_hash = 1;
		if (*p == '0')
			flags->flag_zero = 1;
		if (*p == '-')
			flags->flag_minus = 1;
		if (*p == '+')
			flags->flag_plus = 1;
		if (*p == ' ')
			flags->flag_space = 1;
		p++;
	}
	*format = p;
}

void	ft_parse_flags(const char **format, t_format_flags *flags)
{
	const char	*p = *format;

	ft_initialize_flags(flags);
	ft_set_flags(&p, flags);
	ft_field_width(&p, flags);
	ft_set_precision(&p, flags);
	*format = p;
}
