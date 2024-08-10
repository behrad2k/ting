#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <elf.h>

#pragma once

Elf64_Ehdr read_elf64_header(FILE *file);