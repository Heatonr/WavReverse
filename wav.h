#ifndef H_WAV
#define H_WAV

typedef struct{
    char riff[4];
    int file_size;
    char wave[4];
    char fmt[4];
	int format_length;
	short format_type;
	short number_channels;
	int sample_rate;
	int bytes_per_frame;
	short block_alignment;
	short bits_per_sample;
	char data_begin[4];
	int size_of_data;
	char* data;
}wav_file;

wav_file* parse(char* contents);
#endif
