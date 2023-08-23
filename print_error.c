#include "main.h"

/**
 * print_error - prints error on stderr in case the command is not found
 * @program: The name of the program
 *
 * Return: Nothing
 */
void print_error(char *program)
{
	char *str_prog = "./hsh: 1: ";
	char *end_str = ": not found\n";

	write(2, str_prog, _strlen(str_prog));
	write(2, program, _strlen(program));
	write(2, end_str, _strlen(end_str));
}
