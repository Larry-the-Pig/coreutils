#include <stdio.h>
#include <unistd.h>

#define PROGRAM_NAME "tty"

int main() {
    // POSIX specifies standard input as the tty to be queried
    char* tty = ttyname(STDIN_FILENO);

    if (tty == NULL) {
        perror(PROGRAM_NAME);
        return 1;
    }

    puts(tty);

    return 0;
}