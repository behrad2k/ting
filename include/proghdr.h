#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <header.h>

void gethdrs(FILE *file, Elf64_Ehdr header, Elf64_Phdr out[]);