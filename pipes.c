#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pip[2];
    char s[20];
    pipe(pip);
    int p = fork();

    if (p > 0) {
        printf("Parent process, sending msg to child\n");
        write(pip[1], "Hello child", 12);
        wait(NULL);
        read(pip[0], s, 12);
        printf("Received msg from child: %s\n", s);
    } 
    else if (p == 0) {
        printf("Hi, this is child.\n");
        read(pip[0], s, 12);
        printf("Received msg from parent: %s\n", s);
        write(pip[1], "Hello parent", 13);
    }

    return 0;
}
