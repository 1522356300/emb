# Linux From Scratch

[LFS-BOOK](http://www.linuxfromscratch.org/lfs/downloads/stable/)

## 参考链接
https://blog.csdn.net/weixin_41217917/article/details/80757652
>http://www.linuxfromscratch.org/lfs/
>https://blog.csdn.net/u012333520/article/details/50533002/

## 目标
* 通过LFS增加对linux的理解，能够自己制作内核镜像。
* 截至期：2020.12.31

## 关键工具



## 步骤


### 建立用户环境

    ```
    cat > ~/.bash_profile << "EOF"
    exec env -i HOME=$HOME TERM=$TERM PS1='\u:\w\$ ' /bin/bash
    EOF
    cat > ~/.bashrc << "EOF"
    set +h
    umask 022
    LFS=/mnt/lfs
    LC_ALL=POSIX
    PATH=/tools/bin:/bin:/usr/bin
    export LFS LC_ALL PATH
    EOF
    source ~/.bash_profile
    ```

#### shell知识

```bash
cat > filename << "EOF" ...... << "EOF"
```

