#include "shell.h"

/**
 * display_prompt - Display the shell prompt if in interactive mode.
 *
 * This function prints the shell prompt (a dollar sign '$')
 * to the standard output
 * if the shell is in interactive mode.
 *
 * @mode: Mode of operation (1 for interactive, 0 for non-interactive).
 */
void display_prompt(int mode)
{
	if (mode)
	write(1, "$ ", 2);
}
/**
 * handle_invalid_command - Manage cases where a command is not found.
 *
 * @args: Array of command arguments.
 * @progname: The name of the program.
 * @cmd_count: The count of command execution.
 *
 * Return: An error code (127).
 */
int handle_invalid_command(char **args, char *progname, int cmd_count)
{
	char cmd_count_str = cmd_count + '0';

	display_error(progname, cmd_count_str, args[0]);
	free(args);
	return (127);
}

/**
 * process_shell - Process shell operations and execute commands.
 *
 * @buffer: Input buffer.
 * @argv: Argument values.
 * @count: Command count.
 *
 * Return: Error number.
 */
int process_shell(char *buffer, char **argv, int count)
{
	char **args = NULL;
	char *command_full_path = NULL;

	remove_comment(buffer);

	args = tokenize(buffer);

	if (!args[0])
	{
		free(args);
		return (0);
	}

	if (is_builtin_command(args[0]))
	{
		run_builtin_command(args[0]);
	}
	else
	{
		command_full_path = find_command_path(args[0]);

		if (!command_full_path)
		{
			return (handle_invalid_command(args[0], argv[0], count));
		}

		run_external_command(command_full_path, args);
	}

	return (0);
}
/**
 * main - Entry point for the shell program.
 *
 * @argc: Argument count.
 * @argv: Argument values.
 *
 * Return: Always returns 0.
 */
int main(int argc, char **argv)
{
	int interactive_mode = isatty(0);
	int command_count = 0;
	char *input_buffer = NULL;
	size_t buffer_size = 0;
	ssize_t input_length;

	(void)argc;

	while (1)
	{
		command_count++;
		display_prompt(interactive_mode);

		input_length = getline(&input_buffer, &buffer_size, stdin);

		if (input_length == -1)
		{
			free(input_buffer);
			exit(errno);
		}

		if (process_shell(input_buffer, argv, command_count))
		{
			free(input_buffer);
			exit(127);
		}
	}

	return (0);
}
