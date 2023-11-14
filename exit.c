#include "shell.h"

/**
 * custom_exit - Exits the shell with a custom status.
 * @args: Array of tokens containing the exit status.
 *
 * Ensures a clean exit from the shell with a custom status if provided.
 *
 * Return: 0 on success, 1 on failure.
 */
int custom_exit(char **args)
{
	int status = 0;

	/* Check if an exit status is provided; validate and set it if so. */
	if (args[1] != NULL)
	{
		if (compare_strings(args[1], "0") == 0)
		{
			status = 0;
		}
		else
		{
			status = atoi(args[1]);
			if (status <= 0)
			{
				write(STDERR_FILENO, "Error: Invalid exit status\n", 27);
				return (1);
			}
		}
	}

	exit(status);
	return (0);
}

