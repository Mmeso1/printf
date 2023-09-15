#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

int process_specifier(char specifier, va_list args)
{
	switch (specifier)
	{
		case 'c':
			{
				int c = va_arg(args, int);
				write((char)c);
				return (1);
			}
		case 's':
			{
				char *s = var_arg(args, char *);
				return (s != NULL) ? write_string(s) : 0;
			}
		case '%':
			{
				write('%');
				return (0);
			}
		defaut:
			return (-1);
	}
}

int write_string(const char *s)
{
	int count = 0;
	while (*s)
	{
		write(*s);
		s++;
		count++;
	}
	return count;
}

int process_format_string(const char *format, va_list args)
{
	int len = 0;
	const char *ptr = format;

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
			write(*ptr);
			len++;
		}
		ptr++;
	}
	return len;
}
