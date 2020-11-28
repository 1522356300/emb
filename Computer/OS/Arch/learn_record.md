# 踩坑记录

#### pacman -Syu 遇到gpg导入失败

时间异常：、
```bash
sudo timedatectl set-ntp true   #启动时间同步
```

~/.bash_profile 不生效
配置/etc/profile,添加：source ~/etc/.bash_profile,然后需要注销账户重新登录才会生效。

文件(夹)权限
t   sticky 用户只能删除自己的文件 <针对目录>



* 安装man手册
sudo pacman -S man-pages

* 添加用户到指定组
    * 需求：调试BB-black串口过程中，/dev/ttyS1对普通用户并无读写权限，因此需要将用户添加到权限组中
    * 