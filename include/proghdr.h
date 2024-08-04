#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <header.h>

typedef struct proghdr_32 {
	uint32_t type;
	uint32_t offset; // 32-bit
	uint32_t vaddr; // 32-bit
	uint32_t paddr; // 32-bit
	uint32_t filesz; // 32-bit
	uint32_t memsz; // 32-bit
	uint32_t flags_32; // 32-bit
	uint32_t align; // 32-bit
} proghdr_32;

typedef struct proghdr_64 {
	uint32_t type;
	uint32_t flags_64; // 64-bit
	uint64_t offset_64; // 64-bit
	uint64_t vaddr_64; // 64-bit
	uint64_t paddr_64; // 64-bit
	uint64_t filesz_64; // 64-bit
	uint64_t memsz_64; // 64-bit
	uint64_t align_64; // 64-bit
} proghdr_64;

typedef struct proghdr {
	uint32_t type;
	uint64_t offset_64; // 64-bit
	uint32_t offset; // 32-bit
	uint64_t vaddr_64; // 64-bit
	uint32_t vaddr; // 32-bit
	uint64_t paddr_64; // 64-bit
	uint32_t paddr; // 32-bit
	uint64_t filesz_64; // 64-bit
	uint32_t filesz; // 32-bit
	uint64_t memsz_64; // 64-bit
	uint32_t memsz; // 32-bit
	uint32_t flags;
	uint64_t align_64; // 64-bit
	uint32_t align; // 32-bit
} proghdr;

proghdr universallize_proghdr(bool bitness, proghdr_32 _32, proghdr_64 _64);
void gethdrs(bool bitness, FILE *file, header _header, proghdr out[]);