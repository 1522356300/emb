# Cmake

#### cmake 最低版本号要求
>cmake_minimum_required (VERSION 2.8)

#### 项目信息
>project (PRODUCT)

#### 添加变量值
>aux_source_directory(. DIR_SRCS) ## 添加当前目录下的所有源文件到变量 DIR_SRCS 中

#### 添加子目录
> add_subdirectory(math)    ##添加math子目录，形成目录递归,子目录的CMakeLists.txt文件和相关源码也会被处理

#### 指定生成目标
add_executable(PRODUCTTEST main.cc) 

**z **


#### 添加链接库
target_link_libraries(PRODUCTTEST scu.so)