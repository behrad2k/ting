#include <proghdr.h>

Elf64_Phdr proghdrs[128];

void gethdrs(FILE *file, Elf64_Ehdr header, Elf64_Phdr out[]) {
	uint16_t phnum = header.e_phnum;
	uint64_t phoff = header.e_phoff;
	Elf64_Phdr cur;
	printf("%ld\n", phoff);
	if (file == NULL) {
		printf("uh oh");
	}
	fseek(file, phoff, SEEK_SET);
	for (uint16_t i = 0; i <= phnum; i++) {
		printf("loaded proghdr %d\n out of %d\n", i, phnum);
		fread(&cur, sizeof(cur), 1, file);
		fseek(file, sizeof(cur), SEEK_CUR);
		out[i] = cur;
	}
}