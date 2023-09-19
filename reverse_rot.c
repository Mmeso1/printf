#include "main.h"
#include <stdio.h>

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
	char c;

	while (str[length] != '\0')
	{
		c = str[length];
		if (c >= 'a' && c <= 'z')
		{
			c = ((c - 'a' + 13) % 26) + 'a';
		}
		else if (c >= 'A' && c <= 'Z')
		{
			c = ((c - 'A' + 13) % 26) + 'A';
		}
		_write(c);
		length++;
	}
	return (length);
}
