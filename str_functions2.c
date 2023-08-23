#include "shell.h"

/**
 * starts_with - checks if needle starts with str
 * @str: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of str or NULL
 */
char *starts_with(const char *str, const char *needle)
{
	while (*needle != '\0')
		if (*needle++ != *str++)
			return (NULL);
	return ((char*)str);
}

/**
 * _strdup - duplicates a string
 * @str: the string to be duplicated
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *dup;

	if (str == NULL)
		return (NULL);
	while (*str++ != '\0')
		length++;
	dup = malloc(sizeof(char) * (length + 1));
	if (dup == NULL)
		return (NULL);
	for (length++; length > 0; length--)
		*(dup + length) = *--str;
	return (dup);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (str == NULL)
		return;
	while (*(str + i) != '\0')
	{
		_putchar(*(str + i));
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to be printed
 *
 * Return: On success 1.
 * On error, -1 is returned, and error is set appropriately by write.
 */
int _putchar(char c)
{
	static int i;
	static char buf[BUF_SIZE];

	if (c == BUF_FLUSH || i >= BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		*(buf + i++) = c;
	return (1);
}
