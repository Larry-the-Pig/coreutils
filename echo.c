#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define PROGRAM_NAME "echo"

int main(int argc, char** argv) {
	int length = 0;
	if (argc < 2)
		return 0;

	for (int i = 1; i < argc; i++) {
		length += strlen(argv[i]);
	}

	char* buffer = malloc(length);
	if (buffer == NULL) {
		perror(PROGRAM_NAME);
		return 1;
	}
	
	char* p = buffer;
	for (int i = 1; i < argc; i++) {
		strcpy(p, argv[i]);
		p += strlen(p);

		if (i < argc - 1) {
			*p++ = ' ';
		}
	}

	printf("%s\n", buffer);

	return 0;
}
