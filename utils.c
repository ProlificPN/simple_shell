#include "header_shell.h"
/**
 * _strdup - function that returns pointer to newly allocated space
 * in memory, which contains a copy of the string given as a parameter.
 * @str: string given as a parameter.
 * Return: NULL if str = NULL and On success returns a pointer to
 * the duplicated string. It returns NULL if insufficient memory was available
 */
char *_strdup(char *str)
{
	char *newstr;
	int len;
	int i;


	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
		len = strlen(str);
		newstr = malloc((sizeof(char) * len) + 1);
		if (newstr == NULL)
		{
			free(newstr);
			return (NULL);
		}
		for (i = 0; i < len; i++)
			newstr[i] = str[i];
		newstr[len] = '\0';
	}
	return  (newstr);
}

/**
 * _strlen - function that returns the length of a string.
 * @s: string.
 * Return: length of a string
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (*s != '\0')
	{
		len++;
		s++;

	}
	return (len);
}

/**
 * _strncmp - function that compares two strings.
 * @str1: first string
 * @str2: second string
 * @n: index
 * Return: return 0 if strings are equal, and -1 if its not.
 */
int _strncmp(const char *str1, const char *str2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] == str2[i])
		{
			continue;
		}
		else
		{
			return (-1);
		}
	}
	return (0);
}

/**
 * _strstr - searches for a substring within a larger string
 * @haystack: the string to search through
 * @needle: the string to search for
 *
 * Return: a pointer to the start of the matching substring,or NULL if no match
 * is found
 */
char *_strstr(const char *haystack, const char *needle)
{
	size_t needle_len = _strlen(needle);

	while (*haystack != '\0')
	{
		if (_strncmp(haystack, needle, needle_len) == 0)
		{
			return ((char *)haystack);
		}
		haystack++;
	}

	return (NULL);
}

/**
 * *_strcpy -  copies the string pointed to by src including the
 * terminating null byte (\0), to the buffer pointed to by dest.
 * @dest: copy to
 * @src: copy from
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		*(dest + i) = *(src + i);
	} while (*(src + i) != '\0');
	return (dest);
}
