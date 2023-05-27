#include "header_shell.h"

/**
 * get_path - Search for the command in the PATH directories
 * @command: The command to search for
 * Return: The full path to the command, NULL if not found
 */
char *get_path(char *command)
{
	char *path = _getenv("PATH");
	char *command_path = NULL;
	struct stat st;

	if (path != NULL)
	{
		char *path_copy = _strdup(path);
		char *dir = _strtok(path_copy, ":");

		while (dir != NULL)
		{
			size_t pathbuf_size = _strlen(dir) + _strlen(command) + 2;
			char *pathbuf = malloc(pathbuf_size);

			if (pathbuf == NULL)
			{
				free(path_copy);
				return (NULL);
			}

			_strcpy(pathbuf, dir);
			_strcat(pathbuf, "/");
			_strcat(pathbuf, command);

			if (stat(pathbuf, &st) == 0 && S_ISREG(st.st_mode)
					&& (st.st_mode & S_IXUSR))
			{
				command_path = pathbuf;
				break;
			}

			free(pathbuf);
			dir = _strtok(NULL, ":");
		}

		free(path_copy);
	}

	return (command_path);
}
