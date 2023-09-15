#include "shell.h"

/**
 * free_arr - ...
 *
 * @argv: arr to be freed.
 *
*/
void free_arr(char ***argv)
{
	int i = 0;
	char **arr = *argv;

	for (i = 0; (*argv)[i] != NULL; i++)
		free((*argv)[i]);
	free(arr);
}


/**
 * free_args - args to be freed.
 *
 * @argv: args.
 * @command: the command itself.
*/

void free_args(char ***argv, char *command)
{
	free_arr(argv);
	free(command);
}
