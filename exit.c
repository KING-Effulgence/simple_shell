#include "shell.h"

/**
 * validate_exit_status - Validates the provided exit status.
 * @status_str: String containing the exit status.
 *
 * Return: Validated exit status or -1 on failure.
 */
int validate_exit_status(char *status_str)
{
	if (compare_strings(status_str, "0") == 0)
		return (0);

	int status = atoi(status_str);

	if (status <= 0)
	{
		write(STDERR_FILENO, "Invalid exit status\n", 20);
		return (-1);
	}

	return (status);
}

/**
 * custom_exit - Exits the shell with a custom exit status.
 * @exit_status: Exit status to be used.
 *
 * Description: Exits the shell with the specified exit status.
 */
void custom_exit(int exit_status)
{
	exit(exit_status);
}

/**
 * main - Main function for the shell program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: 0 on success, non-zero on failure.
 *
 * Description: Handles command-line arguments and exits the shell with a
 * custom exit status.
 */
int main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(STDERR_FILENO, "Usage: %s exit_status\n", argv[0]);
		return (1);
	}

	int exit_status = validate_exit_status(argv[1]);

	if (exit_status == -1)
		return (1);

	custom_exit(exit_status);

	return (0);
}

