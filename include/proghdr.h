#include <stdio.h>
#include <stdint.h>

typedef struct proghdr {
	uint32_t type;
	uint32_t hybrid_32; // flags or 32 offset
	uint64_t offset_64;
	uint32_t 
}

