#include "header_shell.h"

/**
 * search_command - searches for a command in the PATH environment variable
 * @name: the name of the command to search for
 * Return: the full path of the command, or NULL if not found
 */
char *search_command(char *name)
{
	char *path = _getenv("PATH");
	char *dir;
	char *cmd;
	int len;
	struct stat st;

	dir = strtok(path, ":");
	while (dir != NULL)
	{
		len = _strlen(dir) + _strlen(name) + 2;
		cmd = malloc(len);
		if (cmd == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		_strcpy(cmd, dir);
		_strncat(cmd, "/", len - _strlen(cmd) - 1);
		_strncat(cmd, name, len - _strlen(cmd) - 1);
		if (access(cmd, F_OK) == 0 && stat(cmd, &st) == 0 && S_ISREG(st.st_mode))
		{
			free(cmd);
			return (_strdup(cmd));
		}
		free(cmd);
		dir = strtok(NULL, ":");
	}
	free(cmd);
	return (NULL);
}
