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
/*
 * cspdiuxX%
 * %c Prints a single character.
 * %s Prints a string (as defined by the common C convention).
 * %p The void * pointer argument has to be printed in hexadecimal format.
 * %d Prints a decimal (base 10) number
 * %i Prints an integer in base 10.
 * %u Prints an unsigned decimal (base 10) number.
 * %x Prints a number in hexadecimal (base 16) lowercase format.
 * %X Prints a number in hexadecimal (base 16) uppercase format.
 * %% Prints a percent sign.
 *
 * Manage any combination of the following flags: ’-0.’ and the field minimum width under all conversions.
 * Manage all the following flags: ’# +’ (Yes, one of them is a space)
 * */

 /*Each conversion specification is introduced by the character %, and ends
  with a conversion specifier. In between there may be (in this order) zero or
	more flags, an optional minimum field width, an optional precision and an
	optional length modifier.*/
	#include <stdio.h>
	#include <stdarg.h>

	typedef void (*format_func)(va_list *args);  // Define the function pointer type

	void handle_integer(va_list *args) {
	    int i = va_arg(*args, int);  // Extract integer from args
	    printf("%d", i);            // Print the integer
	}

	void handle_string(va_list *args) {
	    char *s = va_arg(*args, char *);  // Extract string from args
	    printf("%s", s);                 // Print the string
	}

	void handle_char(va_list *args) {
	    int c = va_arg(*args, int);  // Extract character from args (promoted to int)
	    printf("%c", c);             // Print the character
	}

	format_func* init_format_handlers() {
	    static format_func format_handlers[128] = {NULL};  // Static array of function pointers
	    if (format_handlers['d'] == NULL) {  // Initialize only once
	        format_handlers['d'] = handle_integer;
	        format_handlers['c'] = handle_char;
	        format_handlers['s'] = handle_string;
	    }
	    return format_handlers;  // Return the pointer to the array
	}

	void ft_printf(const char *format, ...) {
	    va_list args;
	    format_func	*format_handlers;	//array of function pointers
			format_func handler; 					//chosen handler
			const char *p;

			va_start(args, format);				// Initialize the va_list
	    format_handlers = init_format_handlers();  // Get the pointer to the handlers
	    p = format;
	    while (*p)
			{
	        if (*p == '%' && format_handlers[(int) *(p + 1)])
					{
	            p++;  // Move past '%'
	            handler = format_handlers[(int) *p];
	            handler(&args);  // Call the handler, passing the va_list
	        }
					else
				 {
	            putchar(*p);  // Print regular characters
	        }
	        p++;
	    }
	    va_end(args);  // Clean up the va_list
	}

	int main() {
	    ft_printf("Hello %s! I have %d apples and %c oranges.\n", "world", 5, 'A');
	    return 0;
	}


/*
int ft_printf(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);

while fmt != NULL
	if fmt != %
		write...
	if fmt == %
		while fmt in (flags, min_field_width, precision, length, conversion)
			parse_conversion_specification
			fmt++
			//after % look for the conversion letter and extract substr


// va_arg(args, int); Retrieve the next argument
//  va_end(args);     Clean up
}
*/
