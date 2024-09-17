/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:14:33 by ataan             #+#    #+#             */
/*   Updated: 2024/09/17 11:41:12 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static t_format_func	*init_format_handlers(void)
{
	static t_format_func	format_handlers[128] = {NULL};

	if (format_handlers['d'] == NULL)
	{
		format_handlers['d'] = ft_handle_integer;
		format_handlers['c'] = ft_handle_char;
		format_handlers['s'] = ft_handle_string;
		format_handlers['p'] = ft_handle_pointer;
		format_handlers['i'] = ft_handle_integer;
		format_handlers['u'] = ft_handle_udecimal;
		format_handlers['x'] = ft_handle_hex;
		format_handlers['X'] = ft_handle_hex_caps;
		format_handlers['%'] = ft_handle_percentage;
	}
	return (format_handlers);
}

static int	ft_parse_and_print(va_list *args, const char *fmt,
		t_format_func *format_handlers)
{
	int				ret;
	t_format_flags	flags;
	t_format_func	handler;

	ret = 0;
	ft_bzero(&flags, sizeof(t_format_flags));
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			ft_parse_flags(&fmt, &flags);
			handler = format_handlers[(int)*fmt];
			if (handler)
				ret += handler(args, &flags);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			ret++;
		}
		fmt++;
	}
	return (ret);
}

int	ft_printf(const char *fmt, ...)
{
	int				ret;
	va_list			args;
	t_format_func	*format_handlers;

	va_start(args, fmt);
	format_handlers = init_format_handlers();
	ret = ft_parse_and_print(&args, fmt, format_handlers);
	va_end(args);
	return (ret);
}
