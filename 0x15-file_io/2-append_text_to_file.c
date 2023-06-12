#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: The name of the file
 * @text_content: The text to append
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int j = 0, fichier;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		text_content = "";


	while (text_content[j] != '\0')
	{
		j++;
	}

	fichier = open(filename, O_WRONLY | O_APPEND);

	if (fichier == -1)
		return (-1);

	write(fichier, text_content, j);

	return (1);
}
