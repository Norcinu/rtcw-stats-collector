#include "parser.h"

char initial_read_buffer[MAX_FILE_SIZE];

int open_file(const char * filename) {
	FILE* file = fopen(filename, "r");
	int i = 0;
	if (file == NULL) {
		printf ("error opening file. %s.\n", filename);
		return FILE_READ_FAIL;
	}
	
	while (fgets(initial_read_buffer, MAX_FILE_SIZE, file) != NULL) {
		printf ("%s\n", initial_read_buffer[i]);
		++i;
	}
	
	return FILE_READ_OK;
}


