## State (状态) 模式

上下文环境中，根据当前状态执行特定工作

上下文对象`组合`状态对象，具体任务由状态对象执行，状态对象引用可切换（类似 Strategy 模式）

[implement](./implement/State.cpp)

![](./images/State.png)

替换 if-else , switch-case 的静态结构，改为依赖于可替换的状态接口。

