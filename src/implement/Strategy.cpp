#include <iostream>

using namespace std;

// 稳定
class Strategy
{
public:
    virtual void practice() = 0;
};

class Context
{
private:
    Strategy *strategy = nullptr;

public:
    void setStrategy(Strategy *ptr)
    {
        if (strategy)
            delete strategy;
        strategy = ptr;
    }
    void doSomething()
    {
        if (!strategy)
            return;
        strategy->practice();
    }
    ~Context()
    {
        if (strategy)
            delete strategy;
    }
};

// 不稳定
class Strategy1 : public Strategy
{
public:
    void practice() override
    {
        cout << "do strategy 1" << endl;
    }
};
class Strategy2 : public Strategy
{
public:
    void practice() override
    {
        cout << "do strategy 2" << endl;
    }
};

int main()
{
    Context context;
    context.setStrategy(new Strategy1()); // 用户传入策略
    context.doSomething();
    context.setStrategy(new Strategy2());// 替换新策略
    context.doSomething();
}