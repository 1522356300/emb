# LFS-BOOK-10.0 关键内容学习笔记

## 0、Preface 前言
* [Software-Building-HOWTO](http://www.tldp.org/HOWTO/Software-Building-HOWTO.html)
* [Beginner's Guide to Installing from Source](http://moi.vonos.net/linux/beginners-installing-from-source/)

### Standards
* POSIX.1-2008
* FHS V3.0
* Linux Standard Base(LSB) V5.0(2015) : linux标准化规范（为大多数发行版都力争在一定程度上与是事实上的可兼容linux环境标准兼容）
* The LSB has four separate standards: 
    * Core: Bash, Bc, Binutils, Coreutils, Diffutils, File, Findutils, Gawk, Grep, Gzip, M4, Man-DB, Ncurses, Procps, Psmisc, Sed, Shadow, Tar, Util-linux, Zlib
    * Desktop: none
    * Runtime Languages : Perl
    * Imaging : none

## Part 1、Introduction 
...
## Part 2、Preparing for the Build
*create host(宿主机) where the new LFS system will be compiled and installed*
* 检查基础包是否已存在，以及版本是否过老。（根据文档描述的创建 version-check.sh 脚本查看）
* 创建 /mnt/lfs,并挂在到一个分区 /dev/sdc4
* 设置变量: export LFS=/mnt/lfs
* FOTTHEROOTUSER ....##待补充

### Chapter 3. Packages and Patches
* 创建缓存文件夹
    * mkdir -v $LFS/sources
    * chmod -v a+wt $LFS/sources
* 下载
    * wget --input-file=wget-list --continue --directory-prefix=$LFS/sources
* MD5校验
    ```
    pushd $LFS/sources
    md5sum -c md5sumsl
    popd
    ```
* All Packages Download
    * 点击如下链接，或者将如下链接替换上面的 wget-list 进行下载即可, 这里省略了MD5校验
    * [Acl   2.2.53](http://download.savannah.gnu.org/releases/acl/acl-2.2.53.tar.gz)
    * [Attr  2.4.48](http://download.savannah.gnu.org/releases/attr/attr-2.4.48.tar.gz)
    * [Autoconf 2.69](http://ftp.gnu.org/gnu/autoconf/autoconf-2.69.tar.xz)
    * [Automake 1.16.2](http://ftp.gnu.org/gnu/automake/automake-1.16.2.tar.xz)
    * [Bash     5.0](http://ftp.gnu.org/gnu/bash/bash-5.0.tar.gz)
    * [Bc       3.15](https://github.com/gavinhoward/bc/releases/download/3.1.5/bc-3.1.5.tar.xz)
    * [Binutils 2.35](http://ftp.gnu.org/gnu/binutils/binutils-2.35.tar.xz)
    * [Bison    3.7.1](http://ftp.gnu.org/gnu/bison/bison-3.7.1.tar.xz)
    * [Bzip2    1.0.8](https://www.sourceware.org/pub/bzip2/bzip2-1.0.8.tar.gz)
    * [Check    0.15.2](https://github.com/libcheck/check/releases/download/0.15.2/check-0.15.2.tar.gz)
    * [Coreutils 8.32](http://ftp.gnu.org/gnu/coreutils/coreutils-8.32.tar.xz)
    * [DejaGNU  1.6.2](http://ftp.gnu.org/gnu/dejagnu/dejagnu-1.6.2.tar.gz)
    * [Diffutils 3.7](http://ftp.gnu.org/gnu/diffutils/diffutils-3.7.tar.xz)
    * [E2fsprogs 1.45.6](https://downloads.sourceforge.net/project/e2fsprogs/e2fsprogs/v1.45.6/e2fsprogs-1.45.6.tar.gz)
    * [Elfutils 0.180](https://sourceware.org/ftp/elfutils/0.180/elfutils-0.180.tar.bz2)
    * [Eudev    3.2.9](https://dev.gentoo.org/~blueness/eudev/eudev-3.2.9.tar.gz)
    * [Expat    2.2.9](https://prdownloads.sourceforge.net/expat/expat-2.2.9.tar.xz)
    * [Expect   5.45.4](https://prdownloads.sourceforge.net/expect/expect5.45.4.tar.gz)
    * [File     5.39](ftp://ftp.astron.com/pub/file/file-5.39.tar.gz)
    ...
* patch download 补丁包

* 环境准备
    * $LFS/ 创建目录：source/(前述已创建)，bin/, etc/,lib/,sbin/,usr/,var/
        ```sh
        mkdir -pv $LFS/{bin,etc,lib,sbin,usr,var}
        case $(uname -m) in 
            x86_64) mkdir -pv $LFS/lib64;;
        esac
        mkdir -pv $LFS/tools
        ```
    * 添加 LFS 用户
        ```sh
        groupadd lfs
        useradd -s /bin/bash -g lfs -m -k /dev/null lfs     
        ## -s 设置默认shell；
        ## -g 添加到组
        ## -m 添加 /home/ 目录下用户home目录
        ## -k 
        passwd lfs
        chown -R -v lfs $LFS
        ```
    * 

## 3、Building the LFS Cross Toolchain and Temporary Tools
*explains which packages and patches need to be downloaded to build an LFS system and how to store them on the new file system*

## 4、**Building the LFS System**
*discusses the setup of an appropriate working environment*

## 5、** **
*explains the installation of the initial tool chain, (binutils, gcc, and glibc) using cross compilation techniques to isolate the new tools from the host system*
## 6、** **
*shows you how to cross-compile basic utilities using the just built cross-toolchain.*
## 7、** **
*enters a "chroot" environment and uses the previously built tools to build the additional tools needed to build and test the final system.*
## 8、** **
*The full LFS system is built*
## 9、** **
*basic system configuration*
## 10、** **
*kernel and boot loader*
## 11、** **
**

## 5、Appendices (附录)

## 部分单词释义
* preface, foreword   前言,序言
* journey to learn  学习之旅
* intrigue  v. 感兴趣,激起...的兴趣  n. 密谋
* concept  n. 概念
* philosophy  n. 哲学
* accomplish   v. 完成
* morph   v.变形
* relegate  v. 降级，贬职
* audience  n. 观众，受众
* implementation    n.执行，工具，仪器
* **Prior** to discovering Linux, we simply **put up** with issues in other Operating Systems as you had no choice.
    * prior   adj.在...之前, 
    * put up  挂起
* With Linux, the concept of choice began to emerge
    * emerge    v.浮现，露出真相
* decide    v.对...作出抉择，决定
* At first, the idea was **rather daunting** , 忘而升畏
    * rather    adv.相当，稍微  int.表示同意某人的提议
    * daunt     v.使胆怯，使失去信心
* After sorting through issues such as circular dependencies and compile-time errors, I finally built a custom-built Linux system. 
    * sort      n.种类  v.整理，妥善处理
    * through   adv.从头到尾 adj.全程的，直达的
* sustained     v.维持，使保持
* opportunity   n.机会，时机
* Out of this broadened interest    处于扩大兴趣
* you are free to alter the instructions to suit yourself,
    * alter         v.改变
    * instruction   n.用法说明，操作指南
* lend  v.借出
* benefit   n.优势，益处  v.得益于
* why go through all the hassle of manually building a Linux system from scratch when you can just download and install an existing one
    * hassle    n.困难  v.烦扰
    * manually  adv.手动的，人工的
* demonstrate   v.证明，示范
* gain          v.赢得，从...受益
* sufficient    adj.足够的，充足的
* architecture  n.建筑学，体系结构
* It requires a **certain level** of existing knowledge of Unix system administration in order to resolve problems and correctly execute the commands listed
    * certain   adj.确定， 某些
* comprehensive     adj.全部的，综合的  n.综合中学
* trial     v.测试，试验    n.审讯，试用
* beyond the scope  超出范围
* customize     v.订制
* typography    n.排版
* errata        n.堪误表
* We **highly recommend against** using newer versions  **强烈反对**
* grant     v.授予，承认 n.拨款
    