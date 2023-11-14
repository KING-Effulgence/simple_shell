#include "shell.h"

/**
 * display_error - Outputs a custom error message to standard error.
 * @prog_name: Name of the program.
 * @cmd_seq: Command count.
 * @user_cmd: Command entered by the user.
 *
 * Description: This function prints a custom error message to standard error
 *              when a command is not found.
 */
void display_error(char *prog_name, int cmd_seq, char *user_cmd)
{
	output_string(prog_name);
	output_string(": ");
	output_char(cmd_seq + '0');
	output_string(": ");
	output_string(user_cmd);
	output_string(": command not found\n");
}

/**
 * output_string - Prints a string.
 * @txt: The string to be printed.
 *
 * Description: This function prints each
 * character of a string to standard output.
 */
void output_string(char *txt)
{
	while (*txt)
	{
		output_char(*txt++);
	}
}

/**
 * output_char - Prints a character to standard error.
 * @character_to_display: The character to be printed.
 *
 * Description: This function writes a single character to standard error.
 *
 * Return: The number of bytes written.
 */
int output_char(char character_to_display)
{
	return (write(2, &character_to_display, 1));
}

