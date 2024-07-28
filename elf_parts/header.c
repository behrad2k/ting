#include <header.h>

char header_64[6];
char header_32[6];

header getheader(FILE *file) {
	snprintf(header_64, 6, "%cELF%c", 0x7f, 0x02);
	char buf[5];
	header ret;
	fseek(file, 0, SEEK_SET);
	fread(&buf, 1, 5, file);
	fseek(file, 4, SEEK_SET);
	if (memcmp(header_32, buf, (long unsigned int)5) == 0 || memcmp(header_64, buf, (long unsigned int)5) == 0) {
		ret.valid = true;
		if (buf[4] - 1) {
			printf("64 bit\n");
		} else {
			printf("32 bit\n");
		}
	}
	fread(&ret, sizeof(header), 1, file);
	return ret;
}