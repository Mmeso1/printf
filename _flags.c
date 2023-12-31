#include "main.h"
#include <stdio.h>

/**
 * handleFlags - calculates active flags
 * @format: Formatted strings in which to print the arguements
 * @i: take a parameters.
 * Return: flags;
 */

int handleFlags(va_list args, const char *format)
{
	int len = 0, value;
	char flag = *format;
	char value_str[20], specifier;

	switch (flag)
	{
		case '+':
			{
				value = va_arg(args, int);
				if (value >= 0)
				{
					_write('+');
					len++;
				}
				else
				{
					sprintf(value_str, "%d", value);
					len += write_string(value_str);
				}
			}
			break;
		case ' ':
			{
				value = va_arg(args, int);
				if (value >= 0)
				{
					_write(' ');
					len++;
				}
				else
				{
					sprintf(value_str, "%d", value);
					len += write_string(value_str);
				}
			}
			break;
		case '#':
			specifier = *format;
			switch (specifier)
			{
				case 'x':
				case 'X':
					len += handleFlagX(va_arg(args, unsigned int), specifier);
			}
			break;
		default:
			return (-1);
	}
	return (len);
}

/**
 * handleFlagX - handle x and x
 * specifier: ....
 * @value: ...
 * Return: length
 */
int handleFlagX(unsigned int value, char specifier)
{
	int len = 0;
	int digit;

	len++;
	if (specifier == 'x')
	{
		_write('0');
		_write('x');
		len += 2;
	}
	while (value > 0)
	{
		digit = value % 16;
		_write(hex_to_char(digit));
		len++;
		value /= 16;
	}
	return (len);
}

