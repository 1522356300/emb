# 《Operating Systems:Three Easy Pieces》

* 虚拟化
* 并行
* 持久性

## CPU虚拟化

## 内存虚拟化

### 物理内存抽象：地址空间

透明、效率、保护
用户态可以看到的任何地址都是虚拟地址，只有操作系统(内核)和硬件才知道物理地址

### 内存分析工具

#### purify

#### valgrind

* 限定：Linux环境，GPL V2
* 架构：core + tools (或者称：framework + plug-in)
core 模拟CPU的环境，为其他工具提供服务
tools 利用core提供的服务完成各种特定的内存调试任务

##### tools

* Memcheck
* Callgrind ：推荐代码编译是添加调试选项。其收集程序运行时的一些数据建立函数的调用关系图，运行结束是，将分析数据写入文件，可利用callgrind_annotate转化为可读形式
* Cachegrind : Cache分析器，模拟CPU中的一级缓存、二级缓存，能够精准的指出程序中cache的丢失与命中，甚至可以提供内存引用次数，以及每行代码，每个函数，每个模块，甚至整个程序产生的指令数，这对优化程序有很大的帮助。
* Helgrind : 主要用于检查多线程程序中出现的竞争问题
* Massif : 堆栈分析器