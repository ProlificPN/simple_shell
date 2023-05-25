#include "header_shell.h"

/**
 * parse_command - trim a command string into a list of arguments
 * @command: the command string
 * @argv: the array to store the arguments in
 * @argc: the maximum number of arguments
 * Return: the number of arguments
 */
int parse_command(char *command, char **argv, int argc)
{
	int i = 0;
	char *token;

	token = strtok(command, " \t\n");
	while (token != NULL && i < argc)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;

	return (i);
}
