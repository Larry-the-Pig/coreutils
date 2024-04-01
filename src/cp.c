#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#define PROGRAM_NAME "cp"
#define BUFFER_SIZE 4096

int main(int argc, char** argv) {
    if (argc < 3)
    return 1;
    
    int fd_from = open(argv[1], O_RDONLY);

    if (fd_from < 0) {
        // error handle
    }

    int fd_to = open(argv[2], O_CREAT | O_WRONLY | O_EXCL, 0666);

    if (fd_to < 0) {
        // error handle
    }

    char buffer[BUFFER_SIZE];
    ssize_t nread;
    ssize_t nwritten;

    while (nread = read(fd_from, buffer, BUFFER_SIZE), nread > 0)
    {
        char* out_ptr = buffer;

        nwritten = write(fd_to, buffer, nread);
        if (nwritten == -1) {
            // error handle
        }
        out_ptr += nwritten;
    }

    if (nread == -1) {
        // error handle
    }

    return 0;
}