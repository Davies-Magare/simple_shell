#include "main.h"

/**
 * execute_shell - executes the command
 * @args: An array of tokens
 * @envp: The environment pointer array
 *
 * Return: 1 if the command was found
 * 0 if otherwise
 */
void execute_shell(char **args, char **envp)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(args[0], args, envp);
		perror(args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			global_exit_status = (WEXITSTATUS(status));
	}
}

