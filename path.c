#include "main.h"

/**
 * find_path - searches for the command in PATH
 * @envp: The list of environment variables
 *
 * Return: On success, a pointer to the environment
 * variable, otherwise return NULL
 */
char *find_path(char **envp)
{
	char *path = NULL;
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		if (_strstr(envp[i], "PATH"))
		{
			path = (envp[i] + 5);
			break;
		}
	}
	if (path == NULL)
		return (NULL);
	return (path);
}
