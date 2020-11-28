# 编程杂记

## ar、nm、objdump

* ar 操作.a、.so等库文件：## archive--档案、存档

    ```bash
    ar -rv test.a test.o ## 根据后面的.o文件创建.a库，如果包已经存在，则替换其内部已存在的模块，不存在的模块则添加
    ar -x test.a    ## 解包test.a库
    ar -t libname.a ## 显示库的模块表清单
    ```

* nm 查看目标文件的符号清单：List symbols in [file(s)] (a.out by default).

    ```bash
    nm -a main.o    ## 查看包含调试符号在内的完整符号表，一般简单的执行 nm main.o 查看源文件中涉及的符号即可
    nm -u main.o    ## 查看未定义的符号
    ```

* objdump 功能强大，包括前两个命令的很多供能:Display information from object。

    ```bash
    objdump -h main.o ##查看文件头部信息
    objdump -t main.o ##查看符号表
    objdump -d main.o ##反汇编，查看二进制机器码
    ```

## GNU C 的 \_\_attribute__ 机制

* \_\_attribute__ 用于设置属性，包括：Function Attribute, Variable Attribute, Type Attribute
((constructor))
* 语法格式为：\_\_attribute__ ((attribute-list)) , 括号中的内容可以前后加下划线
* aligned, 使设置对象占用更多的空间,(同时取决于链接器最大支持字节对齐)
    ```C
    typedef int int32_t __attribute__ ((aligned(8)))
    ```
* packed, 减小对象占用的空间
    ```C

    ```
* at 将便来给你或者函数绝对定位到FLASH(用于固化信息，将出场设置写入flash）或者RAM中（一般用于数据量比较大缓存）
    ```C
    const u16 gflashdata__attribute__((at(0x0800F000))) = 0xFFFF;
    u8 USART2_RX_BUF[USART2_REC_LEN] __attribute__ ((at(0X20001000)));
    ```
* section 将变量,函数放入指定段
    ```C
    /* in RO section */
    const int descriptor[3] __attribute__ ((section ("descr"))) = { 1,2,3 };
    /* in RW section */
    long long rw[10] __attribute__ ((section ("RW")));
    /* in ZI section *
    long long altstack[10] __attribute__ ((section ("STACK"), zero_init));*/

    u8 FileAddr[100] __attribute__ ((section ("FILE_RAM"), zero_init,aligned(4)));
    ```
* transparent_union
* unused
* deprecated
* may_alias

函数注册

## __typeof

## \_\_FUNCTION__

* \_\_func__ 是C++11与C99引入的，其并非宏定义，而是作为一个隐式申明的标识符，就像紧跟在每个函数定义的 { 之后的声明一样。

    ```C
    static const char __func__[] = "function_name";
    //这里的functions_name是词法封闭函数的名称即函数的简单名称。
    ```

* \_\_FUNCTION__ 是一些C编译器支持的与标准扩展。不同编译器可能有不同的版本（尤其区别与windows)
* \_\_PRETTY_FUNCTION__ 是一个gcc扩展，大致类似\_\_FUNCTION__，但是其打印的内容包含函数完整声明，即包含返参类型、入参类型信息等。

## linux环境如何输出彩色文字

* 查看源代码 [日志彩色打印]:(http://github.com/1522356300/emb.github.io/code/color_print))

## 查看当前使用的shell

* echo $0
* echo $SHELL

## 时钟同步

1. NTP

    ```txt
    网络时间协议（Network Time Protocol）是 GNU/Linux 系统通过 Internet 时间服务器同步系统软件时钟的最常见方法。设计时考虑到了各种网络延迟，通过公共网络同步时，误差可以降低到 10 毫秒以内；通过本地网络同步时，误差可以降低到 1 毫秒
    ```

2. systemd-timesyncd 进程

    systemd-timesyncd是一个用于跨网络同步系统时钟的守护服务。它实现了一个 SNTP 客户端。与 NTP 的复杂实现相比，这个服务简单的多，它只专注于从远程服务器查询然后同步到本地时钟。

3. Arch Linux 时钟同步

    >sudo timedatectl set-ntp true

    ```shell
    [psj@Arch ~]$ timedatectl
                Local time: Wed 2020-08-12 00:42:23 CST
            Universal time: Tue 2020-08-11 16:42:23 UTC
                    RTC time: Tue 2020-08-11 16:42:23
                    Time zone: Asia/Shanghai (CST, +0800)
    System clock synchronized: yes
                NTP service: active
            RTC in local TZ: no
    ```

4. xclock 同步时间并每间隔1s刷新

    >sudo pacman -S xorg-xclock

    >xclock -d -update 1 -strftime %T &