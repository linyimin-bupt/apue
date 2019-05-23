#include <fcntl.h>
#include "apue.h"

int main(int argc, char *argv[]) {

//    const int BUFFSIZE = atoi(argv[1]);
//
//    char buf[BUFFSIZE];
//
//    int str_len = 0;
//    int len = 0;
//
//    int fd = open("/dev/null", O_WRONLY);
//
//    while ((str_len = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
//        len += str_len;
//        if (write(fd, buf, str_len) != str_len) {
//            err_sys("write error");
//        }
//    }
//
//    if (str_len < 0) {
//        err_sys("read error");
//    }

    int fd = open("/dev/fd/0", O_WRONLY);
    printf("%d\n", fd);
    exit(0);
}