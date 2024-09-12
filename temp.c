int	handle_string(va_list args, format_flags flags)
{
	char	*s;
	int		len;
	int		printed_chars;

	s = va_arg(args, char *);
	len = strlen(s);
	printed_chars = 0;
	if (flags.precision_set && flags.precision < len)
	{
		len = flags.precision;
	}
	if (!flags.flag_minus && flags.field_width > len)
	{
		printed_chars += flags.field_width - len;
		for (int j = 0; j < flags.field_width - len; j++)
		{
			putchar(' ');
		}
	}
	printed_chars += printf("%.*s", len, s);
	if (flags.flag_minus && flags.field_width > len)
	{
		printed_chars += flags.field_width - len;
		for (int j = 0; j < flags.field_width - len; j++)
		{
			putchar(' ');
		}
	}
	return (printed_chars);
}
