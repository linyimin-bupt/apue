#include <apue.h>

int global_var = 6;
char buf[] = "a write to stdout\n";

int main(void) {
    int var = 88;
    pid_t pid;

    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1) {
        err_sys("write error");
    }
    printf("before fork\n");

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        global_var++;
        var++;
    } else {
        sleep(2);
    }

    printf("pid = %ld, glob = %d, var = %d\n", (long) getpid(), global_var, var);
    return 0;
}
