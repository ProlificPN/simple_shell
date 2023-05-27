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
#include <signal.h>
#include <fcntl.h>
#include <stdarg.h>
#include <limits.h>



#define MAX_COMMAND_LENGTH 1024
#define BUFFER_SIZE 1024
#define MAX_PATH_LENGTH 1024

extern char **environ;

ssize_t read_command(char **command, size_t *bufsize);
void execute_command(char **argv);
int parse_command(char *command, char **argv, int argc);
void simple_shell(void);
char *get_path(char *command);
void print_env(void);
void prompt(void);
int built_in(char **argv);
int cd_builtin(char **args);
ssize_t read_command2(char **command, size_t *bufsize);


char *_getenv(const char *name);
size_t _strlen(const char *s);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, char *src);
char *_strdup(char *s);
int _strncmp(const char *str1, const char *str2, int n);
char *_strcat(char *dest, const char *src);
char *_getline(void);
char *_strtok(char *str, const char *delim);

char *_strstr(const char *haystack, const char *needle);
#endif /* HEADER_H */
