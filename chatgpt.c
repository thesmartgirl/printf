int handle_integer(va_list args, format_flags flags) {
    int i = va_arg(args, int);
    int printed_chars = 0;
    int num_digits = 0;
    char buffer[100];  // Temporary buffer to store the number

    // Convert integer to string and count digits
    num_digits = sprintf(buffer, "%d", i);

    // Handle precision (add leading zeros if necessary)
    if (flags.precision_set && flags.precision > num_digits) {
        printed_chars += flags.precision - num_digits;
        for (int j = 0; j < flags.precision - num_digits; j++) {
            putchar('0');
        }
    }

    // Handle the '+' flag (for positive numbers)
    if (flags.flag_plus && i >= 0) {
        printed_chars += printf("+");
    }

    // Handle field width and left-padding (if not left-aligned with '-')
    if (!flags.flag_minus && flags.field_width > num_digits) {
        printed_chars += flags.field_width - num_digits;
        for (int j = 0; j < flags.field_width - num_digits; j++) {
            putchar(flags.flag_zero ? '0' : ' ');
        }
    }

    // Print the actual number
    printed_chars += printf("%s", buffer);

    // Handle right-padding if left-aligned
    if (flags.flag_minus && flags.field_width > num_digits) {
        printed_chars += flags.field_width - num_digits;
        for (int j = 0; j < flags.field_width - num_digits; j++) {
            putchar(' ');
        }
    }

    return printed_chars;  // Return the number of characters printed
}
