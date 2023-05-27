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

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string to concatenate to dest
 *
 * Return: A pointer to dest
 */
char *_strcat(char *dest, const char *src)
{
	size_t dest_len = _strlen(dest);
	size_t src_len = _strlen(src);
	size_t i;

	for (i = 0; i < src_len; i++)
	{
		dest[dest_len + i] = src[i];
	}

	dest[dest_len + src_len] = '\0';

	return dest;
}


/**
 * _strtok - splits a string into tokens using a specified delimiter
 * @str: the string to split
 * @delim: the delimiter to use
 *
 * Return: a pointer to the next token, or NULL if there are no more tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *last_token = NULL;
	char *token = NULL;
	size_t token_len = 0;
	size_t delim_len = _strlen(delim);

	if (str != NULL)
		last_token = str;
	if (last_token == NULL)
		return NULL;

	token = strstr(last_token, delim);

	if (token != NULL)
	{
		token_len = token - last_token;
		token = last_token;
		last_token = token + token_len + delim_len;
		token[token_len] = '\0';
		return token;
	}

	token = last_token;
	last_token = NULL;
	if (strlen(token) > 0) {
		token_len = strlen(token);
		token[token_len] = '\0';
		return token;
	}
	return NULL;
}
