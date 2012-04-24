#include "parser.h"

int open_file(const char * filename) {
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf ("error opening file. %s.\n", filename);
		fclose(
		return FILE_READ_FAIL;
	}
	return FILE_READ_OK;
}
