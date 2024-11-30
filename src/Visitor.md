## Visitor (访问者) 模式

现有对象拓展功能，而不改变原有类代码：接收一个访问者对象，新增功能由访问者实现

[implement](./implement/Visitor.cpp)

![](./images/Visitor.png)

现有对象 accept 访问者，并由访问者使用该对象（this_ptr）

前提：Visitor 抽象接口要预知所有具体多态类型

