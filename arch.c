#include <arch.h>

char *getarch(bool bit, char *arch_branch, bool force_aarch) {
	
	if (strcmp(arch_branch, "x86") == 0) {
		if (bit) {
			return "x86_64";
		} else {
			return "x86";
		}
	}
	else if (strcmp(arch_branch, "arm") == 0 || strcmp(arch_branch, "aarch") == 0) {
		if (bit) {
			return "aarch64";
		} else if (!force_aarch){
			return "arm32";
		} else {
			return "aarch32";
		}
	} else {
		return "broken";
	}

}