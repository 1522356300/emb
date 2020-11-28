>参考资料：《C语言核心技术》

## C标准
- K&R , Kernighan & Ritchie 1969～1973开发了C语言
- C89 / C90
    - 1989年美国国家标准协会ANSI对C语言进行标准化，即 ANSI C
    - 1990年ISO采纳了ANSI C => ISO/IEC 9899:1990
- C99
    - 1999年ISO/IEC 9899：1999
    - 引入：内联函数，可变长数组，复合字面量，制定成员初始化器，可变参宏，long long int, 复数类型
- C11
    - 2011年 ISO/IEC 9899：2011
    - 引入：静态断言，字节对齐符，范型机制，原子操作，多线程支持，unicode支持
    
## C/C++ 关键字
- C89标准
    |||||||
    |:-----|:-----|:-----|:-----|:-----|:-----|
    | auto | register | static | volatile | const | extern |
    |  do  |   while  |  for   |  switch  |  case | default | 
    |  if  |   else   |  goto  | continue | break |
    | char |  short   |  int   |  long    | float | double  |
    |signed| unsigned |typedef |   enum   | union |  struct |
    | void |  return  | sizeof ||||
    |||||||

- C99新增
    - inline  内联函数
    - restrict    限定和约束指针，并表明指针是访问数据对象的唯一且初始的方式，不能通过其他途径来修改，可以帮助编译器进行更好的优化代码。
    - _Bool       布尔类型
    - _Complex    用于表示复数类型
    - _Imaginary  用于表示虚数类型
    - _Pragma     同 `#pragma`

- C11 新增：
    - _Alignas    指定某个变量按照其他数据类型对其
    - _Alignof    指定数据类型内存对其的字节数
    - _Atomic     原子类型说明符和限定符
    - _Static_assert  编译时有效，测试由用户指定且可以转换为布尔值的整数表达式表示的软件断言。若计算结果为0,则编译错误而失败。
    - _Noreturn   声明调用完成后的函数不返回主调函数，用于告诉用户和编译器，该函数不会将控制返回主调函数，通知编译器可以优化一些代码。
    - _Thread_local   被修饰的变脸具有线程周期，在线程开始时生成，线程结束时销毁，可以与static,extern联合使用，将影响变量的链接属性
    - _Generic    可以简单的将一组具有不同类型却有相同功能的函数抽象为一个统一个的接口
        - 类似于sizeof,typeof, 其用于在编译时获取该表达式的类型，并不会对该表达式做运算，类似与switch
        ```c
        #define getTypeName(x)   _Generic((x), \
            _Bool:"bool", \
            char:"char",\
            int:"int",\
        )
        ```

## 部分接口描述
`
## 预处理

- 预处理器将每个注释用空格替换
- 空格符和制表符可以出现在#字符和命令名字之间, 如下语句合法
    >`#  define  max(a, b) ((a)>(b)?(a):(b))`
- include 
    - 可以在include 后面使用宏，只要在进行宏替换以后能找到对应的文件即可。
    - 将任何后面跟的文件内容插入到预处理命令的相应位置。
    - include 最多支持15层的嵌套包含
- define
    - C99支持可变参
        - `__VA_ARGS__` 其被调用时所用的参数列表中剩下的所有参数取代
- 字符串化 `#`
    - 实参中的每个双引号前面都会添加一个反斜线
- 字符拼接 `##`
- 宏嵌套
    - 宏可以嵌套，但是不能递归，当前宏的定义不能依赖与当前的宏
    - 在替换实参， 执行玩#， ## 运算以后，预处理器会检查操作所得的替换文本，并展开其中所包含的所有宏。
- 作用域
    - 宏不可重复定义，除非完全相同。若需要改变宏定义，需采用`#undef`,若宏本不存在，则与处理器忽略该undef命令
- 范型宏

- 条件编译
    - `#ifdef`  等效于  `#if define`
    - `#ifndef`  等效于  `#if !define`
    - 后面的宏被定义时，条件为真，值为1
- `#line line_number` 重定义行号，将下一行设置为其后的行数，影响`__LINE__`
- `#error [text]` 让预编译器发出错误消息，并结束执行。若这里的`text`包含宏，其不会被展开
- `#pragma [takens]` 用于向编译器提供额外信息
    - 若第一个标记为 STDC， 则该命令为标准pragma,否则其实现决定于编译器版本
    - `#pragma pack(n)`  字节对其n， 通常为是2的幂值，2,4,8。若未写数字，则设置为实现版本的默认值
- 其余预定义宏
    - `__DATA__`, `__FILE__`, `__LINE__`, `__TIME__`, 
    - `__STDC__`, 整数常量1,表示该编译器遵循ISO C标准
    - `__STDC_HOSTED__` 如果当前实现版本是宿主环境下的实现版本，则其为整数常量1（有操作系统的支持，拥有完整的标准库）
    - `__STDC_VERSION__`
    - `__cplusplus` 为C++编译器保留

### 格式化输入输出
- printf, scanf 返回值为输入/输出字符个数
    - `借助printf的返回值，可以直接获取一个数的位数`
- 行输入：fgets, **~~gets~~**  
    > man 3 gets
    ```
    char *gets(char *s);
    DESCRIPTION
    Never use this function.
    gets() reads a line from stdin into the buffer pointed to by s until either a terminating newline or EOF, which it replaces with a null byte ('\0').  No check for buffer overrun is performed (see BUGS below).
    ```
    - 换行符的读入问题：
        - fgets读入换行符(0x0a), str[strlen(str)-1] == '\n';
        - 如何不读入换行符？
            `scanf("%[^\n]", str);` 这里利用正则表达式过滤掉\n




### 跨平台
- x64平台编译x32文件：
    `gcc -m32 helo.c` 需要预先安装32位的lib库，否则找不到对应的头文件

* getopt, getopt_long
#include <unistd.h>
#include <getopt.h>
int getopt(int argc, char * const argv[], const char optstring);
多次循环调用依次获取参数选项，获取结束返回-1,
optstring, "xy:z::" , x无选项参数， y必有选项参数，z选项参数可有可无，若有则必须紧接在选项后面不能有空格


## typeof
- 获取变量/函数类型，但是不可包含限定词，如const, static, extern 
- typeof 仅用于gnu编译器，若采用ansi或其他标准，应写成：__typeof(), __typeof__()

## 调试用预编译
- `__func__` 为c99标准的标识符
- `__FUNCTION__`, 编译器提供商所使用，其往往定义为 `__func__` 的宏, 在函数大括号开始之后就立即初始化。
    - `__FUNCDNAME__` C++函数修饰名
    - `__FUNCSIG__` C++函数签名， 以 void myfunc(void) 为例
        - void __cdecl myfunc(void)
        - void __thiscall S::myfunc(void) const   //成员函数
    - 关于函数调用约定
        - __cdecl
        - __stdcall
        - __fastcall
        - thiscall 仅仅用与C++成员函数，其并不是关键字，无法被程序员指定，