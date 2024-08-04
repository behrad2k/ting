#include <proghdr.h>

proghdr proghdrs[128];

proghdr universallize_proghdr(bool bitness, proghdr_32 _32, proghdr_64 _64) {
	proghdr proghdr_;
	if (bitness) {
		proghdr_.type = _64.type;
		proghdr_.flags = _64.flags_64;
		proghdr_.offset_64 = _64.offset_64;
		proghdr_.vaddr_64 = _64.vaddr_64;
		proghdr_.paddr_64 = _64.paddr_64;
		proghdr_.filesz_64 = _64.filesz_64;
		proghdr_.memsz_64 = _64.memsz_64;
		proghdr_.align_64 = _64.align_64;
	} else {
		proghdr_.type = _32.type;
		proghdr_.flags = _32.flags_32;
		proghdr_.offset = _32.offset;
		proghdr_.vaddr = _32.vaddr;
		proghdr_.paddr = _32.paddr;
		proghdr_.filesz = _32.filesz;
		proghdr_.memsz = _32.memsz;
		proghdr_.align = _32.align;
	}
	return proghdr_; // this is also bad
}

void gethdrs(bool bitness, FILE *file, header _header, proghdr out[]) {
	uint16_t phnum = _header.phnum;
	if (bitness) {
		proghdr_32 unusable;
		uint64_t phoff = _header.phoff_64;
		proghdr_64 cur;
		fseeko(file, phoff, SEEK_SET);
		for (uint16_t i = 0; i <= phnum; i++) {
			fread(&cur, sizeof(cur), 1, file);
			fseek(file, sizeof(cur), SEEK_CUR);
			out[i] = universallize_proghdr(bitness, unusable, cur);
		}
	} else {
		proghdr_64 unusable;
		uint32_t phoff = _header.phoff;
		proghdr_32 cur;
		fseek(file, phoff, SEEK_SET);
		for (uint16_t i = 0; i <= phnum; i++) {
			fread(&cur, sizeof(cur), 1, file);
			fseek(file, sizeof(cur), SEEK_CUR);
			out[i] = universallize_proghdr(bitness, cur, unusable);
		}
	}
}