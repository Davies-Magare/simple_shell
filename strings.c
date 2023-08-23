#include "main.h"

/**
 * _strcpy - copies a string
 * @dest: The buffer to hold the copied string
 * @src: The string to be copied
 *
 * Return: A pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: A string
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

/**
 * _strcat - concantenates two strings
 * @dest: The string to append to
 * @src: The string to append
 *
 * Return: A pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i, len;

	len = 0;
	for (i = 0; dest[i] != '\0'; i++)
		len++;
	for (i = 0; src[i] != '\0'; i++)
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @str1: The first string
 * @str2: The second string
 *
 * Return: 0 if str1 and str2 are equal
 * 1 if str1 is greater that str2
 * Otherwise -1 is returned
 */
int _strcmp(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[1] && str2[i]; i++)
	{
		if (str1[i] != str2[i])
			break;
	}
	if (!str1[i] && !str2[i])
		return (0);
	else if (!str1[i] || !str2[i])
	{
		if (str1[i])
			return (1);
		return (-1);
	}
	if (str1[i] > str2[i])
		return (1);
	else if (str2[i] > str1[i])
		return (-1);
	return (-1);
}
