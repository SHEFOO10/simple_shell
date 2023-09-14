#include "shell.h"

/**
 * free_arr - ...
 *
 * @argv: args to be freed.
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
