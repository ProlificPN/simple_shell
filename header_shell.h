#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_COMMAND_LENGTH 1024

extern char **environ;

ssize_t read_command(char **command, size_t *bufsize);
int execute_command(char *command);
void simple_shell(void);
char *search_command(char *name);
void print_env(void);

char *_getenv(const char *name);
int _strlen(const char *s);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, char *src);
char *_strdup(char *s);
int _strncmp(const char *str1, const char *str2, int n);


#endif /* HEADER_H */
