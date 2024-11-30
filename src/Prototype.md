## Prototype (原型) 模式

复制已有对象，无需知道其具体类型（自己复制自己，返回自身拷贝）

- 外部直接调用拷贝构造需要知道具体类型
- 外部遍历属性拷贝无法访问私有数据

[implement](./implement/Prototype.cpp)



![](./images/Prototype.png)

实现返回多态引用的 `clone()` 接口函数，常与工厂方法搭配使用