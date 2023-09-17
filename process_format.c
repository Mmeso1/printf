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
	int result;

	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;

			if (!is_valid_specifier(*ptr))
			{
				return (len);
			}

			result = process_specifier(*ptr, args);
			if (result == -1)
			{
				return (len);
			}

			len += result;
		}
		else
		{
			_write(*ptr);
			len++;
		}
		ptr++;
	}
	return (len);
}

/**
 * is_valid_speifier - check if it is a valid spec
 * @c: the spec
 * Return: true or false
 */
bool is_valid_specifier(char c)
{
	return (c == 'c' || c == 's' || c == '%'
		|| c == 'b' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'o' || c == 'x' || c == 'X'
		|| c == 'S');
}
