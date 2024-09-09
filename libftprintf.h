#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include <stdio.h>

typedef void (*format_func)(va_list *args);

typedef struct {
    int flag_hash;    // #
    int flag_zero;    // 0
    int flag_minus;   // -
    int flag_plus;    // +
    int flag_space;   // (space)
    int field_width;  // Field width (e.g., 5 in "%5d")
    int precision;    // Precision (e.g., 3 in "%.3d")
    int precision_set; // 1 if precision was explicitly set
} format_flags;

#endif
