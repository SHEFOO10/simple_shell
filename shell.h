#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

char *trim_spaces(char *line);

char **command_args(char **cmd_arr, char *full_line);
// int _strlen(char *str);
void free_args(char ***argv);

#endif
