#include "shell.h"

/**
 * run_command - Executes a specified command.
 * @cmd_args: The command to start
 * (commonly the primary element of the user's input arguments).
 * @cmd_argv: Array of command line arguments useful for error notifications.
 *
 * Return: Status of the initiated command or error code.
 */
int run_command(char **cmd_args, char **cmd_argv)
{
	pid_t child_pid;
	int cmd_status;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror(cmd_argv[0]);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(cmd_args[0], cmd_args, environ) == -1)
		{
			perror(cmd_argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&cmd_status);
		if (WIFEXITED(cmd_status))
			cmd_status = WEXITSTATUS(cmd_status);

		errno = cmd_status;

		/* Release memory for the dynamically allocated string array */
		free(cmd_args);
	}

	return (cmd_status);
}

