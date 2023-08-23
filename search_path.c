#include "main.h"

/**
 * search_command - searches the path for a command
 * @command: A command
 * @path: The environment PATH variable pointer
 *
 * Return: If successful, the path to the command
 * Otherwise, return NULL
 */
char *search_command(char *command, char *path)
{
	char *search_path = NULL;
	char *path_tok;
	struct stat st;
	int len;

	path_tok = strtok(path, ":");
	len = _strlen(path_tok) + _strlen(command) + 2;
	while(path_tok != NULL)
	{
		search_path = (char *)malloc(len);
		if (search_path == NULL)
			return (NULL);
		_strcpy(search_path, path_tok);
		_strcat(search_path, "/");
		_strcat(search_path, command);
		if ((stat(search_path, &st) == 0))
			break;
		free(search_path);
		search_path = NULL;
		path_tok = strtok(NULL, ":");
	}
	if (search_path != NULL)
	{
		printf("%s\n", search_path);
		return (search_path);
	}
	return (NULL);
}

