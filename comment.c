#include "shell.h"

/**
 * strip_comments - Removes comments from a given input string.
 *
 * Comments, marked by '#', are removed. An unescaped '#' marks the beginning
 * of a comment. Otherwise, it is treated as a regular character.
 *
 * @text: The input string from which comments are to be removed.
 */
void strip_comments(char *text)
{
	int index = 0;

	while (text[index])
	{
		if (index > 0 && text[index] == '#' && text[index - 1] != ' ')
		{
			text[index] = '\0';
			break;
		}
		if (text[index] == '#')
		{
			text[index] = '\0';
			break;
		}
		index++;
	}
}

