#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "Node.h"

template <typename T>
class LinkedStack
{
private:
    Node<T> *top;
    int num_elements;

public:
    LinkedStack(): top{nullptr}, num_elements{0}
    {
    }

    void push(T new_element)
    {
        Node<T> *new_node{new Node<T>{new_element}};
        new_node->next = top;
        top = new_node;
        ++num_elements;
    }

};

#endif
