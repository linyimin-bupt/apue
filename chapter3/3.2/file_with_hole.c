#include "apue.h"
#include <fcntl.h>

int main(void) {
    char buf1[] = "abcdefghij";
    char buf2[] = "ABCDEFGHIJ";

    int fd;

    if ((fd = creat("file.hole", FILE_MODE)) < 0) {
        err_sys("creat error");
    }

    if (write(fd, buf1, strlen(buf1)) != strlen(buf1)) {
        err_sys("buf1 write error");
    }

    if (lseek(fd, 16384, SEEK_SET) == -1) {
        err_sys("lseek error");
    }

    if (write(fd, buf2, strlen(buf2)) != strlen(buf2)) {
        err_sys("buf2 write error");
        FOPEN_MAX
    }

    return 0;
}