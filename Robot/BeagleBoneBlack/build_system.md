# 嵌入式操作系统构建

***考虑到ArchLinux对arm支持不够，且ROS官方指定系统为Ubuntu，因此本文尝试为 BeagleBone Black 构建Ubuntu系统***

## 0、构建方式
1) 通过现有镜像文件直接升级
2) 源码自行构建LFS

## 1、BeagleBone Black 系统升级
* 下载镜像文件，下载的为.img.xz []()
* 通过imgwriter工具写入SD卡， linux通过dd命令
    ```sh
    sudo dd bs=4M   ##每次写入块大小 
            if=2013-09-25-wheezy-raspbian.img   ##输入镜像文件
            of=/dev/sdb ##输出sd卡路径 
    ```
* 插入SD卡，按住boot button, 单板上电。等到四个LED指示灯全亮即表明进入更新系统版本状态。等待，知道等全亮或者全灭表明更新成功。断电，取出SD卡，重新上电即可。

#### <font color='RED'>NOTE</font>
* windows中可采用win32DiskImager,linux采用dd命令。**img文件不同与iso，不能采用其他操作系统写入iso镜像文件的工具** 
* 实践中需要修改单板现有文件系统中 /boot/uEnv.txt 文件，取消 **#cmdline=init=/opt/scripts/tools/eMMC/init-eMMC-flasher-v3.sh** 的#号注释


## 2、LFS 自行构建OS镜像

[Compiling the BeagleBone Black Kernel](https://wiki.beyondlogic.org/index.php/BeagleBoneBlack_Building_Kernel#NFS_boot_failures)
* ARM Cross Compiler
    ```sh
    yay -S arm-linux-gnueabihf-gcc  ##gcc-arm-linux-gnueabi
    ```
* kernel compressor : lzop
    ```sh
    sudo pacman -S lzop
    ```
* uboot mkimage 
    ```sh
    wget ftp://ftp.denx.de/pub/u-boot/u-boot-2020.10.tar.bz2 #访问该网站检索最新版本替换文件名
    ```