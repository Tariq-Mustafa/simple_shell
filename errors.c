#include "shell.h"

/**
 *_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (str == '\0')
		return;
	while (*(str + i) != '\0')
	{
		_eputchar(*(str + i));
		i++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to be printed
 *
 * Return: On success 1.
 * On error, -1 is returned, and error is set appropriately by write.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[BUF_SIZE];

	if (c == BUF_FLUSH || i >= BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		*(buf + i++) = c;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to be printed
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[BUF_SIZE];

	if (c == BUF_FLUSH || i >= BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		*(buf + i++) = c;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (str == '\0')
		return (0);
	while (*str != '\0')
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}