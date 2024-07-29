#include <header.h>

char header_64_[6];
char header_32_[6];

header universallize(bool bitness, header_32 _32, header_64 _64) {
	header header_;
	if (bitness) {
		header_.bitness = _64.bitness;
		header_.endian = _64.endian;
		header_.version = _64.version;
		header_.osabi = _64.osabi;
		header_.abiversion = _64.abiversion;
		header_.type = _64.type;
		header_.machine = _64.machine;
		header_.phoff_64 = _64.phoff_64; // 64-bit
		header_.shoff_64 = _64.shoff_64; // 64-bit
		header_.flags = _64.flags;
		header_.ehsize = _64.ehsize;
		header_.phentsize = _64.phentsize;
		header_.phnum = _64.phnum;
		header_.shentsize = _64.shentsize;
		header_.shnum = _64.shnum;
		header_.shstrndx = _64.shstrndx;
		header_.valid = _64.valid;
	} else {
		header_.bitness = _32.bitness;
		header_.endian = _32.endian;
		header_.version = _32.version;
		header_.osabi = _32.osabi;
		header_.abiversion = _32.abiversion;
		header_.type = _32.type;
		header_.machine = _32.machine;
		header_.phoff = _32.phoff; // 32-bit
		header_.shoff = _32.shoff; // 32-bit
		header_.flags = _32.flags;
		header_.ehsize = _32.ehsize;
		header_.phentsize = _32.phentsize;
		header_.phnum = _32.phnum;
		header_.shentsize = _32.shentsize;
		header_.shnum = _32.shnum;
		header_.shstrndx = _32.shstrndx;
		header_.valid = _32.valid;
	}
	return header_; // oh god this is horrible
}

header getheader(FILE *file) {
	snprintf(header_64_, 6, "%cELF%c", 0x7f, 0x02);
	char buf[5];
	header fallback;
	fseek(file, 0, SEEK_SET);
	fread(&buf, 1, 5, file);
	fseek(file, 4, SEEK_SET);
	if (memcmp(header_32_, buf, (long unsigned int)5) == 0 || memcmp(header_64_, buf, (long unsigned int)5) == 0) {
		if (buf[4] - 1) {
			header_64 ret;
			header_32 unusable;
			ret.valid = true;
			fread(&ret, sizeof(header), 1, file);
			printf("64 bit\n");
			return universallize(true, unusable, ret);
		} else {
			header_32 ret;
			header_64 unusable;
			ret.valid = true;
			fread(&ret, sizeof(header), 1, file);
			printf("32 bit\n");
			return universallize(false, ret, unusable);
		}
	}
	return fallback;
}