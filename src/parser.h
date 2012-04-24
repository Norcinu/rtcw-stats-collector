#ifndef SEG_PARSER_H
#define SEG_PARSER_H

#include <stdio.h>
#include <assert.h>

#define MAX_FILE_SIZE 4096
//#define MAX_FILE_SIZE 256
#define FILE_READ_OK 1
#define FILE_READ_FAIL 0

int open_file(const char * filename);
//void read();

#endif

