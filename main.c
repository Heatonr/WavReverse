#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "file.h"
#include "wav.h"

int main(int argc, char** argv){
    if(argc != 3){
        printf("Exiting due to invalid arguments. WavReverse requires exactly two inputs: writefile and readfile.\n"
               "WavReverse was provided with %d inputs.\n", argc - 1);
        exit(EINVAL); // Exiting with invalid argument code
    }

	char* buffer;
    wav_file* wav;

	read_file(argv[1], &buffer);
	wav = parse(buffer);
    char output[wav->size_of_data];

    printf("File: %s\n==================\n", argv[1]);
    printf("Format is \"%s\" with data length %d\n", wav->fmt, wav->format_length);
    printf("Format type is \"%s\"\n", wav->wave);
    printf("%d channels with a sample rate of %d\n", wav->number_channels, wav->sample_rate);
    printf("%d byte rate, %d alignment, %d bits per sample\n",
            wav->bytes_per_frame, wav->block_alignment, wav->bits_per_sample);
    printf("Data is \"%s\" and data size is %d", wav->data_begin, wav->size_of_data);

    memcpy(&output[0],&wav->riff,sizeof(wav->riff));
    memcpy(&output[4],&wav->file_size,sizeof(wav->file_size));
    memcpy(&output[8],&wav->wave,sizeof(wav->wave));
    memcpy(&output[12],&wav->fmt,sizeof(wav->fmt));
    memcpy(&output[16],&wav->format_length,sizeof(wav->format_length));
    memcpy(&output[20],&wav->format_type,sizeof(wav->format_type));
    memcpy(&output[22],&wav->number_channels,sizeof(wav->number_channels));
    memcpy(&output[24],&wav->sample_rate,sizeof(wav->sample_rate));
    memcpy(&output[28],&wav->bytes_per_frame,sizeof(wav->bytes_per_frame));
    memcpy(&output[32],&wav->block_alignment,sizeof(wav->block_alignment));
    memcpy(&output[34],&wav->bits_per_sample,sizeof(wav->bits_per_sample));
    memcpy(&output[36],&wav->data_begin,sizeof(wav->data_begin));
    memcpy(&output[40],&wav->size_of_data,sizeof(wav->size_of_data));

    for(int i = wav->size_of_data; i >= 44; i -= 2){
        output[i] = wav->data[wav->size_of_data - i];
        output[i + 1] = wav->data[wav->size_of_data + 1 - i];
    }

    write_file(argv[2], output, sizeof(output));
	free(buffer);
	free(wav);
	return 0;
}
