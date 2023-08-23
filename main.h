#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#define BUFSIZE 1024
void execute_shell(char **args, char **envp);
char **tokenize_input(char *buffer);
char *check_buffer(char *buffer);
int full_command(char **args, char **envp);
void free_array(char **array);
int global_exit_status;
char *find_path(char **envp);
char *search_command(char *command, char *path);
void print_env(char **envp);
void print_error(char *program);
char *_strcpy(char *dest, char *src);
char *_strstr(char *haystack, char *needle);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strdup(char *str);

#endif
