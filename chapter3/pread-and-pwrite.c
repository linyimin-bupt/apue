/**
 * 1. pread and pwrite are atomic operations
 * 2. When invoke pread or pwrite function, the current file offset is not updated.
 */

/**
 * Problem: 当使用O_APPEND打开后， current file offset应该指向文件末尾， 但是这个得到的是0
 */
#include "apue.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int fd = open("test.txt", O_WRONLY | O_APPEND | O_CREAT );

    if (fd == -1) {
        err_sys("open() error");
    }

    // current offset
    off_t offset = lseek(fd, 0, SEEK_CUR);

    printf("Before pwrite, offset: %ld\n", offset);

    char buf[] = "This is a test";

    ssize_t str_len = pwrite(fd, buf, strlen(buf), 0);
//    ssize_t str_len = write(fd, buf, strlen(buf));

    printf("Write %zd bytes data\n", str_len);

    /*
     * 调用pwrite不会改变current file offset(文件偏移量)
     */
    offset = lseek(fd, 0, SEEK_CUR);

    printf("After pwrite, offset: %ld\n", offset);

    close(fd);
    return 0;
}