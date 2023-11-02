#include "shell.h"

/**
 * display_prompt - Display shell prompt if it is interactive mode.
 * @mode: Mode of of operation.
 */
void display_promptt(int mode)
{
	if (mode)
		write(1, "$ ", 2);
}

/**
 * manage_invalid_command - Handle when the command is not found.
 * @args: Argumentsof the array.
 * @progname: Program name.
 * @count: Command execution counts.
 *
 * Return: Error number.
 */
int handle_invalid_command(char **args, char *progname, int count)
{
	char cmd_count = count + '0';

	display_error(progname, cmd_count, args[0]);
	free(args);
	return (127);
}

/**
 * process_shell - Process the shell operations and commands
 * @buffer: Input a buffer.
 * @argv: Argument of values.
 * @count: Commmand of count.
 *
 * Return: Error number.
 */
int process_the_shell(char *buffer, char **argv, int count)
{
	char **args = NULL, *command_full_path = NULL;

	remove_comment(buffer);
	args = tokenize(buffer);
	if (!args[0])
	{
		free(args);
		return (0);
	}
	if (access(args[0], X_OK) == -1 &&
			handle_builtin_commands(args, argv[0], buffer) != 1)
	{
		command_full_path = find_cmd_path(fetch_path_env(), args[0]);
		if (!command_full_path)
		{
			return (manage_invalid_command(args, argv[0], count));
		}
		run_full_cmd(args, argv, command_full_path);
		return (0);
	}
	run_command(args, argv);
	return (0);
}


/**
 * main - Main function shell.
 * @argc: Argument of count.
 * @argv: Argument of values.
 *
 * Return: Exit the status.
 */
int main(int argc, char **argv)
{
	int mode = isatty(0), count = 0;
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t num_length;

	(void)argc;
	while (1)
	{
		count++;
		display_prompt(mode);
		num_length = getline(&buffer, &buffer_size, stdin);
		if (num_length == -1)
		{
			free(buffer);
			exit(errno);
		}
		if (process_shell(buffer, argv, count))
		{
			free(buffer);
			exit(127);
		}
	}
	return (0);
}
