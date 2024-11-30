#include <string>
#include <iostream>

class Implementation
{ // 工作类接口
public:
    virtual ~Implementation() {}
    virtual std::string OperationImplementation() const = 0; // 具体工作
};

class ConcreteImplementationA : public Implementation
{ // 具体工作类
public:
    std::string OperationImplementation() const override
    {
        return "ConcreteImplementationA: Here's the result on the Implement A.\n";
    }
};
class ConcreteImplementationB : public Implementation
{ // 具体工作类
public:
    std::string OperationImplementation() const override
    {
        return "ConcreteImplementationB: Here's the result on the implement B.\n";
    }
};

class Abstraction
{

protected:
    Implementation *implementation_;

public:
    Abstraction(Implementation *implementation) : implementation_(implementation)
    {
    }

    virtual ~Abstraction()
    {
    }

    virtual std::string Operation() const
    { // 抽象任务，其内部实质工作由组合的具体工作类完成
        return "Abstraction: Base operation with:\n" +
               this->implementation_->OperationImplementation();
    }
};

class ExtendedAbstraction : public Abstraction
{
public:
    ExtendedAbstraction(Implementation *implementation_1, Implementation *implementation_2) // 拓展功能
        : Abstraction(implementation_1), _implementation_(implementation_2)
    {
    }
    std::string Operation() const override
    {
        return "ExtendedAbstraction: Extended operation with:\n" +
               this->implementation_->OperationImplementation() + " and " + this->_implementation_->OperationImplementation();
    }

private:
    Implementation *_implementation_;
};

void ClientCode(const Abstraction &abstraction)
{
    // ...
    std::cout << abstraction.Operation();
    // ...
}

int main()
{
    Implementation *implementation_1 = new ConcreteImplementationA;
    Abstraction *abstraction = new Abstraction(implementation_1);
    ClientCode(*abstraction);
    std::cout << std::endl;
    delete abstraction;

    Implementation *implementation_2 = new ConcreteImplementationB;
    abstraction = new ExtendedAbstraction(implementation_1, implementation_2);
    ClientCode(*abstraction);

    delete implementation_1;
    delete implementation_2;
    delete abstraction;

    return 0;
}