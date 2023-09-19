#include "main.h"

/**
 * reverse_string - reverse string
 * @str: ......
 * Return: length
 */
int reverse_string(const char *str)
{
	int length = 0, i;

	while (str[length] != '\0')
	{
		length++;
	}
	for (i = length - 1; i >= 0; i--)
	{
		_write(str[i]);
	}
	return (length);
}

/**
 * rot-13_string - encrypt string in 13 chars rot
 * @str: .....
 * Return: len
 */
int rot13_string(const char *str)
{
	int length = 0;
	char c, base;

	while (str[length] != '\0')
	{
		c = str[length];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			base = (c >= 'a' && c <= 'z') ? 'a' : 'A';
			c = (c - base + 13) % 26 + base;
		}
		_write(c);
		length++;
	}
	return (length);
}
