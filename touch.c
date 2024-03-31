#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PROGRAM_NAME "touch"

int main (int argc, char** argv) {
	if (argc < 1) {
		return 0;
	}

	for (int i = 1; i < argc; i++) {
		int fd = open(argv[i], O_CREAT | O_WRONLY | O_EXCL, 0666);
		if (fd < 0) {
			perror(PROGRAM_NAME);
			return 1;
		}
		
		int close_status = close(fd);

		if (close_status < 0) {
			perror(PROGRAM_NAME);
			return 1;
		}
	}

	return 0;
}
