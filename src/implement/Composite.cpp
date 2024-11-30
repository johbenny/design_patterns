#include <algorithm>
#include <iostream>
#include <list>
#include <string>

class Component { // 节点接口 ： 分支（分叉，根），叶子节点
  
 protected:
  Component *parent_;

 public:
  virtual ~Component() {}
  void SetParent(Component *parent) {
    this->parent_ = parent;
  }
  Component *GetParent() const {
    return this->parent_;
  }
 
  virtual void Add(Component *component) {}
  virtual void Remove(Component *component) {}
 
  virtual bool IsComposite() const {
    return false;
  }

  virtual std::string Operation() const = 0;
};

class Leaf : public Component { // 叶子节点
 public:
  std::string Operation() const override {
    return "Leaf";
  }
};

class Composite : public Component { // 分支节点

 protected:
  std::list<Component *> children_;

 public:
  
  void Add(Component *component) override {
    this->children_.push_back(component);
    component->SetParent(this);
  }
  
  void Remove(Component *component) override {
    children_.remove(component);
    component->SetParent(nullptr);
  }
  bool IsComposite() const override {
    return true;
  }
  
  std::string Operation() const override { // 调用子节点和子分支完成任务
    std::string result;
    for (const Component *c : children_) {
      if (c == children_.back()) {
        result += c->Operation();
      } else {
        result += c->Operation() + "+";
      }
    }
    return "Branch(" + result + ")";
  }
};

void ClientCode(Component *component) {
  // ...
  std::cout << "RESULT: " << component->Operation();
  // ...
}


void ClientCode2(Component *component1, Component *component2) {
  // ...
  if (component1->IsComposite()) {
    component1->Add(component2);
  }
  std::cout << "RESULT: " << component1->Operation();
  // ...
}



int main() {
  Component *simple = new Leaf; // 一次叶子节点调用
  ClientCode(simple);
  std::cout << "\n\n";


  Component *tree = new Composite; // 根

  Component *branch1 = new Composite; // 分支1
  Component *leaf_1 = new Leaf;
  Component *leaf_2 = new Leaf;
  branch1->Add(leaf_1);
  branch1->Add(leaf_2);

  Component *branch2 = new Composite; // 分支2
  Component *leaf_3 = new Leaf;
  branch2->Add(leaf_3);


  tree->Add(branch1); // 链接分支，根下有两个分支
  tree->Add(branch2);


  ClientCode(tree); // 调用根，所有节点都被递归调用
  std::cout << "\n\n";

  std::cout << "Client: I don't need to check the components classes even when managing the tree:\n";
  ClientCode2(tree, simple);
  std::cout << "\n";

  delete simple;
  delete tree;
  delete branch1;
  delete branch2;
  delete leaf_1;
  delete leaf_2;
  delete leaf_3;

  return 0;
}