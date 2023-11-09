#include "shell.h"

/**
 * execute_command - Execute a specified command with arguments.
 * @command: The command to execute.
 * @arguments: The arguments for the command.
 *
 * Return: Status of the executed command or an error code.
 */
int execute_command(const char *command, char **arguments)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid < 0)
	{
	perror(command);
	exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(command, arguments, environ);
		perror(command);
		exit(EXIT_FAILURE);
	}
	else
	{
	wait(&status);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);

	errno = status;
	}

	return (status);
}
