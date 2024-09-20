/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:14:33 by ataan             #+#    #+#             */
/*   Updated: 2024/09/17 11:29:44 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

typedef struct s_format_flags
{
	int		flag_hash;
	int		flag_zero;
	int		flag_minus;
	int		flag_plus;
	int		flag_space;
	int		field_width;
	int		precision;
	int		precision_set;
}			t_format_flags;

typedef struct s_to_print
{
	int		digits;
	int		zeros;
	int		pads;
	int		tot_len;
	char	*s;
	char	*prefix;
	char	cpad;
}			t_to_print;

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
int			ft_print_left_adj(t_to_print *nbr_print);
int			ft_print_right_adj(t_to_print *nbr_print);
char		*ft_uitoa(unsigned int n);
char		*ft_hextoa(unsigned int n, int caps);
char		*ft_ptrtoa(uintptr_t ptr);
void		ft_parse_flags(const char **fmt, t_format_flags *flags);
void		ft_calc_content_hex(const unsigned long u, t_format_flags *flags,
				int caps, t_to_print *nbr_print);
void		ft_calc_len_hex(t_format_flags *flags, t_to_print *nbr_print);

#endif
