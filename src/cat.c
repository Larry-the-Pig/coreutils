#include <stdio.h>
#include <errno.h>
#include <string.h>

#define PROGRAM_NAME "cat"

int main(int argc, char** argv) {
    if (argc < 2)
    return 0;
    
    for (int i = 1; i < argc; i++) {
        FILE* file = fopen(argv[i], "r");
        if (file == NULL) {
            perror(PROGRAM_NAME);
            return 1;
        }

        char buffer[256];

        // fgets WILL write a NULL terminator
        while (fgets(buffer, 256, file)) {
            printf("%s", buffer);
        }

        int close_status = fclose(file);
        if (close_status != 0) {
            perror(PROGRAM_NAME);
            return 1;
        }
    }

    return 0;
}