#include "main.h"

/**
 * main - The simple shell driver function
 * @argc: The argument count to main
 * @argv: An array of string arguments to main
 * @envp: An array of environment variables
 *
 * Return: Always 0 (Success)
 */
int main(int __attribute__((unused)) argc, char __attribute__((unused)) *argv[], char **envp)
{
	ssize_t getline_ret;
	char *buffer = NULL, *prompt = "$ ", *cpy_buf;
	size_t size;
	char **args;
	int mode = isatty(0);

	while (1)
	{
		if (mode == 1)
			write(1, prompt, strlen(prompt));
		getline_ret = getline(&buffer, &size, stdin);
		if (getline_ret == -1)
		{
			free(buffer);
			exit(global_exit_status);
		}
		cpy_buf = check_buffer(buffer);
		if (cpy_buf[0] == '\n')
			continue;
		args = tokenize_input(cpy_buf);
		if (_strcmp(args[0], "env") == 0)
		{
			print_env(envp);
			free_array(args);
			continue;
		}
		if (_strcmp(args[0], "exit") == 0)
		{
			free(buffer);
			free_array(args);
			exit(global_exit_status);
		}
		full_command(args, envp);
	}
	free(buffer);
	exit(global_exit_status);
	return (0);
}

/**
 * check_buffer - locates the first non_space character in input
 * @buffer: The user input buffer
 *
 * Return: A pointer to the first non space character
 */
char *check_buffer(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
		if (buffer[i] != ' ')
			break;
	if (buffer[i] == '\0')
		return (NULL);
	return (buffer + i);
}

/**
 * print_env - prints the environment
 * @envp: An array of environment variables
 *
 * Return: Nothing
 */
void print_env(char **envp)
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
		printf("%s\n", envp[i]);
}


