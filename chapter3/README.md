## 文件I/O

### 综述

本章讲讲解的文件I/O是非缓冲IO(`unbuffered IO`),所谓的非缓冲IO是指每次调用`read`或者`write`函数,都会引发系统调用.非缓冲IO属于POSIX标准.

本章主要解决的问题:

1. 文件IO常用的5个函数`open`, `write`, `read`, `lseek`和`close`.

2. 非缓冲IO`read`及`write`函数`nbytes`对读写性能的影响

3. 内核如何维护多进程同时操作一个文件

### 文件描述符

对于内核来说,所有打开的文件都由文件描述符表示.对于文件的操作也通过文件操作符完成.文件描述符通常是一个非负整数.

在Unix系统中, 0通常代表标准输入, 1表示标准输出, 2表示标准错误,为了程序的可读性,一般不在程序中直接使用魔法数.所以`unistd.h`文件为这些数定义了符号常量:

- `STDIN_FILENO`
- `STDOUT_FILENO`
- `STDERR_FILENO`

文件描述符的值范围为: 0~FILE_MAX-1

Linux系统可以通过一下命令查看`FILE_MAX`的值

```bash
cat /proc/sys/fs/file-max
```

### `open` 和 `openat`函数

打开文件或者创建文件

```objectivec
#include <fcntl.h>

int open(const char *path, int oflag, .../* mode_t mode*/);
int openat(int fd, const char *path, int oflag, .../*mode_t mode*/);
```

其中path指定文件的路径, oflag指定打开模式;



### `creat` 函数

### `close` 函数

### `lseek` 函数

### `read` 函数

### `write` 函数

### I/O的效率

### 文件共享

### 原子操作

### `dup` 和 `dup2` 函数

### `sync`, `fsync` 和 `fdatasync` 函数

### `fcntl` 函数

### 总结
