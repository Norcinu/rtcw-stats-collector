#include "parser.h"

char initial_read_buffer[MAX_FILE_SIZE];

int open_file(const char * filename) {
    FILE* file = fopen(filename, "r");
    int i = 0;
    if (file == NULL) {
        printf ("error opening file. %s.\n", filename);
        return FILE_READ_FAIL;
    }
    
    /*fgets(initial_read_buffer, 256, file);
    for (;i<255;i++){
        printf ("%c", initial_read_buffer[i]);
    }*/
    while (fgets(initial_read_buffer, MAX_FILE_SIZE, file) != NULL) {
        for (;i<MAX_FILE_SIZE; i++){
            printf ("%c", initial_read_buffer[i]);
        }
    }

    /*for (;i< MAX_FILE_SIZE-1; i++) {
        printf ("%c", initial_read_buffer[i]);
    }*/
    
    return FILE_READ_OK;
}


