# ArchLinux

## openssh-server
* 安装 openssh-server
* systemctl start sshd.service
* systemctl enable sshd.service
* 配置文件 /etc/ssh/sshd_config ， 配置 PermitRootLogin yes/no 可禁用以root账户登录
* 客户端执行： ssh  $(user_name)@$(ip_addr)

## 链接
- link_s -> target , 选项-s后面的是已经存在的实体文件
    `ln -s target link_s`