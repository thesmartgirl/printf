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
#include "libftprintf_bonus.h"

static void ft_initialize_flags (format_flags *flags)
{
  flags->flag_hash = 0;
  flags->flag_zero = 0;
  flags->flag_minus = 0;
  flags->flag_plus = 0;
  flags->flag_space = 0;
  flags->field_width = 0;
}

void ft_parse_flags(const char **format, format_flags *flags)
{
    const char *p = *format;

    while (*p == '#' || *p == '0' || *p == '-' || *p == '+' || *p == ' ')
    {
        if (*p == '#') flags->flag_hash = 1;
        if (*p == '0') flags->flag_zero = 1;
        if (*p == '-') flags->flag_minus = 1;
        if (*p == '+') flags->flag_plus = 1;
        if (*p == ' ') flags->flag_space = 1;
        p++;
    }
    if (*p >= '1' && *p <= '9')
    {
        flags->field_width = ft_atoi(p);
        while (*p >= '0' && *p <= '9')
        {
            p++;
        }
    }
    *format = p;
}
