#include "main.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * custom_specifier - for those special ones
 * @specifier: the specifier
 * @args: the arguments being passed in here
 * Return: ...
 */

int custom_specifier(char specifier, va_list args)
{
	switch (specifier)
	{
		case 'd':
		case 'i':
			return (handleSignedInt(args, specifier));
		case 'u':
		case 'o':
		case 'x':
		case 'X':
			return (handleUnsignedInt(args, specifier));	
		case 'b':
			{
				unsigned int num = va_arg(args, unsigned int);
				int len = 0;
				int bit;

				while (num > 0)
				{
					bit = num % 2;
					_write(bit + '0');
					num /= 2;
					len++;
				}
				return (len);
			}
		default:
			return (-1);
	}
}

/**
 * get_format_string - to get the format specifiers
 * @specifier: the specifier character
 * Return: a pointer to the function
 */
const char *get_format_string(char specifier)
{
	switch (specifier)
	{
		case 'd':
		case 'i':
			return ("%d");

		case 'u':
			return ("%u");

		case 'o':
			return ("%o");

		case 'x':
			return ("%x");

		case 'X':
			return ("%X");
		default:
			return (NULL);
	}
}

/**
 * handleSignedInt - handle sint
 * @args: the arg list
 * @specifier: the format specifier
 * Return: the length of the args
 */
int handleSignedInt(va_list args, char specifier)
{
	int num = va_arg(args, int), temp, len, written_len;
	char *num_str;
	const char *format;

	len = 0;
	if (num < 0)
	{
		_write('-');
		num = -num;
		len++;
	}

	temp = num;

	do {
		temp /= 10;
		len++;
	} while (temp != 0);

	num_str = (char *)malloc((len + 1) * sizeof(char));

	if (num_str == NULL)
	{
		return (-1);
	}

	format = get_format_string(specifier);
	snprintf(num_str, len + 1, format, num);
	written_len = write_string(num_str);
	free(num_str);

	return (written_len);
}

/**
 * handleUnsignedInt - to handle the printing of uint
 * @args: the list of args in the quotes
 * @specifier: the format specifier characters
 * Return: the length of args
 */
int handleUnsignedInt(va_list args, char specifier)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int len = 1;
	unsigned int temp = num;
	char *num_str;
	const char *format;
	unsigned int written_len;

	do {
		temp /= 10;
		len++;
	} while (temp != 0);

	num_str = (char *)malloc((len + 1) * sizeof(char));
	if (num_str == NULL)
	{
		return (-1);
	}

	format = get_format_string(specifier);
	snprintf(num_str, len + 1, format, num);

	written_len = write_string(num_str);
	free(num_str);

	return (written_len);
}

