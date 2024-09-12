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

#ifndef FT_PRINTF_BONUS_H
# define FT_FTPRINTF_BONUS_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct s_format_flags
{
	int	flag_hash;
	int	flag_zero;
	int	flag_minus;
	int	flag_plus;
	int	flag_space;
	int	field_width;
	int	precision;
	int	precision_set;
}		t_format_flags;

typedef int	(*t_format_func)(va_list *args, t_format_flags *flags);

int			ft_handle_char(va_list *args, t_format_flags *flags);
int			ft_handle_string(va_list *args, t_format_flags *flags);
int			ft_handle_pointer(va_list *args, t_format_flags *flags);
int			ft_handle_udecimal(va_list *args, t_format_flags *flags);
int			ft_handle_integer(va_list *args, t_format_flags *flags);
int			ft_printf(const char *fmt, ...);
int			ft_handle_hex(va_list *args, t_format_flags *flags);
int			ft_handle_hex_caps(va_list *args, t_format_flags *flags);
int			ft_putnbr_hex_fd(unsigned long nbr, int caps, int fd);
int			ft_handle_percentage(va_list *args, t_format_flags *flags);
char		*ft_uitoa(unsigned int n);
void		ft_parse_flags(const char **fmt, t_format_flags *flags);

#endif
