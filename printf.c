#include "main.h"
#include <stddef.h>

/**
 * _printf - the _printf function goes in this file
 * @format: the arguments in string quotes
 * Return: length of string
 */

int _printf(const char *format, ...)
{
	int len;
	va_list args;

	if (format == NULL)
	{
		write_string("(null)");
		return (-1);
	}

	va_start(args, format);
	len = process_format_string(format, args);
	va_end(args);
	return (len);
}
