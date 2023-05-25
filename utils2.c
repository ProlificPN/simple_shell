#include "header_shell.h"
/**
 * _getenv - function that searches  the environment list to
  * find the environment variable name, and returns a pointer to
  * the corresponding value string.
 * @name: the environment variable name.
 * Return: a pointer to the corresponding value string.
 */
char *_getenv(const char *name)
{
	char **env;
	int len = _strlen(name);

	for (env = environ; *env != NULL; ++env)
	{
		if (_strncmp(*env, name, len) == 0)
			return (&(*env)[len + 1]);
	}
	return (NULL);
}
