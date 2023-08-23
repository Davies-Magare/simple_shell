#include "main.h"

/**
 * tokenize_input - tokenizes the user input
 * @buffer: A string of the command line arguments
 *
 * Return: On success, an array with the user tokenized input
 * On failure, return NULL
 */
char **tokenize_input(char *buffer)
{
	char *token;
	char *delimeter = " \t\n:";
	int size = 120;
	int i;
	char **tokens;

	tokens = (char **)malloc(sizeof(char *) * size);
	token = strtok(buffer, delimeter);
	i = 0;
	while (token != NULL)
	{
		tokens[i++] = strdup(token);
		token = strtok(NULL, delimeter);
	}
	tokens[i] = NULL;
	return (tokens);
}
