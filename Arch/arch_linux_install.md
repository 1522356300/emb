# Arch Linux 安装

>https://blog.csdn.net/r8l8q8/article/details/76516523

## 相关命令

## 离线安装
* 利用 rpmextract 工具
    > cd /
    > sudo rpmextract.sh ~lujun9972/android-x86-7.1-r2.x86_64.rpm
* [archlinux 离线安装rpm包](https://linux.cn/article-9847-1.html)


## APP安装
>sudo pacman -S python-pip

## linux 数据提取操作
* cut 切分
    ```bash
    export | cut -d " " -f 3-      ##以空格切分export信息，取第三段开始的内容
    ##??如何取PATH最后一段
    ```
* grep 检索
    > -V 反选， -c 计数, -i 忽略大小写

* sort 排序
    > -n 以纯数字排序， -r 反向排序， -t 分割符， -k 以哪一段计算排序
    ```bash
    cat /etc/passwd | sort -t ":" -k 3 -n -r
    ```
* wc 统计字符，字数，行数
    >-c
* uniq 去重
* tee 双向重导项
* split 文件切分
* xargs 参数代换
* tr 替换，压缩，删除
    ```bash
    echo "addcrfad     fsdfs" | tr  "abc" "123" |tr -d "f" | tr -s " " 
    $: 1dd3r1d sds  ##将a,b,c 依次替换为 1,2,3,  -d 删除字符， -s压缩字符
    
    ```

