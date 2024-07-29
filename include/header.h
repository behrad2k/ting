#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct header_32 { 
	uint8_t bitness;
	uint8_t endian;
	uint8_t version;
	uint8_t osabi;
	uint8_t abiversion;
	uint16_t type;
	uint16_t machine;
	uint32_t phoff; // 32-bit
	uint32_t shoff; // 32-bit
	uint32_t flags;
	uint16_t ehsize;
	uint16_t phentsize;
	uint16_t phnum;
	uint16_t shentsize;
	uint16_t shnum;
	uint16_t shstrndx;
	bool valid;
} header_32;

typedef struct header_64 { 
	uint8_t bitness;
	uint8_t endian;
	uint8_t version;
	uint8_t osabi;
	uint8_t abiversion;
	uint16_t type;
	uint16_t machine;
	uint64_t phoff_64; // 64-bit
	uint64_t shoff_64; // 64-bit
	uint32_t flags;
	uint16_t ehsize;
	uint16_t phentsize;
	uint16_t phnum;
	uint16_t shentsize;
	uint16_t shnum;
	uint16_t shstrndx;
	bool valid;
} header_64;


typedef struct header { 
	uint8_t bitness;
	uint8_t endian;
	uint8_t version;
	uint8_t osabi;
	uint8_t abiversion;
	uint16_t type;
	uint16_t machine;
	uint64_t phoff_64; // 64-bit
	uint64_t shoff_64; // 64-bit
	uint32_t phoff; // 32-bit
	uint32_t shoff; // 32-bit
	uint32_t flags;
	uint16_t ehsize;
	uint16_t phentsize;
	uint16_t phnum;
	uint16_t shentsize;
	uint16_t shnum;
	uint16_t shstrndx;
	bool valid;
} header;

header getheader(FILE *file);
header universallize(bool bitness, header_32 _32, header_64 _64);