#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void check_elf(unsigned char *ident);
void print_magic(unsigned char *ident);
void print_class(unsigned char class);
void print_data(unsigned char data);
void print_version(unsigned char version);
void print_osabi(unsigned char osabi);
void print_abi(unsigned char *ident);
void print_elf_type(Elf64_Half type);
void print_entry_point(Elf64_Addr entry);
void close_elf(int elf);

/**
 * check_elf - Checks if it is an ELF file.
 * @ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (ident[i] != 127 &&
		    ident[i] != 'E' &&
		    ident[i] != 'L' &&
		    ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *ident)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Print the class of the ELF file
 * @class: The class value from the identification bytes
 */
void print_class(unsigned char class)
{
	printf("  Class:                             ");
	switch (class)
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown>\n");
		break;
	}
}

/**
 * print_data - Print the data encoding of the ELF file
 * @data: The data encoding value from the identification bytes
 */
void print_data(unsigned char data)
{
	printf("  Data:                              ");
	switch (data)
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown>\n");
		break;
	}
}

/**
 * print_version - Print the version of the ELF file
 * @version: The version value from the identification bytes
 */
void print_version(unsigned char version)
{
	printf("  Version:                           %d (current)\n", version);
}

/**
 * print_osabi - Print the OS/ABI of the ELF file
 * @osabi: The OS/ABI value from the identification bytes
 */
void print_osabi(unsigned char osabi)
{
	printf("  OS/ABI:                            ");
	switch (osabi)
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %d>\n", osabi);
		break;
	}
}

/**
 * print_abi - Prints the ABI version of an ELF header.
 * @ident: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *ident)
{
	printf("  ABI Version:                       %d\n",
	       ident[EI_ABIVERSION]);
}

/**
 * print_elf_type - Print the type of the ELF file
 * @type: The type value from the ELF header
 */
void print_elf_type(Elf64_Half type)
{
	printf("  Type:                              ");
	switch (type)
	{
	case ET_NONE:
		printf("NONE (No file type)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown>\n");
		break;
	}
}

/**
 * print_entry_point - Print the entry point address of the ELF file
 * @entry: The entry point value from the ELF header
 */
void print_entry_point(Elf64_Addr entry)
{
	printf("  Entry point address:               0x%lx\n", entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on success, or the appropriate exit code on failure
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident[EI_CLASS]);
	print_data(header->e_ident[EI_DATA]);
	print_version(header->e_ident[EI_VERSION]);
	print_osabi(header->e_ident[EI_OSABI]);
	print_abi(header->e_ident);
	print_elf_type(header->e_type);
	print_entry_point(header->e_entry);

	free(header);
	close_elf(o);
	return (0);
}

