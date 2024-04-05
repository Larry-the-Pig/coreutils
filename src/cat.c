#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define PROGRAM_NAME "cat"

int main(int argc, char** argv) {
    if (argc < 2)
    return 0;

    int old_errno;
    
    int i = 1;

    if (strcmp(argv[1], "-u") == 0)
    i = 2;

    for (; i < argc; i++) {

        int fd = open(argv[i], O_RDONLY);
        if (fd == -1) {
            goto error;
        }

        char buffer[256];

        ssize_t nread;
        
        while (nread = read(fd, buffer, 256), nread > 0) {
            if (write(STDOUT_FILENO, buffer, nread) == -1) {
                goto error;
            }
        }

        if (nread == -1) {
            goto error;
        }

        if (close(fd) == -1) {
            fd = -1;

            goto error;
        }

        // advance before label
        continue;

        error:
            old_errno = errno;
            if (fd != -1) {
                if (close(fd) < 0) {
                    perror(PROGRAM_NAME);
                }
            }

            errno = old_errno;
            perror(PROGRAM_NAME);
            return 1;
    }

    return 0;

}
