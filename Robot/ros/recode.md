扫地机器人
AGV


### history


### ROS实现该领域代码重用的问题
1. jfisnag
    * fjaing

### 学习资料
[古月-ROS入门21讲](https://www.bilibili.com/video/BV1zt411G7Vn?from=search&seid=15890733324810987456)
《ROS机器人开发实践》
技术基础：C++，Python,Linux


## ROS 安装
> [Arch Linux ROS](http://wiki.ros.org/noetic/Installation/ArchLinux)
0. package安装
    * yay -S ros-package 

1. 初始化 rosdep
    ```
    [psj@Arch ~]$ sudo rosdep init
    [psj@Arch ~]$ rosdep update
    [psj@Arch ~]$ echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc
    [psj@Arch ~]$ source ~/.bashrc
    ```
    > <font color="Red">rosdep 是什么？</font>


> [ROS Tutorials](http://wiki.ros.org/ROS/Tutorials)
2. create a ROS Workspace
    ```bash
    [psj@Arch ~]$ mkdir -p ~/catkin_ws/src
    [psj@Arch ~]$ cd ~/catkin_ws/
    [psj@Arch ~]$ catkin_make
    [psj@Arch ~]$ source devel/setup.bash
    [psj@Arch ~]$ echo $ROS_PACKAGE_PATH
    /home/youruser/catkin_ws/src:/opt/ros/kinetic/share 
    ```
3. Navigation the file system
    <table><tbody>
    <th> build system for ROS </th>
    <tr><td> rosbuild </td> <td>old </td></tr>
    <tr><td> catkin </td><td>new</td></tr>
    </tbody></table>
    
    ```bash
    [psj@Arch ~]$ yay -S ros-noetic-ros-tutorials ##检查相关package
    [psj@Arch ~]$ rospack find roscpp_serialization ##查询包信息，返回安装路径
    ```

4. 启动小乌龟
    * 准备工作，安装好 tutorials , rosbash 
    * 启动三个终端，分别执行如下命令
        ```shell
        [psj@Arch ~]$ roscore #打开ROS服务
        [psj@Arch ~]$ rosrun turtlesim turtlesim_node #打开小乌龟
        [psj@Arch ~]$ rosrun turtlesim turtle_teleop_key ##通过键盘操作小乌龟
        ```

5. 节点 rosnode
    ```sh
    [psj@Arch ~]$ rosnode
    /rosout
    /rqt_gui_py_node_820733
    /teleop_turtle
    /turtlesim
    ```
6. 话题 rostopic
    ```sh
    [psj@Arch ~]$ rostopic list #查看话题列表
    /rosout
    /rosout_agg
    /turtle1/cmd_vel
    /turtle1/color_sensor
    /turtle1/pose
    ```
    ```sh
    [psj@Arch ~]$ rostopic info /turtle1/cmd_vel
    Type: geometry_msgs/Twist

    Publishers: 
    * /teleop_turtle (http://Arch:39377/)

    Subscribers: 
    * /turtlesim (http://Arch:44215/)
    ```
    ```sh
    [psj@Arch ~]$ rostopic echo /turtle1/cmd_vel  # 实时查看topic通信信息
    linear: 
    x: 0.0
    y: 0.0
    z: 0.0
    angular: 
    x: 0.0
    y: 0.0
    z: -2.0
    ```
    ```sh
    [psj@Arch ~]$ rostopic type /turtle1/cmd_vel    #查看 topic 数据类型 
    geometry_msgs/Twist
    [psj@Arch ~]$ rosmsg show geometry_msgs/Twist
    geometry_msgs/Vector3 linear
    float64 x
    float64 y
    float64 z
    geometry_msgs/Vector3 angular
    float64 x
    float64 y
    float64 z
    ```
    ```sh
    [psj@Arch ~]$ rostopic pub /turtle1/cmd_vel geometry_msgs/Twist -r 1 -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, -1.8]'  ##发送msg控制小乌龟， -r 持续发送，1 发送频率
    ```

7. 服务 Service
    ```sh
    [psj@Arch ~]$ rosservice list   #查看服务
    /clear
    /kill
    /reset
    /rosout/get_loggers
    /rosout/set_logger_level
    /spawn
    /teleop_turtle/get_loggers
    /teleop_turtle/set_logger_level
    /turtle1/set_pen
    /turtle1/teleport_absolute
    /turtle1/teleport_relative
    /turtlesim/get_loggers
    /turtlesim/set_logger_level
    [psj@Arch ~]$ rosservice call clear #可以清楚缓存（小乌龟已生成的路径图）
    ```
8. 其余cmd
    * rqt_graph 图形化
        ```shell
        [psj@Arch ~]$ rosrun rqt_graph rqt_graph  ##启动UI界面查看 ROS信息，包括 node，topic
        ```
    > <font color="Red"> rosrun rqt_plot rqt_plot </font>
    


