#include <stdio.h>

void read_file_to_memory(unsigned char *ptr_to_memory){
	FILE *fp;
	unsigned char buffer[10];

   	fp = fopen("fishie.ch8", "rb");

   	fread(buffer,sizeof(buffer),1,fp); // read 10 bytes to our buffer
   	
   	for(int i = 0; i<10; i++){
    	printf("%x ", buffer[i]); // prints a series of bytes
    	ptr_to_memory[i+500] = buffer[i];
   	}

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

	read_file_to_memory(memory_ptr);

	printf("\nhello\n");
	for(int i = 500; i<510; i++){

		printf("%x ", memory[i]);	
	}

	printf("\n");


	return 0;
}