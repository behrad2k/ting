#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
#include <arch.h>
#include <header.h>
#include <proghdr.h>

int main(int argc, char *argv[]) {
	int opt;
	int bitness = 64;
	char *filename = NULL;
	char *arch_arg = "x86";
	FILE *a = NULL;

	static struct option long_options[] = {
		{"arch", required_argument, NULL, 'a'},
		{"bits", required_argument, NULL, 'b'},
		{"help", no_argument, NULL, 'h'},
		{NULL, 0, NULL, 0}
	};

	while ((opt = getopt_long(argc, argv, "b:a:h", long_options, NULL)) != -1) {
		switch (opt) {
			case 'a':
				arch_arg = optarg;
				break;
			case 'b':
				bitness = atoi(optarg);
				if (bitness != 64 && bitness != 32) {
					printf("invalid bitness\n");
					return 1;
				}
				break;
			case 'h':
				fprintf(stderr, "usage: %s filename [--arch arch][--bits 32||64]\n--arch: forces arch\n--bits: forces bits\n", argv[0]);
				exit(EXIT_SUCCESS);
			default:
				fprintf(stderr, "usage: %s filename [--arch arch][--bits 32||64]\n--arch: forces arch\n--bits: forces bits\n", argv[0]);
				exit(EXIT_FAILURE);
		}
	}

	if (optind < argc) {
		filename = argv[optind];
	} else {
		fprintf(stderr, "filename is required.\n");
		exit(EXIT_FAILURE);
	}

	a = fopen(filename, "r");
	if (a == NULL) {
		printf("broken");
		switch (errno) {
			case (EACCES): {
				printf("no access\n");
				return 1;
			}
			case (ENOENT): {
				printf("doesnt exist\n");
				return 1;
			}
		}
	}
	
	Elf64_Ehdr h = read_elf64_header(a);
	Elf64_Phdr hdrs[128];
	gethdrs(a, h, hdrs);

	printf("full arch: %s\n", getarch(h.e_ident[EI_CLASS] == 2 || bitness == 64, arch_arg, (strcmp(arch_arg, "aarch") != 0)));


	return 0;
}
