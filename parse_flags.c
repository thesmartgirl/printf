#include "libftprintf.h"

void	parse_flags(const char **format, format_flags *flags)
{
	const char	*p = *format;

	// Initialize the flags
	flags->flag_hash = 0;
	flags->flag_zero = 0;
	flags->flag_minus = 0;
	flags->flag_plus = 0;
	flags->flag_space = 0;
	flags->field_width = 0;
	flags->precision = 0;
	flags->precision_set = 0;
	// Parse flags
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
	// Parse field width (if any)
	if (*p >= '1' && *p <= '9')
	{
		flags->field_width = atoi(p);
		while (*p >= '0' && *p <= '9')
		{
			p++;
		}
	}
	// Parse precision (if any)
	if (*p == '.')
	{
		p++;
		flags->precision_set = 1; // Mark that precision was explicitly set
		flags->precision = atoi(p);
		while (*p >= '0' && *p <= '9')
		{
			p++;
		}
	}
	*format = p; // Update the format pointer
}
