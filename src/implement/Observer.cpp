#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Subscriber
{
public:
    void update(bool v)
    {
        context_ = v;
        if (context_)
            doSomething();
    }

protected:
    void doSomething() { cout << "context_ is ready" << endl; }

private:
    bool context_{false};
};

class Publisher
{
public:
    Publisher() = default;
    void subscribe(Subscriber *ptr)
    {
        subscribers.push_back(ptr);
    }

    void unsubscribe(Subscriber *ptr)
    {
        auto it = find(subscribers.begin(), subscribers.end(), ptr);
        if (it != subscribers.end())
            subscribers.erase(it);
    }

    void changeState(bool v)
    {
        context = v;
        notifySubscribers();
    }

private:
    void notifySubscribers()
    {
        for (auto ptr : subscribers)
            ptr->update(context);
    }

private:
    vector<Subscriber *> subscribers;
    bool context{false};
};

class SubSubscriber : public Subscriber
{
};

int main()
{
    Publisher publisher;
    Subscriber *sub1 = new SubSubscriber;
    Subscriber *sub2 = new SubSubscriber;
    publisher.subscribe(sub1);
    publisher.subscribe(sub2);
    publisher.changeState(true);
    publisher.changeState(false);
}