## Factory （工厂）模式

根据不同需求（不同工厂）生成不同的具体对象（多态对象），消除直接用 `new` 生成某一具体的多态对象；消除对具体类的依赖

[implement](./implement/Factory.cpp)


![](./images/Factory.png)

具体工厂生成具体类，具体工厂类必须重写接口的生成方法

Creator 和 Product 接口稳定，外部仅依赖该接口，初始化延迟到 Creator 接口内（没有直接 new ）。