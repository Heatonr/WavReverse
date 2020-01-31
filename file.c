#include "file.h"
#include <stdio.h>
#include <stdlib.h>

size_t read_file( char* filename, char **buffer ){
	FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Can't open file");
    }
	fseek(fp, 0, SEEK_END);
	int file_size = ftell(fp);
	*buffer = (char*)malloc(file_size * sizeof(char));
	rewind(fp);

	//The following code was inspired by https://stackoverflow.com/questions/2029103/correct-way-to-read-a-text-file-into-a-buffer-in-c
	if( fp != NULL ){
		fread(*buffer, 1, file_size, fp);
		if( ferror( fp ) != 0) {
			fputs("Error reading file", stderr);
		}
		fclose(fp);
	}

	return 0;
}

size_t write_file( char* filename, char *buffer, size_t size ){
    FILE* fp = fopen(filename, "wb");

    if( fp != NULL ){
		fwrite(buffer, sizeof(char), size, fp);
		if( ferror( fp ) != 0) {
			fputs("Error reading file", stderr);
		}
		fclose(fp);
	}

	return 0;
}
