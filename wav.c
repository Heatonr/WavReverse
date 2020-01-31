#include "wav.h"
#include <string.h>
#include <stdlib.h>

wav_file* parse(char* contents){
	wav_file* wav = malloc(sizeof(wav_file));


    memcpy(&(wav->riff), contents, 4*(sizeof(char)));
    contents += 4*(sizeof(char));
    memcpy(&(wav->file_size), contents, sizeof(int));
    contents += sizeof(int);
    memcpy(&(wav->wave), contents, 4*(sizeof(char)));
    contents += 4*(sizeof(char));
    memcpy(&(wav->fmt), contents, 4*(sizeof(char)));
    contents += 4*(sizeof(char));
    memcpy(&(wav->format_length), contents, sizeof(int));
    contents += sizeof(int);
    memcpy(&(wav->format_type), contents, sizeof(short));
    contents += sizeof(short);
    memcpy(&(wav->number_channels), contents, sizeof(short));
    contents += sizeof(short);
    memcpy(&(wav->sample_rate), contents, sizeof(int));
    contents += sizeof(int);
    memcpy(&(wav->bytes_per_frame), contents, sizeof(int));
    contents += sizeof(int);
    memcpy(&(wav->block_alignment), contents, sizeof(short));
    contents += sizeof(short);
    memcpy(&(wav->bits_per_sample), contents, sizeof(short));
    contents += sizeof(short);
    memcpy(&(wav->data_begin), contents, 4*sizeof(char));
    contents += 4*sizeof(char);
    memcpy(&(wav->size_of_data), contents, sizeof(int));
    contents += 4*sizeof(char);
    wav->data = contents;


    return wav;
}
