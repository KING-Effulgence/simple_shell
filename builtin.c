#include "shell.h"

/**
 * handle_builtin_commands - Handle execution built-in commands.
 * @args: An array arguments.
 * @name: shell program name (unused in current logic).
 * @buf: Buffer containing command.
 *
 * Return: 1 if a built-in command was executed, 0 otherwise.
 */
int handle_builtin_commands(char **args, char *name, char *buf)
{
	int is_exec = 0;
	int env_index = 0;
	int status = 0; /* Default exit status */

	(void)name;

	if (args[0] == NULL)
	{
		return (is_exec);
	}

	/*check for "exit" command*/
	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1])
		{
			status = atoi(args[1]); /* Convert  to integer */
			if (status < 0)
			{
				write(1, "Invalid exit status\n", 20);
				return (is_exec); /* Continue shell execution */
			}
		}
		free(args);
		free(buf);
		exit(status); /* Exit with provided status, or 0 if none given */
	}
	else if (strcmp(args[0], "env") == 0)
	{
		while (environ[env_index] != NULL)
		{
			write(1, environ[env_index], strlen(environ[env_index]));
			write(1, "\n", 1);
			env_index++;
		}
		free(args);
		is_exec  = 1;
	}
	return (is_exec);
}
