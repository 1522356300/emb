# GCC

- introduction
    - GCC: GNU Compiler Collection

- 预编译
    - cpp   预处理器
    - -E 指示在预处理玩以后即停止

- 编译
    - -S 指示在生成汇编语言以后立即停止，默认生成.s的汇编语言文件
    - -fverbose-asm 选项可以将变量，语句等作为汇编语句中的注释，如下所示
        ```
        # hello.c:7:     printf("hello, world\n");
            leaq	.LC0(%rip), %rdi	#,
            call	puts@PLT	#
        # hello.c:8:     return 0;
            movl	$0, %eax	#, _3
        # hello.c:9: }
        ```
- 汇编
    - as    汇编器
    - -c    指示GCC不进行链接，并保留汇编生成的目标文件 .o
    - 汇编器选项，需要以逗号分割放在gcc的-Wa选项后：
        - -as=hello.sym 输出模块的符号表到hello.sym文件中
        - -L 在符号表中包含本地符号（内部链接的C标识符） 
            - `gcc -o hello -Wa,-as=hello.sym,-L hello.c`
        - -a 后面可加上多个开关选项，控制列表输出，默认列表输出包含汇编代码、符号表。
    __通过添加相关汇编选项，可以详细分析编译器是如何将C代码翻译成二进制程序__

- 链接
    - ld    链接器s


- -Wall 输出告警信息
- -o    目标输出文件
- -Dname    增加宏定义符号name，配合源码中的`#ifdef name`实现条件编译，符号name必须是源码尚未被定义过的。
- -Uname    取消name定义
- -Idirectory[: dir]    指定对该目录进行头文件搜索

- 编译成动态库
    - -fPIC     gcc将不会包含对函数和变量具体内存地址的引用
    - -shared   用于创建共享函数库
    ```
    [psj@Arch func]$ gcc -o log.a log.c -shared
    [psj@Arch func]$ file log.a
    log.a: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked,...
    ```
    - ldd 命令可以查看应用程序需要使用的函数库是

- 调试信息
    - -g  在可执行程序的调试函数段中包含调试信息， 其可以被GDB用于执行源代码级别的调试，和其他更高级的调试的方式。
- 优化
    - -O0 ～ -O3 ， 从不进行优化到要求GCC尽可能的执行优化
    - -Os  可以对可执行文件的大小进行优化
- 硬件选项
    - -march    要求gcc针对特定的CPU模型生成代码，其中包含特定模式的指令
    - -msoft-float  要求GCC不要使用硬件浮点运算指令，而是依靠函数库调用来执行浮点运算
    - -mbig-endian， -mlittle-endian  指定大小段字节序


    