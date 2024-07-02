#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <iostream>

template <typename T>
class Node
{
private:
    T value;
    std::vector<Node<T> *> childrens; 

public:
    Node(T val) : value(val) {}

    void update_childrens(){
       childrens.clear();
    }

    void add_child(Node<T> *child){
        childrens.push_back(child);
    }
    int number_of_childrens() const{
        return childrens.size();
    }
    T get_value() const{
        return value;
    }
    const std::vector<Node<T> *> &get_childrens(){
        return childrens;
    }
    
    ~Node() {}
    
};

#endif // NODE_HPP
