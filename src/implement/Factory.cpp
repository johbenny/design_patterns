#include <iostream>
#include <string>


class Product {
 public:
  virtual ~Product() {}
  virtual std::string Operation() const = 0;
};


class ConcreteProduct1 : public Product {
 public:
  std::string Operation() const override {
    return "{Result of the ConcreteProduct1}";
  }
};
class ConcreteProduct2 : public Product {
 public:
  std::string Operation() const override {
    return "{Result of the ConcreteProduct2}";
  }
};



class Creator { 

 public:
  virtual ~Creator(){};
  virtual Product* FactoryMethod() const = 0;

  std::string SomeOperation() const {
    Product* product = this->FactoryMethod();
    std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
    delete product;
    return result;
  }
};


class ConcreteCreator1 : public Creator { // 具体工厂
 public:
  Product* FactoryMethod() const override {
    return new ConcreteProduct1(); // 生成具体对象
  }
};

class ConcreteCreator2 : public Creator { // 具体工厂
 public:
  Product* FactoryMethod() const override {
    return new ConcreteProduct2(); // 生成具体对象
  }
};

void ClientCode(const Creator& creator) { // 外部实现不知道具体工厂子类
  // ...
  std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
            << creator.SomeOperation() << std::endl;
  // ...
}



int main() {

  Creator* creator = new ConcreteCreator1();
  ClientCode(*creator);
  std::cout << std::endl;


  Creator* creator2 = new ConcreteCreator2();
  ClientCode(*creator2);


  Product* p=creator2->FactoryMethod(); // 外部实现不知到具体的多态对象是什么子类型

  delete creator;
  delete creator2;
}