#include "shell.h"

/**
 * _strlen - returns the length of the string
 * @str: the string whose length has to be checked
 *
 * Return: integer to length of string
 */
int _strlen(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	while (*str++ != NULL)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strings.
 * @str1: the first string
 * @str2: the second string
 *
 * Return: positive if str1 < str2, negative if str1 > str2, zero if str1 == str2
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 != NULL && *str2 != NULL)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * _strcat - concatenates two strings
 * @str1: the first string
 * @str2: the second string
 *
 * Return: pointer to the final string
 */
char *_strcat(char *str1, char *str2)
{
	char *str3 = str1;

	while (*str1 != '\0')
		str1++;
	while (*str2 != '\0')
		*str1++ = *str2++;
	*str1 = '\0';
	return (str3);
}

/**
 * _strcpy - copies a string
 * @arr: the array that will copied str in it
 * @str: the string that needs to be copied
 *
 * Return: pointer to the copied string
 */
char *_strcpy(char *arr, char *str)
{
	int i = 0;

	if (arr == str || str == 0)
		return (arr);
	while (*(str + i))
	{
		*(arr + i) = *(str + i);
		i++;
	}
	*(arr + i) = 0;
	return (arr);
}
