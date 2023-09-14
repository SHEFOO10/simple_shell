#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


/* excute_program.c */
int excute_program(char **args, char **env);

/* handle_path.c */
int _path(char **command_arr, char **env);
char *getpath(char **env);

/* string_functions.c */
char *trim_spaces(char *line);
char **command_args(char **cmd_arr, char *full_line);
char *concat_command(char *command, char *directory);

/* free_args.c */
void free_args(char ***argv);

#endif
