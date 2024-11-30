## Composite (组合) 模式


以树状结构实现全部调用，调用一个根对象，递归完成整个树的调用 (多态递归调用)

Component: 根，分支，叶子

Composite 代表一个分支，其上有子分支或节点 

[implement](./implement/Composite.cpp)
![](./images/Composite.png)

- 分支：遍历调用子节点的 execute()
- 叶子：在 execute() 中完成实际功能


