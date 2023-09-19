#include "main.h"
#include <stddef.h>

/**
 * handleCustomS - to handle non printable characters
 * @args: the args
 * Return: 1 on success or -1 otherwise
 */

int handleCustomS(va_list args)
{
	const char *s = va_arg(args, const char *);
	int len = 0, i;

	if (s != NULL)
	{
		for (i = 0; s[i]; i++)
		{
			if (s[i] >= 32 && s[i] < 127)
			{
				_write(s[i]);
				len++;
			}
			else
			{
				_write('\\');
				_write('x');
				_write(hex_to_char(s[i] >> 4));
				_write(hex_to_char(s[i] & 0xF));
				len += 4;
			}
		}
	}
	else
	{
		_write('(');
		_write('n');
		_write('u');
		_write('l');
		_write('l');
		_write(')');
		len += 6;
	}
	return (len);
}

/**
 * hex_to_char - to convert a hex to a char
 * @value: the arg passed to it
 * Return: the arg when converted to a char
 */

char hex_to_char(int value)
{
	return ((value >= 0 && value <= 9) ? '0' +
		value : (value >= 10 && value <= 15) ? 'A' +
		(value - 10) : '?');
}
