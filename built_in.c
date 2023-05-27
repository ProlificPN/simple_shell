#include "header_shell.h"
i
/**
 * exit_shell - exits the shell
*/
void exit_shell(void)
{
	exit(0);
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


<<<<<<< HEAD
/*

built_in - checks if the command is a built-in and executes it

@argv: the array of arguments to execute

Return: 1 if the command is a built-in, 0 otherwise
=======
/**
 *built_in - checks if the command is a built-in and executes it
 *@argv: the array of arguments to execute
 *
 *Return: 1 if the command is a built-in, 0 otherwise
>>>>>>> eb8dc0564dba0eb7f0ae20bc7fe5955fbc720a86
*/
int built_in(char **argv)
{
	if (_strncmp(argv[0], "exit", 4) == 0)
	{
		exit_shell();
		return (1);
	}
	else if (_strncmp(argv[0], "env", 3) == 0)
	{
		print_environment();
		return (1);
	}
	else if (_strncmp(argv[0], "cd", 2) == 0)
		return (cd_builtin(argv));

	return (0);
}
