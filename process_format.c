#include "main.h"
#include <stdio.h>

/**
 * process_specifier - to figure out the proper format
 * @specifier: the format specifier
 * @args: the list of args
 * Return: 1 if successful or -1 otherwise
 */
int process_specifier(char specifier, va_list args)
{
	switch (specifier)
	{
		case 'c':
			{
				int c = va_arg(args, int);

				_write((char)c);
				return (1);
			}
		case 's':
			{
				char *s = va_arg(args, char *);

				return (((s != NULL) ? write_string(s) : 0));
			}
		case '%':
			{
				_write('%');
				return (1);
			}
		case 'p':
			{
				void *ptr = va_arg(args, void *);
				char hex_str[19];

				if (snprintf(hex_str, sizeof(hex_str), "0x%016lx",
							(unsigned long)ptr) > 16)
					snprintf(hex_str, sizeof(hex_str), "0x%016lx", (unsigned long)ptr);

				snprintf(hex_str, sizeof(hex_str), "%p", ptr);
				return (write_string(hex_str));
			}
		default:
			if (is_valid_specifier(specifier))
			{
				return (custom_specifier(specifier, args));
			}
			return (-1);
	}
}

/**
 * write_string - to count the length of string arg
 * @s: the string pointer
 * Return: length of string arg
 */
int write_string(const char *s)
{
	int count = 0;

	while (*s)
	{
		_write(*s);
		s++;
		count++;
	}
	return (count);
}

/**
 * process_format_string - puts everything together
 * @format: the specifiers in the double quotes
 * @args: list of args
 * Return: ....
 */
int process_format_string(const char *format, va_list args)
{
    int len = 0;

    while (*format)
    {
        char flag = 0, specifier;
        int field_width = 0, precision = -1, result;
	    
        if (*format != '%')
        {
            _write(*format);
            len++;
            format++;
        }
        else
        {
            format++; 
            while (*format == '+' || *format == '-' || *format == '0' || *format == ' ' || *format == '#')
            {
                if (*format == '+')
                    flag |= FLAG_PLUS;
                else if (*format == '-')
                    flag |= FLAG_MINUS;
                else if (*format == '0')
                    flag |= FLAG_ZERO;
                else if (*format == ' ')
                    flag |= FLAG_SPACE;
                else if (*format == '#')
                    flag |= FLAG_HASH;
                format++;
            }

            if (*format >= '1' && *format <= '9')
            {
                sscanf(format, "%d", &field_width);
                while (*format >= '0' && *format <= '9')
                    format++;
            }

            if (*format == '.')
            {
                format++;
                if (*format >= '0' && *format <= '9')
                {
                    sscanf(format, "%d", &precision);
                    while (*format >= '0' && *format <= '9')
                        format++;
                }
            }

            if (is_valid_specifier(*format))
            {
                specifier = *format;
                result = process_specifier(specifier, args);
                if (result == -1)
                    return (-1);

                len += result;
                format++;
            }
            else
            {
                _write('%');
                format++;
                len++;
            }
        }
    }

    return (len);
}

/**
 * is_valid_specifier - check if it is a valid spec
 * @c: the spec
 * Return: true or false
 */
bool is_valid_specifier(char c)
{
	return (c == 'c' || c == 's' || c == '%'
		|| c == 'b' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'o' || c == 'x' || c == 'X'
		|| c == 'S' || c == 'p' || c == 'r' || c == 'R');
}
