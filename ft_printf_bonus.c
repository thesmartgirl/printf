/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:14:33 by ataan             #+#    #+#             */
/*   Updated: 2024/09/08 17:26:15 by ataan            ###   ########.fr       */
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
		//format_handlers['p'] = ft_handle_pointer;
		format_handlers['i'] = ft_handle_integer;
		format_handlers['u'] = ft_handle_udecimal;
		format_handlers['x'] = ft_handle_hex;
		format_handlers['X'] = ft_handle_hex_caps;
	  format_handlers['%'] = ft_handle_percentage;
	}
	return (format_handlers);
}

int	ft_printf(const char *fmt, ...)
{
	int				ret;
	va_list			args;
	t_format_func	*format_handlers;
	t_format_func	handler;
	t_format_flags	flags;

	va_start(args, fmt);
	format_handlers = init_format_handlers();
	ret = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			ft_parse_flags(&fmt, &flags);
			//PLZ REMOVE ME
			printf("flag_plus=%d\n", flags.flag_plus);
			printf("flag_space=%d\n", flags.flag_space);
			printf("flag_hash=%d\n", flags.flag_hash);
			printf("flag_zero=%d\n", flags.flag_zero);
			printf("flag_minus=%d\n", flags.flag_minus);
			printf("precision_set=%d\n", flags.precision_set);
			printf("precision=%d\n", flags.precision);
			printf("field_width=%d\n", flags.field_width);
			if (format_handlers[(int)*(fmt)])
			{
				handler = format_handlers[(int)*fmt];
				ret += handler(&args, &flags);
			}
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			ret++;
		}
		fmt++;
	}
	va_end(args);
	return (ret);
}
