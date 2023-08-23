#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: The string to scan for substring
 * @needle: The substring to search in haystack
 *
 * Return: A pointer to the substring. Otherwise
 * return NULL
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j, k;

	if (!*needle)
		return (haystack);
	else if (!*haystack)
		return (NULL);
	for (i = 0; haystack[i]; i++)
	{
		if (haystack[i] != *needle)
			continue;
		for (k = i, j = 0; j < _strlen(needle) && haystack[k] &&
				haystack[k] == needle[j]; k++, j++)
		{
			;
		}
		if (j == _strlen(needle))
			return (&haystack[i]);
	}
	return (NULL);
}


/**
 * _strdup - returns a pointer to a dynamically allocated copy
 * of a string
 * @str: The string to copy
 *
 * Return: On success, a pointer to the duplicated string in memory
 * Otherwise NULL is returned
 */

char *_strdup(char *str)
{
	char  *strp;

	if (str == NULL)
		return (NULL);
	strp = malloc(_strlen(str) + 1);
	if (strp == NULL)
		return (NULL);
	_strcpy(strp, str);
	return (strp);
}
