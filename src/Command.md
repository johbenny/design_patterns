## Command (命令) 模式

将一个任务请求抽象为一个对象，任务对象可传递、缓存，实现延迟调用和任务传递 

c++：静态函数对象，function，package_task 都是编译时绑定；多态函数对象、命令模式是运行时绑定

[implement](./implement/Command.cpp)

![](./images/Command.png)

将 行为请求者 和 行为实现者 解耦