#include "main.h"

/**
 * create_file - Creates a file with the given filename and writes the
 *               specified text content into it
 * @filename: The name of the file to create
 * @text_content: The text content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
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

	fichier = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fichier == -1)
		return (-1);

	write(fichier, text_content, j);

	return (1);
}
