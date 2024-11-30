
#include <string>
#include <iostream>
using namespace std;

class Component
{
public:
    virtual ~Component() {}
    virtual string Operation() const = 0;
};

class ConcreteComponent : public Component
{
public:
    string Operation() const override
    {
        return "ConcreteComponent";
    }
};

class Decorator : public Component
{
    
protected:
    Component *component_;

public:
    Decorator(Component *component) : component_(component)
    {
    }
    std::string Operation() const override
    {
        return this->component_->Operation(); // 包装原有功能，不改变接口
    }
};

class ConcreteDecoratorA : public Decorator
{
  
public:
    ConcreteDecoratorA(Component *component) : Decorator(component) // 包装原有功能
    {
    }
    std::string Operation() const override
    {
        return "ConcreteDecoratorA(" + Decorator::Operation() + ")"; // 拓展原有功能，，不改变接口
    }
};

class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB(Component *component) : Decorator(component) // 包装原有功能
    {
    }

    std::string Operation() const override
    {
        return "ConcreteDecoratorB(" + Decorator::Operation() + ")"; // 拓展原有功能，不改变接口
    }
};

void ClientCode(Component *component)
{
    cout << "RESULT: " << component->Operation()<<endl;;
}

int main()
{

    Component *simple = new ConcreteComponent; // 原有功能
    ClientCode(simple);


    Component *decorator1 = new ConcreteDecoratorA(simple); // 拓展功能内容
    ClientCode(decorator1);

    Component *decorator2 = new ConcreteDecoratorB(decorator1); // 再次拓展功能内容
    ClientCode(decorator2);
 

    delete simple;
    delete decorator1;
    delete decorator2;

    return 0;
}
/**
 *  RESULT: ConcreteComponent
    RESULT: ConcreteDecoratorA(ConcreteComponent)
    RESULT: ConcreteDecoratorB(ConcreteDecoratorA(ConcreteComponent))
 */