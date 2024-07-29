#include <stdio.h>
#include <stdint.h>

typedef struct proghdr {
	uint32_t type;
	uint32_t flags_64; // 64-bit
	uint64_t offset_64; // 64-bit
	uint32_t offset; // 32-bit
	uint64_t vaddr_64; // 64-bit
	uint32_t vadder; // 32-bit
	uint64_t paddr_64; // 64-bit
	uint32_t paddr; // 32-bit
	uint64_t filesz_64; // 64-bit
	uint32_t filesz; // 32-bit
	uint64_t memsz_64; // 64-bit
	uint32_t memsz; // 32-bit
	uint32_t flags_32; // 32-bit
	uint64_t align_64; // 64-bit
	uint32_t align; // 32-bit
}

