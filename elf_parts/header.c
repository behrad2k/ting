#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

Elf64_Ehdr read_elf64_header(FILE *file) {
	Elf64_Ehdr header;
	fread(&header, 1, sizeof(Elf64_Ehdr), file);
	return header;
}