#include <stdio.h>
#include <stdint.h>

int main(int argc, char * argv[])
{
	// Usage : intdump [filename]

	if(argc >= 2)
	{
		FILE * file = fopen(argv[1],"rb");

		if(file != NULL)
		{
			fseek(file,0,SEEK_END);
			uint64_t len = ftell(file); // Find size of file in bytes
			rewind(file);
			
			for(uint64_t i = 0; i < len; i++)
			{
				if(i%15 == 0)
					putchar('\n'); // move to new line after 15 bytes.

				printf("%u\t",fgetc(file)); // seperate bytes with a horizontal tab.
			}
		
			putchar('\n');
			fclose(file);
			return 0;
		}
		else
		{
			perror("Failed ");
			return -1;
		}
		
	}
	else
	{
		puts("Failed : No filename given.");
		return -1;	
	}
	
} 
