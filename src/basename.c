#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(int argc, char** argv) {
    // this behavior is undefined
    if (argc < 2) {
        puts(".");
        return 0;
    }

    char buffer[BUFFER_SIZE] = {0};

    strncpy(buffer, argv[1], BUFFER_SIZE - 1);

    if (strcmp(buffer, "/") == 0) {
        puts("/");
        return 0;
    }

    // remove trailing / characters
    size_t len = strlen(buffer) - 1;
    while (buffer[len] == '/') {
        buffer[len] = 0;
        len--;

        // prevent underflows
        if (len <= 0)
        break;
    }

    // true if string is only / characters
    if (len <= 0) {
        puts("/");
        return 0;
    }

    char* token = strrchr(buffer, '/');

    // no slash is present
    if (token == NULL) {
        puts(buffer);
        return 0;
    }

    // advance past the / character.
    token += 1;

    puts(token);

    return 0;
}
