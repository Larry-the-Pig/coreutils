#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

#define PROGRAM_NAME "ls"

int main(int argc, char** argv) {
    DIR* dp = opendir(argv[1]);
    struct dirent* ep;

    if (dp == NULL) {
        perror(PROGRAM_NAME);
        return 1;
    }

    errno = 0;
    while ((ep = readdir(dp)) != NULL) {
        puts(ep->d_name);
    }

    if (errno != 0) {
        perror(PROGRAM_NAME);
        if (closedir(dp) == -1) {
            perror(PROGRAM_NAME);
        }

        return 1;
    }

    if (closedir(dp) == -1) {
        perror(PROGRAM_NAME);
        return 1;
    }

    return 0;
}