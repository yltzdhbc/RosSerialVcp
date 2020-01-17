# RosSerialVcp
## 前情提要

工程文件在我的GITHUB上 链接
[https://github.com/yltzdhbc/RosSerialVcp](https://github.com/yltzdhbc/RosSerialVcp)

最近在做ros，stm32是一个性能强悍的微控制器，适合做底层数据的运算，ROS和stm32通信就是连接这两者的桥梁，花了很多时间去了解这方面的内容，写一篇总结

## stm32 rosserial

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200117142347114.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3l1bGVpdGFv,size_16,color_FFFFFF,t_70)

- rosserial 是ros官方的一个功能包 [http://wiki.ros.org/rosserial/](http://wiki.ros.org/rosserial/)
- rosserial相当于让stm32可以直接在ros网络中发布话题,接入ros,节点的写法和在linux下相同,使用起来也是非常方便

## USB转TTL

- 在网上,很多资料都是使用stm32 usart 和usb 转 ttl 来连接的 ,这样因为大部分stm32的定时器是16位,65秒左右会溢出,导致时钟与ros同步不上,会出现 error,虽然不影响实际的通信效果 , 但是看着也很烦人

## USB VCP 虚拟串口

- 关于stm32虚拟串口的使用可以看我另一篇博文[https://blog.csdn.net/yuleitao/article/details/103285137](https://blog.csdn.net/yuleitao/article/details/103285137)
- stm32带有usb接口,开启虚拟串口之后,ubuntu下可以直接识别
- 测试中发现VCP和rROS的通信比较稳定,使用USB转TTL,使用1HZ发送消息频率一直达不到1HZ,在0.8~0.98之间飘

## CUBEMX的配置

1. RCC
   ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200117140311974.png)
2. SYS
   ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200117140335282.png)
3. USB![在这里插入图片描述](https://img-blog.csdnimg.cn/20200117140347325.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3l1bGVpdGFv,size_16,color_FFFFFF,t_70)
4. USB_DEVICE
   ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200117140435928.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3l1bGVpdGFv,size_16,color_FFFFFF,t_70)
5. 时钟树
   ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200117140501596.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3l1bGVpdGFv,size_16,color_FFFFFF,t_70)
6. ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200117140602542.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3l1bGVpdGFv,size_16,color_FFFFFF,t_70)
7. ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200117140621802.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3l1bGVpdGFv,size_16,color_FFFFFF,t_70)

## 工程文件的配置

1. 复制ROSlib库到工程文件目录下面
   ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200117140649804.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3l1bGVpdGFv,size_16,color_FFFFFF,t_70)
2. 添加如下四个文件到工程里，并在keil中导入
   ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200117140743868.png)

## KEIL的配置

1. 添加 ,__USE_C99_MATH 到define

```
,__USE_C99_MATH
```

2. 添加,  --diag_suppress=1,47,1300 , 到misc controls

```
--diag_suppress=1,47,1300
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200117140727588.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3l1bGVpdGFv,size_16,color_FFFFFF,t_70)

3. 添加rosmain.h，使用cubemx的话，要添加到BEGAIN 和END之间，这样重新生成代码的时候就不会把我们自己添加的代码覆盖掉了
   ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200117140718412.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3l1bGVpdGFv,size_16,color_FFFFFF,t_70)
4. 添加如下函数到指定位置

```
setup();
loop();
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200117140705193.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3l1bGVpdGFv,size_16,color_FFFFFF,t_70)

5. 下载到stm32
6. 主要的函数在ros_main.cpp里面，这里延续的arduino的写法，setup里面就是初始化节点，发布一个叫做chatter的话题 ，在loop里面循环调用了publish以1HZ的频率在ros中发布“HELLO WORLD”消息

```
void setup(void)
{
   nh.initNode();
   nh.advertise(chatter);
}
void loop(void)
{
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_12);
	str_msg.data = hello;
 	chatter.publish(&str_msg);
 	nh.spinOnce();
	HAL_Delay(1000);
}
```

7. 工程文件在我的GITHUB上 链接
   [https://github.com/yltzdhbc/RosSerialVcp](https://github.com/yltzdhbc/RosSerialVcp)

## 在Linux上测试接收stm32发过来的消息

使用 ttl 转 usb 一般检测到的是ttyUSB0 , 直接使用USB虚拟串口(VCP)一般检测到的是ttyACM0

  1. 查看USB设备

```cpp
lsusb
dmesg | grep tty
```

2. 提高串口权限

```cpp
sudo chmod 777 /dev/ttyACM0
```

4. linux上要先安装rosserial库，如果有就忽略这一步

```cpp
sudo apt-get install ros-kinetic-serial
```

5. 启动roscore

```cpp
roscore
```

6. 启动rosserial 指定端口 /dev/ttyACM0 这里端口可能不一样

```cpp
rosrun rosserial_python serial_node.py _port:=/dev/ttyACM0 _baud:=115200
```

7. 输入 rostopic echo /chatter 查看topic 内容

```cpp
rostopic echo /chatter
```

8. 输入rqt_graph可以查看节点状态图

```cpp
rqt_graph
```

9. 输入rqt打开topic monitor 可以查看消息的内容和频率

```cpp
rqt
```



