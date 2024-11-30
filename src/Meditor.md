## Mediator (中介者) 模式

停止组件之间的直接交流，改为必须调用特殊的中介者对象， 通过中介者对象`重定向调用行为`，以间接的方式进行合作。

合作组件仅依赖于一个中介者类， 无需与多个其他组件相耦合。

[implement](./implement/Mediator.cpp)

![](./images/Mediator.png)

功能组件聚合一个相同的中介者，Mediator 内部可能很复杂
