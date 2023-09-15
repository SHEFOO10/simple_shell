#include "shell.h"

/**
 * __exit - handle exit
 *
 * @status_code: code returned after exit.
 * @command: for the error.
 * Return: .......
*/

int __exit(char *status_code, char *command)
{
	int code = atoi(status_code);

	if (code < 0)
	{
		fprintf(stderr, "./hsh: 1: %s: Illegal number: %d\n", command, code);
		return (2);
	}
	if (status_code[0] <= '0' || status_code[0] >= '9')
	{
		fprintf(stderr, "./hsh: 1: %s: Illegal number: %s\n", command, status_code);
		return (2);
	}
	return (code);
}
