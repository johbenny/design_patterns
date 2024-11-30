## ChainOfResponsibility (责任链) 模式

将处理任务的对象链接成一个队列，将任务传递给头节点，并在队列上依次传递下去，直到任务处理成功或到队尾仍无法处理

[implement](./implement/ChainOfResponsibility.cpp)

![](./images/ChainOfResponsibility.png)

- ConcreteHandler::handle: 检查并处理任务，无法处理则调用 BaseHandler::handle 传递任务
- BaseHandler::handle: 负责将任务传递给下一个工作节点