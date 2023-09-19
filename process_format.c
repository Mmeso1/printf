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
	const char *ptr = format;
	int result, field_width = 0;
	char flag;

	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			flag = FLAG_NONE;
			while (*ptr == '+' || *ptr == '-' || *ptr == '0' || *ptr == ' ' || *ptr == '#')
			{
				flag |= (*ptr == '+') ? FLAG_PLUS : 0;
				flag |= (*ptr == '-') ? FLAG_MINUS : 0;
				flag |= (*ptr == '0') ? FLAG_ZERO : 0;
				flag |= (*ptr == ' ') ? FLAG_SPACE : 0;
				flag |= (*ptr == '#') ? FLAG_HASH : 0;

				if (flag == 0x01)
				{
					_write('+');
					len++;
				}
				else if (flag == 0x10)
				{
					_write('0');
					_write('x');
					len += 2;
				}
				ptr++;
				while (*ptr >= '0' && *ptr <= '9')
				{
					field_width = field_width * 10 + (*ptr - '0');
					ptr++;
				}
			}
			if (!is_valid_specifier(*ptr))
			{
				_write('%');
				return (len + 1);
			}
			result = process_specifier(*ptr, args);
			if (result == -1)
				return (-1);
			len += result;
			ptr++;
		}
		else
		{
			_write(*ptr);
			len++;
			ptr++;
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
