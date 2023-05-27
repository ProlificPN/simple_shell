#include "header_shell.h"

/**
 * cd_builtin - changes the current directory of the process
 * @args: the arguments to the cd command
 *
 * Return: 1 if the shell should continue running, 0 if it should exit
 */
int cd_builtin(char **args)
{
	char *dir = args[1];
	char cwd[MAX_PATH_LENGTH];

	if (dir == NULL)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
		{
			printf("cd: no home directory\n");
			return (1);
		}
	}
	else if (strncmp(dir, "-", 1) == 0)
	{
		dir = _getenv("OLDPWD");
		if (dir == NULL)
		{
			printf("cd: no previous directory\n");
			return (1);
		}
		printf("%s\n", dir);
	}

	if (chdir(dir) == -1)
	{
		printf("cd: %s: No such file or directory\n", dir);
		return (1);
	}

	if (getcwd(cwd, MAX_PATH_LENGTH) == NULL)
	{
		perror("cd");
		return (1);
	}

	setenv("OLDPWD", _getenv("PWD"), 1);
	setenv("PWD", cwd, 1);

	return (1);
}
