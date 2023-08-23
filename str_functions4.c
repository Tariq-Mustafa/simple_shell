#include "shell.h"

/**
 **_strncpy - copies a string
 *@arr: the array that will copied str in it
 *@str: the string that needs to be copied
 *@n: the number of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *arr, char *str, int n)
{
	int i;

	i = 0;
	while (*(str + i) != '\0' && i < n - 1)
	{
		*(arr + i) = *(str + i);
		i++;
	}
    	for (; i < n; i++)
    	{
        	*(arr + i) = '\0';
    	}
	return (arr);
}

/**
 **_strncat - concatenates two strings
 *@s1: the first string
 *@s2: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *s1, char *s2, int n)
{
	char *str = s1;

	while (*s1 != '\0')
		s1++;
	while (*s2 != '\0' && n > 0)
	{
		*s1 = *s2;
		s1++;
		s2++;
		n--;
	}
	if (n > 0)
		*s1 = '\0';
	return (str);
}

/**
 **_strchr - locates a character in a string
 *@str: the string to be searched in
 *@c: the character we`re looking for
 *Return: (str) a pointer to the memory area s
 */
char *_strchr(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
