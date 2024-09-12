/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:14:33 by ataan             #+#    #+#             */
/*   Updated: 2024/09/11 16:48:30 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

typedef int	(*t_format_func)(va_list *args);

int			ft_handle_char(va_list *args);
int			ft_handle_integer(va_list *args);
int			ft_handle_string(va_list *args);
int			ft_handle_pointer(va_list *args);
int			ft_handle_udecimal(va_list *args);
int			ft_handle_hex(va_list *args);
int			ft_handle_hex_caps(va_list *args);
int			ft_handle_percentage(va_list *args);
int			ft_printf(const char *fmt, ...);
int			ft_putnbr_hex_fd(unsigned long nbr, int caps, int fd);
char		*ft_uitoa(unsigned int n);

#endif
