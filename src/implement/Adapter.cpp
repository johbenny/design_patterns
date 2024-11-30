#include <iostream>
#include <string>
#include <algorithm>

class Target
{
public:
    virtual ~Target() = default;

    virtual std::string Request() const
    {
        return "Target: The default target's behavior.";
    }
};


class Adaptee
{
public:
    std::string SpecificRequest() const
    {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};


class Adapter : public Target // 新接口
{
private:
    Adaptee *adaptee_; // 旧接口

public:
    Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
    std::string Request() const override
    {
        std::string to_reverse = this->adaptee_->SpecificRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (TRANSLATED) " + to_reverse;
    }
};


void ClientCode(const Target *target)
{
    std::cout << target->Request();
}

int main()
{
  
    Target *target = new Target;
    ClientCode(target);
    std::cout << "\n\n";
    Adaptee *adaptee = new Adaptee; // 旧接口

    std::cout << "Adaptee: " << adaptee->SpecificRequest(); // 旧接口动作
    std::cout << "\n\n";

    Adapter *adapter = new Adapter(adaptee); // 适配新接口 
    ClientCode(adapter);
    std::cout << "\n";

    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}