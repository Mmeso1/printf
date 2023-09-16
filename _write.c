#include <unistd.h>

/**
 * _write - write to the stdoit
 * @c: the character to ne written to the stdout
 * Return (void)
 */

void _write(char c)
{
	write(STDOUT_FILENO, &c, 1);
}
