#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_file_to_memory(unsigned char *ptr_mem, char* path_to_file){
	FILE *fp;
	unsigned char buffer[16];

   	fp = fopen(path_to_file, "rb");

   	if(fp == NULL){
   		printf("Couldn't open: %s\n", path_to_file);
   		return -1;
   	}

   	int how_many_bytes_was_read;
   	int ptr_mem_top = 500;

   	while(!feof(fp)){
   		how_many_bytes_was_read = fread(buffer,sizeof(unsigned char),sizeof(buffer),fp);
   		
   		if(how_many_bytes_was_read>0){
   			//	printf("Read: %d bytes\n", how_many_bytes_was_read);

   			for(int i = 0; i<how_many_bytes_was_read; i++){
   				if(buffer[i]<16)
   					printf("0");
   				
   				ptr_mem[ptr_mem_top] = buffer[i];
   				printf("%x ", ptr_mem[ptr_mem_top]);
   				ptr_mem_top++;
   				}

   				printf("\n");

   			} 
   	}

   	return ptr_mem_top;
	fclose(fp);
}

int main(int argc, char const *argv[])
{
	// unsunsigned char = 1 byte = 8 bits
	unsigned char memory [4096];
	unsigned char *memory_ptr;
	memory_ptr = memory;
	unsigned char V[16];
	unsigned char key[16];			// array to store state of hex keyboard
	unsigned char SP;				// stack pointer - points to the top of stack
	unsigned char gfx[64 * 32];		// screen 
	unsigned char delay_timer;
	unsigned char sound_timer;

	// unsunsigned short = 2 bytes = 16 bits
	unsigned short I;			
	unsigned short PC;				
	unsigned short opcode;			// register to store current opcode
	unsigned short stack[16];

	// ???? its convenient but not sure if correct
	int p_mem_top;	// points to the last index where something is written to memory


	// erease all memory
	for (int i = 0; i < 4096; ++i)
	{
		memory[i] = 0;
	}

	if(argc != 2){
		printf("%s\n", "Wrong parameter. You need to specify file you want to load to.");
		return -1;
	}

	char* path_to_file = malloc(strlen(argv[1]) + 1);
	strcpy(path_to_file, argv[1]);
	p_mem_top = read_file_to_memory(memory_ptr, path_to_file);

	//handle file load error
	if(p_mem_top == -1){
		printf("File load error. \n");
		return -1;
	}

	// print content of memory
	printf("\n");
	printf("%s\n", "W pamieci:");

	int current_byte = 500;

	do{
		for (int i = 0; i < 16; ++i){
			if(memory[current_byte+i] < 16)
				printf("0");

			printf("%x ", memory[current_byte+i]);
			
		}
		current_byte+=16;
		printf("\n");
	}while(current_byte<p_mem_top);

	printf("\n");


	return 0;
}