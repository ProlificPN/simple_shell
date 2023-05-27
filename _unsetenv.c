#include "header_shell.h"

/**
 * unsetenv_builtin - removes an environment variable
 * @args: the arguments to the unsetenv command
 *
 * Return: 1 if the shell should continue running, 0 if it should exit
 */
int unsetenv_builtin(char **args)
{
	if (args[1] == NULL)
	{
		write(STDERR_FILENO, "unsetenv: no variable specified\n", 33);
		return 1;
	}

	char *name = args[1];
	int name_len = strlen(name);
	char **env_ptr = environ;

	while (*env_ptr != NULL)
	{
	if (_strncmp(*env_ptr, name, name_len) == 0 && (*env_ptr)[name_len] == '=')
	{
		char **p = env_ptr;

		do
		{
			*p = *(p + 1);
		} while (*++p != NULL);
		return 1;
		}
		env_ptr++;
	}

	write(STDERR_FILENO, "unsetenv: variable not found\n", 29);
	return 1;
}
