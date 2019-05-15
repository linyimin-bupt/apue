# apue

Unix环境高级编程源码及课后习题

## Ubuntu16.04下编译 `apue.h`头文件

1. 下载源码及解压

```shell
wget http://www.apuebook.com/src.3e.tar.gz
tar -zxvf src.tar.gz
```

这时在当前文件夹下会生成一个 `apue.3e`文件夹。

2. 编辑头文件

```shell
vim ./apue.3e/include/apue.h
```

光标移动到文件最后一行"#endif"的前面，然后添加如下代码，然后退出保存。

```shell
#include "error.c"
```

3. 拷贝到/usr/include/

```shell
cp ./include/apue.h /usr/include/
cp ./lib/error.c /usr/include/
```

4. 编译

```shell
make
```

5. 错误处理

编译时出现了以下错误：

```$xslt
/usr/bin/ld: cannot find -lbsd
...
make: ***[all] Error 1
```

这是因为缺少了相关库，使用下面命令安装相关库即可：

```$xslt
sudo apt-get install libbsd-dev
```

6. 重新编译

```$xslt
make
```

成功之后，就可以在项目里直接引用了

```c
#include "apue.h"
```

### 参考

[UNIX环境高级编程（第三版）头文件"apue.h"问题](https://www.jianshu.com/p/dd734b0e8cb9)

## [chapter 3 File I/O](./chapter3)