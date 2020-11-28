# Shell
### zsh
* 安装zsh配置文件oh-my-sh
    >wget https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O - | sh
### 终端
* terminal = tty(Teletypewriter 电传打印机)，Ctrl+ Alt + T
* w / who 查看当前通过哪个终端介入
* which 
* echo $PATH
* su - user 这里‘-’可以清除环境变量
* sudo !!  对上一条命令加上 sudo 重新执行
* cp src_1 src_2 ... dst_dir/
* 重定向  ：> 覆盖,  >> 追加
* 远程路径： 协议：//用户名:密码@位置/路径：端口
    > ftp://user:passwd@ftp.haizeix.com:21
* cd ~root/ 切换到root的home目录
* last 查看最近登录情况
### 重定向
* 将标准输出，标准输出分别重定向到指定文件
    >ls /dev1 ./  1>ls.log 2> err.log  
* 将标准输出，标准输入重定向同一个路径（2>&)
    >ls /etc2 ./ > ls.log 2>& 1
* > a.out < file
* > mkfifo file

# vim 环境搭建

* 参考链接
[如何在 Linux 下利用 Vim 搭建 C/C++ 开发环境?](https://www.zhihu.com/question/47691414)
[Vim的终极配置方案](https://blog.csdn.net/amoscykl/article/details/80616688?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-4.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-4.channel_param)


* 插件管理: vim-plug, 管理大量插件更简便(操作：PlugInstall , PlugUpgrade)
* 符号索引: ctags, gtags, etags, cquery ...
* 自动索引: vim-gutentags
* 编译运行: AsyncRun
* 动态检查: ALE
* 修改比较: vim-signify
* 代码补全


* vim-plug 安装
> curl -fLo ~/.vim/autoload/plug.vim --create-dirs  https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

* 配置需要安装的插件 ~/.vimrc
> $ mkdir ~/.vim/plugged
> $ vim ~/.vimrc
```
    call plug#begin('~/.vim/plugged')
    Plug 'beanworks/vim-phpfmt' #添加要安装的插件
    call plug#end()
```
* 安装插件
```
    vim
    :PlugInstall
```

### VIM 命令
* hjkl
* 2w 向前移动两个单词
* 3e 向前移动到第 3 个单词的末尾
* 0 移动到行首
* $ 当前行的末尾
* gg 文件第一行     
* G 文件最后一行
* 行号+G 指定行
* <ctrl>+o 跳转回之前的位置
* <ctrl>+i 返回跳转之前的位置

#### 删除
* x 删除当前字符
* dw 删除至当前单词末尾
* de 删除至当前单词末尾，包括当前字符
* d$ 删除至当前行尾
* dd 删除整行
* 2dd 删除两行

#### 修改
* i 插入文本
* A 当前行末尾添加
* r 替换当前字符
* o 打开新的一行并进入插入模式

#### 查找
* <ctrl>+g 显示当前行以及文件信息
* / 正向查找（n：继续查找，N：相反方向继续查找）
* ？ 逆向查找
* % 查找配对的 {，[，(
* :set ic 忽略大小写
* :set noic 取消忽略大小写
* :set hls 匹配项高亮显示
* :set is 显示部分匹配

#### 替换
* :s/old/new 替换该行第一个匹配串
* :s/old/new/g 替换全行的匹配串
* :%s/old/new/g 替换整个文件的匹配串
#### 折叠与展开
* zc 折叠
* zC 折叠所有嵌套
* zo 展开折叠
* zO 展开所有折叠嵌套
