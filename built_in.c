#include "header_shell.h"
i
/**
 * exit_shell - exits the shell
*/
void exit_shell(void)
{
	exit(EXIT_SUCCESS);
}

/**
 *print_environment - prints the current environment
 *
*/
void print_environment(void)
{
	char **env = environ;
	while (*env)

	{
		printf("%s\n", *env);
		env++;
	}
}


/*

built_in - checks if the command is a built-in and executes it

@argv: the array of arguments to execute

Return: 1 if the command is a built-in, 0 otherwise
*/
int built_in(char **argv)
{
	if (strncmp(argv[0], "exit", 4) == 0)
	{
		exit_shell();
		return (1);
	}
	else if (strncmp(argv[0], "env", 3) == 0)
	{
		print_environment();
		return (1);
	}

	return (0);
}
