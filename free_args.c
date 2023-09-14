#include "shell.h"

void free_args(char ***argv)
{
	int i = 0;
	for (i = 0; (*argv)[i] != NULL; i++)
			free((*argv)[i]);
	// free(*argv);
}