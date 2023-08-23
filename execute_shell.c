#include "main.h"

/**
 * execute_shell - executes the command
 * @args: An array of tokens
 * @envp: The environment pointer array
 *
 * Return: 1 if the command was found
 * 0 if otherwise
 */
int execute_shell(char **args, char **envp)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		return (0);
	}
	else if (pid == 0)
	{
		if ((execve(args[0], args, envp) == -1))
		return (0);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			global_exit_status = (WEXITSTATUS(status));
	}
	return (1);
}

