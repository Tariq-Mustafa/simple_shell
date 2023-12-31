#include "shell.h"

/**
 * interactive - returns true if shell is in interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@c: The character input
 *Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string number to an integer number
 *@s: the string number to be converted
 *Return: 0 if the string is not a number, converted number otherwise
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, result = 0;

	for (i = 0;  *(s + i) != '\0' && flag != -1; i++)
	{
		if (*(s + i) == '-')
			sign *= -1;

		if (*(s + i) >= '0' && *(s + i) <= '9')
		{
			flag = 1;
			result = result * 10 + (*(s + i) - '0');
		}
		else if (flag == 1)
			flag = -1;
	}

	return (sign * result);
}
