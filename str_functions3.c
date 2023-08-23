#include "shell.h"

/**
 * **strtow - splits a string into words.
 * @str: the string that wanted to be splites
 * @d: the delimeter string
 * Return: a pointer (str2) to an array of strings, or NULL on failure
 */
char **strtow(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **str2;

	if (str == NULL || *str == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; *(str + i) != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;
	if (numwords == 0)
		return (NULL);
	str2 = malloc((1 + numwords) * sizeof(char *));
	if (!str2)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(*(str + i), d))
			i++;
		k = 0;
		while (!is_delim(*(str + i + k), d) && *(str + i + k))
			k++;
		str2[j] = malloc((k + 1) * sizeof(char));
		if (!str2[j])
		{
			for (k = 0; k < j; k++)
				free(str2[k]);
			free(str2);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			str2[j][m] = str[i++];
		str2[j][m] = 0;
	}
	str2[j] = NULL;
	return (str2);
}

/**
 * **strtow2 - splits a string into words
 * @str: the string that wanted to be splites
 * @d: the delimeter
 * Return: a pointer (str2) to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **str2;

	if (str == NULL || *str == 0)
		return (NULL);
	for (i = 0; *(str + i) != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;
	if (numwords == 0)
		return (NULL);
	str2 = malloc((1 + numwords) * sizeof(char *));
	if (!str2)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(*(str + i), d))
			i++;
		k = 0;
		while (!is_delim(*(str + i + k), d) && *(str + i + k))
			k++;
		str2[j] = malloc((k + 1) * sizeof(char));
		if (!str2[j])
		{
			for (k = 0; k < j; k++)
				free(str2[k]);
			free(str2);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			str2[j][m] = str[i++];
		str2[j][m] = 0;
	}
	str2[j] = NULL;
	return (str2);
}
