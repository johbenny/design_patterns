#include <iostream>
using namespace std;

class Abstract
{
public:
    void work_flow() // template 稳定
    {
        cout<<"工作流程开始:"<<endl;
        method_1();
        method_2();
        method_3();
        cout<<"工作流程结束;"<<endl;
    }
   virtual ~Abstract()=default;
protected:
    // 非稳定
    virtual void method_1() = 0;

    virtual void method_2() = 0;

    virtual void method_3() = 0;
 
};

class Concret : public Abstract
{
protected:
    void method_1() override { cout << "特殊流程 1" << endl; }
    void method_2() override { cout << "特殊流程 2" << endl; }
    void method_3() override { cout << "特殊流程 3" << endl; }
};

int main()
{
    Abstract *a = new Concret();
    a->work_flow();
    delete a;
    return 0;
}