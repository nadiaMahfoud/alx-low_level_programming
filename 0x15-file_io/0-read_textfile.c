#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: The name of the file to read
 * @letters: The number of letters to read and print
 *
 * Return: The actual number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *bf;
	ssize_t o, r, w;

	if (filename == NULL)
		return (0);

	bf = malloc(sizeof(char) * letters);
	if (bf == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	r = read(o, bf, letters);
	w = write(STDOUT_FILENO, bf, r);

	if (o == -1 || r == -1 || w == -1 || w != r)
	{
		free(bf);
		return (0);
	}

	free(bf);
	close(o);

	return (w);
}
