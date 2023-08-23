#include "main.h"

/**
 * full_command - searches for the full command
 * @args: An array of tokens
 * @envp: The environment pointer array
 *
 * Return: 1 if the command was found
 * 0 if otherwise
 */
int full_command(char **args, char **envp)
{
	char *full_path = NULL;
	char *job_path;
	char *path, *cpy_path;

	path = find_path(envp);
	job_path = _strdup(path);
	cpy_path = job_path;
	while (1)
	{
		if (access(args[0], X_OK) == 0)
			break;
		full_path = search_command(args[0], job_path);
		if (full_path == NULL)
		{
			print_error(args[0]);
			free_array(args);
			free(cpy_path);
			return (0);
		}
		free(args[0]);
		args[0] = NULL;
		args[0] = full_path;
		break;
	}
	execute_shell(args, envp);
	free_array(args);
	free(cpy_path);
	return (1);
}

/**
 * free_array - frees an array of pointers
 * @array: An array of pointers
 *
 * Return: Nothing
 */
void free_array(char **array)
{
	int i;

	for (i = 0; array[i] != NULL; i++)
		free(array[i]);
	free(array);
}
