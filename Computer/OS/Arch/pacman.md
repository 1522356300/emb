# 软件包管理器 pacman

软件包管理器：yum, apt-get, rpm, pip, composer
>https://wiki.archlinux.org/index.php/Pacman_(简体中文)

## 配置文件

* /etc/pacman.conf   ##  pacman 配置
* /etc/pacman.d/mirrorlist   ## 镜像源，考前的优先
* /var/cache/pacman/pkg/     ## 缓存软件包

## 标准命令

* 列出已安装的软件包
    >pacman -Q
    >pacman -Qi package_name  ## 查询本地安装包的详细信息
    >pacman -Si package_name  ## 显示软件包的详细信息
    >pacman -Ql package_name  ## 列出已安装包的所有文件
* 更新整个系统
    >pacman -Syu
* 强制删除软件包机器相关所有内容
    >pacman -Rsc xorg
    >pacman -Sc  ## 清除未安装软件包的缓存（以及旧版本的软件包）
    >pacman -Scc  ## 清除所有缓存
* 显示软件包的依赖树
    >pactree package_name
* 从本地安装：
    >pacman -U package_path/package_name
    >pacman -U http://package_url/package_name  ## 从指定远程路径中安装
* --force 强制
* --ignore 忽略

## 自己推断单意

* -S 指定软件包组
* -s 相关依赖
* -c 递归清除
* -d 不删除依赖当前软件包的其他程序
* -y 源
* -u 更新系统
* -R 删除

## 问题

* 更新系统之前，最好先确保时间date正常，否则可能出现gpg等因时间错误而更新异常。