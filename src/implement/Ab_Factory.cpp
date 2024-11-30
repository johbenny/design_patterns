#include <iostream>
#include <string>
using namespace std;

class AbstractProductA {  // 头部类
 public:
  virtual ~AbstractProductA(){};
  virtual std::string UsefulFunctionA() const = 0;
};


class ConcreteProductA1 : public AbstractProductA {
 public:
  std::string UsefulFunctionA() const override {
    return "我来组成hero头部";
  }
};

class ConcreteProductA2 : public AbstractProductA {
  std::string UsefulFunctionA() const override {
    return "我来组成devil头部";
  }
};


class AbstractProductB {  // 尾部类
 public:
  virtual ~AbstractProductB(){};
  virtual std::string UsefulFunctionB() const = 0;
  virtual std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const = 0;
};


class ConcreteProductB1 : public AbstractProductB {
 public:
  std::string UsefulFunctionB() const override {
    return "我来组成hero尾部";
  }

  std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override {
    cout<< collaborator.UsefulFunctionA()<<endl;
    cout<<this->UsefulFunctionB()<<endl;
    return "hero 合体成功";
  }
};

class ConcreteProductB2 : public AbstractProductB {
 public:
  std::string UsefulFunctionB() const override {
    return "我来组成devil尾部";
  }
 
  std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override {
    cout<< collaborator.UsefulFunctionA()<<endl;
    cout<<this->UsefulFunctionB()<<endl;
    return "devil 合体成功";
  }
};


class AbstractFactory {
 public:
  virtual AbstractProductA *CreateProductA() const = 0;
  virtual AbstractProductB *CreateProductB() const = 0;
};


class ConcreteFactory1 : public AbstractFactory {  // 一系列产品( hero )
 public:
  AbstractProductA *CreateProductA() const override { // 产品类一
    return new ConcreteProductA1();
  }
  AbstractProductB *CreateProductB() const override { // 产品类二
    return new ConcreteProductB1();
  }
};


class ConcreteFactory2 : public AbstractFactory { // 一系列产品 （devil）
 public: 
  AbstractProductA *CreateProductA() const override { // 产品类一
    return new ConcreteProductA2();
  }
  AbstractProductB *CreateProductB() const override { // 产品类二
    return new ConcreteProductB2();
  }
};


void ClientCode(const AbstractFactory &factory) { // 用户代码不知到是谁在合体
  const AbstractProductA *product_a = factory.CreateProductA();
  const AbstractProductB *product_b = factory.CreateProductB();
  std::cout << product_b->AnotherUsefulFunctionB(*product_a) << "\n";
  delete product_a;
  delete product_b;
}

int main() {
 
  ConcreteFactory1 *f1 = new ConcreteFactory1();
  ClientCode(*f1); 
  delete f1;
  std::cout << std::endl;

  ConcreteFactory2 *f2 = new ConcreteFactory2();
  ClientCode(*f2);
  delete f2;
  return 0;
}
