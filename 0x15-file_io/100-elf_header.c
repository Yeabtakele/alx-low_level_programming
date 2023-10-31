#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 1024

/**
 * display_elf_header - Display the ELF header information
 * @filename: The name of the ELF file
 */
void display_elf_header(char *filename);

/**
 * print_error_and_exit - Print error message and exit with status code 98
 * @error_message: The error message to be printed
 */
void print_error_and_exit(const char *error_message);

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_error_and_exit("Usage: elf_header elf_filename");
	}

	display_elf_header(argv[1]);

	return (0);
}

/**
 * display_elf_header - Display the ELF header information
 * @filename: The name of the ELF file
 */
void display_elf_header(char *filename)
{
	int fd, i;
	ssize_t bytes_read;
	Elf64_Ehdr elf_header;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error_and_exit(strerror(errno));
	}

	bytes_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));
	if (bytes_read == -1)
	{
		print_error_and_exit(strerror(errno));
	}

	if (bytes_read != sizeof(Elf64_Ehdr) || memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		print_error_and_exit("Not an ELF file");
	}

	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", elf_header.e_ident[i]);
	}
	printf("\n");

	printf("Class:   %s\n", elf_header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
	printf("Data:    %s\n", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("Version: %d\n", elf_header.e_ident[EI_VERSION]);

	printf("OS/ABI:  ");
	switch (elf_header.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX System V ABI\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX ABI\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD ABI\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux ABI\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris ABI\n");
			break;
		case ELFOSABI_IRIX:
			printf("IRIX ABI\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD ABI\n");
			break;
		case ELFOSABI_TRU64:
			printf("TRU64 UNIX ABI\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM architecture ABI\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded) ABI\n");
			break;
		default:
			printf("Unknown ABI\n");
			break;
	}

	printf("ABI Version: %d\n", elf_header.e_ident[EI_ABIVERSION]);

	printf("Type:    ");
	switch (elf_header.e_type)
	{
		case ET_NONE:
			printf("None\n");
			break;
		case ET_REL:
			printf("Relocatable file\n");
			break;
		case ET_EXEC:
			printf("Executable file\n");
			break;
		case ET_DYN:
			printf("Shared object file\n");
			break;
		case ET_CORE:
			printf("Core file\n");
			break;
		default:
			printf("Unknown type\n");
			break;
	}

	printf("Entry point address: 0x%lx\n", (unsigned long)elf_header.e_entry);

	close(fd);
}

/**
 * print_error_and_exit - Print error message and exit with status code 98
 * @error_message: The error message to be printed
 */
void print_error_and_exit(const char *error_message)
{
	fprintf(stderr, "Error: %s\n", error_message);
	exit(98);
}

