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
    
    int old_errno;

    int fd_from = open(argv[1], O_RDONLY);

    if (fd_from < 0) {
        perror(PROGRAM_NAME);
        return 1;
    }

    int fd_to = open(argv[2], O_CREAT | O_WRONLY | O_EXCL, 0666);

    if (fd_to < 0) {
        //fd_to = -1;
        goto error;
    }

    char buffer[BUFFER_SIZE];
    ssize_t nread;
    ssize_t nwritten;

    while (nread = read(fd_from, buffer, BUFFER_SIZE), nread > 0)
    {
        char* out_ptr = buffer;

        nwritten = write(fd_to, buffer, nread);
        if (nwritten == -1) {
            goto error;
        }
        out_ptr += nwritten;
    }

    if (nread == -1) {
        goto error;
    }

    if (close(fd_from) < 0) {
        fd_from = -1;
        goto error;
    }

    if (close(fd_to) < 0) {
        fd_to = -1;
        goto error;
    }

    return 0;

    // at this point fd_open was successful
    error:
        old_errno = errno;
        if (fd_from != -1) {
            if (close(fd_from) < 0) {
                perror(PROGRAM_NAME);
            }
        }

        if (fd_to != -1) {
            if (close(fd_to) < 0) {
                perror(PROGRAM_NAME);
            }
        }

        errno = old_errno;
        perror(PROGRAM_NAME);
        return 1;
}