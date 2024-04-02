#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>

#define PROGRAM_NAME "whoami"

int main() {
    /*
        the man page for getpwuid says:
        If one wants to check errno after the call, 
        it should be set to zero before the call.
    */
    errno = 0;

    struct passwd* p = getpwuid(geteuid());

    if (p == NULL) {
        perror(PROGRAM_NAME);
        return 1;
    }

    printf("%s\n", p->pw_name);

    return 0;
}
