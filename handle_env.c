#include "shell.h"

/**
 * handle_env - prints environment variables.
 *
 * @env: environment variables.
 *
 * Return: Always (0).
*/
int handle_env(char **env)
{
	int i = 0;

	for (i = 0; env[i] != NULL; i++)
		printf("%s\n", env[i]);
	return (0);
}
